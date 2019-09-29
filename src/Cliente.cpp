#include <iostream>
#include <string>
#include <fstream>
#include "Cliente.hpp"
#include <vector>

using namespace std;

cliente::cliente()
{
    // cout << "cliente construido"<<endl;
}

cliente::~cliente()
{
    // cout << "cliente destruido"<<endl;
}

void cliente::isSocio()
{

    string x, z;
    cout << "O cliente eh socio?[s/n]" << endl;
    do
    {
        cin >> x;
        z = "a";
        if (cin.fail() || (x != "s" && x != "n"))
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Entrada invalida. Digite novamente:" << endl;
            z = "b";
        }
    } while (z != "a");
    this->socio = x;
}
void cliente ::isSocio(string x)
{
    this->socio = x;
}

void cliente ::showSocio()
{
    if (this->socio == "s")
    {
        cout << "Cliente eh socio" << endl;
    }
    else
    {
        cout << "Cliente nao eh socio" << endl;
    }
}
string cliente::getSocio()
{
    return this->socio;
}

void cliente ::saveclient(cliente *p)
{
    fstream arq;
    arq.open("./data/Clientes.txt", ios::out | ios::app);
    arq << p->getnome() << endl;
    arq << p->getidade() << endl;
    arq << p->getcpf() << endl;
    arq << p->socio << endl;
    arq.close();
}

cliente cliente ::find()
{
    string x, inf, aux = "0";
    int i = 0, pos = 0, y, checker = 0;
    fstream arquivo;
    vector<string> v;
    cliente temp;
    do
    {
        cout << "Digite o cpf do cliente:" << endl;
        cout << "Se o cliente nao possuir cadastro, digite um asterisco ( "
                "*"
                " ):"
             << endl;
        do
        {
            y = 0;
            getline(cin, x);
            for (int c = 0; c < (int)x.size(); c++)
            {
                if (x == "*")
                {
                    temp.setnome(aux);
                    temp.setidade(aux);
                    temp.setcpf(aux);
                    temp.isSocio(aux);
                    return temp;
                }
                if (!isdigit(x[c]) || isspace(x[c]) || x.size() != 11)
                {
                    y = 1;
                }
            }
            if (y == 1)
            {
                cout << "Cpf invalido. Digite novamente: " << endl;
            }

        } while (y != 0);

        arquivo.open("./data/Clientes.txt", ios::in);
        i = 0;
        y = 0;
        while (getline(arquivo, inf))
        {
            v.push_back(inf);
            if (v[i] == x)
            {
                cout << "\nCliente encontrado !!" << endl;
                pos = i - 2;
                y = 1;
            }
            i++;
        }
        arquivo.close();
        if (y == 1)
        {
            temp.setnome(v[pos]);
            temp.setidade(v[pos + 1]);
            temp.setcpf(v[pos + 2]);
            temp.isSocio(v[pos + 3]);
            return temp;
        }
        else
        {
            cout << "Cliente nao encontrado." << endl;
            checker = 1;
        }
    } while (checker != 0);
    return temp; // nunca chega nesse, mas da warning
}
