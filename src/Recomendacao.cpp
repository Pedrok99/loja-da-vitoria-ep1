#include <iostream>
#include <string>
#include "Recomendacao.hpp"
#include <fstream>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

recomendacao::recomendacao() {}
recomendacao::~recomendacao() {}

vector<string> recomendacao ::separacategoria(vector<string> v)
{
    int pos = 0;
    string lim = ", ";
    vector<string> separar;

    for (int i = 0; i < (int)v.size(); i++)
    {
        while (v[i].find(", ") != std::string::npos)
        {
            pos = v[i].find(", ");
            separar.push_back(v[i].substr(0, pos));
            v[i].erase(0, pos + lim.length());
        }
        separar.push_back(v[i]);
    }
    return separar;
}

void recomendacao ::historico(vector<string> categorias, string cpf)
{

    fstream arq;
    vector<string> separado;

    if (categorias.size() < 1)
    {
        return;
    }

    separado = separacategoria(categorias);

    arq.open("./data/Historico.txt", ios::out | ios::trunc);

    arq << cpf << endl;

    for (int i = 0; i < (int)separado.size(); i++)
    {
        arq << separado[i] << endl;
    }
    arq.close();
}

vector<string> recomendacao::gethistorico()
{

    fstream arq;
    string temp;
    vector<string> hist;

    arq.open("./data/Historico.txt", ios::in);

    getline(arq, temp);

    while (getline(arq, temp))
    {
        hist.push_back(temp);
    }
    arq.close();

    return hist;
}

void recomendacao::salvahistorico()
{
    fstream arq;
    vector<string> v;
    string cpf, categoria;

    arq.open("./data/Historico.txt", ios::in);

    while (getline(arq, categoria))
    {
        v.push_back(categoria);
    }
    arq.close();
    arq.open("./data/" + v[0] + ".txt", ios::out | ios::app);
    for (int i = 1; i < (int)v.size(); i++)
    {
        arq << v[i] << endl;
    }
    arq.close();
}

vector<string> recomendacao ::analisahist()
{
    //pegar um cpf e ordenar em um vetor quais os produtos + comprados

    int y, cont = 0;
    string cpf, aux, tempC, tempN;
    fstream arq;
    vector<string> categorias, ordenado, aux1, error;
    error.push_back("*");

    cout << "Digite o cpf do cliente :" << endl;
    cin.ignore(10000, '\n');
    do
    {
        y = 0;
        getline(cin, cpf);
        for (int i = 0; i < (int)cpf.size(); i++)
        {
            if (!isdigit(cpf[i]) || isspace(cpf[i]) || cpf.size() != 11)
            {
                y = 1;
            }
        }
        if (y == 1)
        {
            cout << "Cpf invalido. Digite novamente:" << endl;
        }
    } while (y == 1);

    arq.open("./data/" + cpf + ".txt", ios::in);
    if (arq.fail())
    {
        cout << "Cpf invalido ou o cliente ainda nao efetuou nenhuma compra..." << endl;
        cout << "Retornando ao menu..." << endl;
        return error;
    }
    else
    {
        cout << "\n\nVerificando historico...\n" << endl;
        while (getline(arq, aux))
        {
            categorias.push_back(aux);
        }
        arq.close();
    }

    aux1 = categorias;

    for (int i = 0; i < (int)categorias.size(); i++)
    {

        for (int j = 0; j < (int)categorias.size(); j++)
        {
            if ((categorias[i] == aux1[j]))
            {
                aux1[j] = "0";
                cont++;
            }
        }
        if (cont != 0)
        {
            ordenado.push_back(categorias[i]);
            ordenado.push_back(to_string(cont));
        }
        cont = 0;
    }

    aux1 = ordenado;
    int maior = 0, pos;

    for (int i = 0; i < (int)ordenado.size(); i += 2)
    {
        for (int j = 1; j < (int)ordenado.size(); j += 2)
        {
            if (atoi(ordenado[j].c_str()) > maior)
            {
                maior = atoi(ordenado[j].c_str());
                pos = j;
            }
        }
        aux1[i] = ordenado[pos - 1];
        aux1[i + 1] = ordenado[pos];
        maior = 0;
        ordenado[pos] = "0";
    }

    //printa o vetor em ordem
    /* for (int k = 0; k < aux1.size(); k++)
    {
        cout << aux1[k] << endl;
    }*/

    return aux1;
}
void recomendacao ::recomenda(vector<string> vet)
{
    fstream arq;
    string aux;
    vector<string> lista, temp;
    arq.open("./data/Produtos.txt", ios::in);

    while (getline(arq, aux))
    {

        if (!isdigit(aux[0]))
        {
            lista.push_back(aux);
        }
    }
    arq.close();

    // faz a recomendação
    cout << "Produtos recomendados com base em suas compras passadas:\n"
         << endl;

  /* for (int g = 0; g < 20; g += 2)
    {
        cout << "Categoria: " << vet[g] << endl;
        cout << "Frequencia de compra : " << vet[g + 1] << endl;
    } */

    for (int i = 0; i < (int)vet.size(); i = i + 2)
    {
        if (i >= 20)
        {
            return;
        }

        for (int j = 1; j < (int)lista.size(); j = j + 2)
        {

            if (lista[j].find(vet[i]) != string::npos)
            {
                temp.push_back(lista[j - 1]);
            }
        }

        std::mt19937 generator;
        int random;
        generator.seed(time(0));
        uniform_int_distribution<uint32_t> dice(0, (temp.size() - 1));
        random = dice(generator);

        if (temp.size() <= 0)
        {
            cout << "Historico do cliente apresenta um produto de categoria desconhecida" << endl;
            temp.clear();
        }
        else
        {
            cout << (i / 2) + 1 << "-" << temp[random] << endl;
            temp.clear();
        }
    }
}
