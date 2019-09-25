#include <iostream>
#include <string>
#include "Produto.hpp"
#include <fstream>
#include <vector>
using namespace std;

produto ::produto() {}
produto ::~produto() {}

void produto::setnome()
{
    string x, aux;
    fstream arq;
    int z;
    cout << "Digite o nome do produto:" << endl;
    do
    {
        z = 0;
        getline(cin, x);
        for (int i = 0; i < x.size(); i++)
        {
            if (isalpha(x[i]) || isspace(x[i]))
            {
            }
            else
            {
                cout << "Nome invalido!! Insira-o novamente:" << endl;
                z = 1;
                break;
            }
        }
        arq.open("Produtos.txt", ios::in);
            while (getline(arq, aux))
            {
                if (aux == x)
                {
                    cout << "Produto ja cadastrado. Digite novamente:" << endl;
                    z = 1;
                }
            }
            arq.close();

    } while (z != 0);
    this->nome = x;
}

void produto ::setcategoria()
{
    string quant, y, out = "";
    int z;
    char n;
    do
    {
        cout << "Digite a categoria do produto:" << endl;
        do
        {
            z = 0;
            getline(cin, quant);
            for (int i = 0; i < quant.size(); i++)
            {
                if (isalpha(quant[i]) || isspace(quant[i]))
                {
                }
                else
                {
                    cout << "Nome invalido!! Insira-o novamente:" << endl;
                    z = 1;
                    break;
                }
            }
        } while (z != 0);
        out = out + quant;

        cout << "O produto se encaixa em outra categoria?[s/n]" << endl;
        do
        {
            cin >> n;
            y = "a";
            if (cin.fail() || (n != 's' && n != 'n'))
            {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "Entrada invalida. Digite novamente:" << endl;
                y = "b";
            }

        } while (y != "a");
        if (n == 's')
        {
            out = out + ", ";
        }
        else
        {
            this->categoria = out;
        }

        cin.clear();
        cin.ignore(32767, '\n');

    } while (n == 's');
}

void produto ::setpreco()
{
    float quant, y = 0;
    cout << "Digite o preco do produto" << endl;
    do
    {
        y = 0;
        cin >> quant;
        if (cin.fail() || quant < 0)
        {
            y = 1;
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Entrada invalida. Digite-a novamente:" << endl;
        }

    } while (y == 1);
    this->preco = quant;
}

void produto ::setquantidade()
{
    int quant, y = 0;
    cout << "Digite a quantidade de produtos" << endl;
    do
    {
        cin >> quant;
        if (cin.fail() || quant < 0)
        {
            y = 1;
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Entrada invalida. Digite-a novamente:" << endl;
        }

    } while (y == 1);
    this->quantidade = quant;
}

string produto ::getnome()
{
    return this->nome;
}

string produto ::getcategoria()
{
    return this->categoria;
}

float produto ::getpreco()
{
    return this->preco;
}

int produto ::getquantidade()
{
    return this->quantidade;
}

void produto ::saveproduct(produto *p)
{
    fstream arq;
    arq.open("Produtos.txt", ios::out | ios::app);
    arq << p->getnome() << endl;
    arq << p->getcategoria() << endl;
    arq << p->getpreco() << endl;
    arq << p->getquantidade() << endl;
    arq.close();
}

vector<string> produto ::getlista()
{
    fstream arq;
    string quant;
    int i = 0;
    vector<string> v;
    arq.open("Produtos.txt", ios::in);
    cout << "lista de produtos:\n"
         << endl;
    while (getline(arq, quant))
    {
        cout << "Codigo#:" << i << endl;
        cout << "Produto:" << quant << endl;
        v.push_back(quant);
        getline(arq, quant);
        cout << "Categoria(s):" << quant << endl;
        v.push_back(quant);
        getline(arq, quant);
        cout << "Preco:" << quant << endl;
        v.push_back(quant);
        getline(arq, quant);
        cout << "Quantidade:" << quant << "\n"
             << endl;
        v.push_back(quant);
        i++;
    }
    return v;
}

void produto ::carrinho(vector<string> pro, string s)
{
    string quant, z;
    int y, i, p1, quantd;
    float preco, soma = 0, total;
    vector<string> backup = pro, carrinho;
    fstream arq;
    do
    {
        cout << "Digite o codigo do produto para adicionar ao carrinho:" << endl;
        do
        {
            y = 0;
            cin >> i;
            if (cin.fail() || i < 0 || (i * 4) >= (((int)pro.size())))
            {
                y = 1;
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "Codigo invalido. Digite-o novamente:" << endl;
            }
        } while (y == 1);
        p1 = i;
        cout << "Produto selecionado:" << pro[p1 * 4] << endl;
        carrinho.push_back(pro[p1 * 4]);
        // carrinho.push_back(pro[(i*4)+2]);
        cout << "Digite a quantidade desejada:" << endl;
        do
        {
            y = 0;
            cin >> i;
            if (cin.fail() || i < 0)
            {
                y = 1;
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "Entrada invalida." << endl;
            }

        } while (y == 1);
        carrinho.push_back(to_string(i));
        quantd = atoi(pro[(p1 * 4) + 3].c_str());
        preco = stof(pro[(p1 * 4) + 2].c_str());
        if (i > quantd)
        {
            cout << "Quantidade acima do estoque. Saindo do modo venda." << endl;
            return;
        }
        else
        {

            quantd = quantd - i;
            total = (stof(pro[(p1 * 4) + 2].c_str())) * i;
            pro[(p1 * 4) + 3] = to_string(quantd);
            // pro[(p1*4)+2]=to_string(preco);
            //cout << pro[(p1 * 4)] << endl;
            // cout << pro[(p1 * 4) + 1] << endl;
            soma = soma + total;

            carrinho.push_back(pro[(p1 * 4) + 2]);
            cout << "No carrinho :" << endl;
            for (int vrum = 0; vrum < carrinho.size(); vrum += 3)
            {
                cout << "Produto:" << carrinho[vrum] << endl;
                cout << "Quantidade:" << carrinho[vrum + 1] << endl;
                cout << "Preco: R$ " << carrinho[vrum + 2] << "\n"
                     << endl;
            }

            cout << "Preco total dos Produtos: R$ " << soma << endl;
            cout << "gostaria de adicionar outro produto?" << endl;

            do
            {
                cin >> quant;
                z = "a";
                if (cin.fail() || (quant != "s" && quant != "n"))
                {
                    cin.clear();
                    cin.ignore(32767, '\n');
                    cout << "Entrada invalida. Digite novamente:" << endl;
                    z = "b";
                }
            } while (z != "a");
        }
    } while (quant == "s");

    if (quant == "n")
    {
        arq.open("Produtos.txt", ios::out | ios::trunc);
        for (int cont = 0; cont < pro.size(); cont++)
        {
            arq << pro[cont] << endl;
        }
        arq.close();
    }
    if (s == "s")
    {
        cout << "\n"
             << endl;
        cout << "Desconto por ser socio (-15%):" << (soma * (15.0 / 100.0)) << endl;
        cout << "Preco final (-15% por ser socio): R$" << (soma - soma * (15.0 / 100.0)) << endl;
    }
    else
    {
        cout << "Preco final: R$ " << soma << endl;
    }
}

void produto ::attproduto(vector<string> prod, int cod)
{
    int checker, quanti;
    do
    {
        cout << "Digite a quantidade a ser adicionada" << endl;
        checker = 0;
        cin >> quanti;
        if (cin.fail() || quanti < 0)
        {
            cout << "entrada Invalida" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            checker = 1;
        }
    } while (checker == 1);

    prod[(cod * 4) + 3] = to_string(atoi(prod[(cod * 4) + 3].c_str()) + quanti);
    fstream arq;
    arq.open("Produtos.txt", ios::out | ios::trunc);
    for (int cont = 0; cont < prod.size(); cont++)
    {
        arq << prod[cont] << endl;
    }
    arq.close();

    cout << "Quantidade atualizada" << endl;
}