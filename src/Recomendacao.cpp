#include <iostream>
#include <string>
#include "Recomendacao.hpp"
#include <fstream>
#include <vector>
using namespace std;

recomendacao::recomendacao() {}
recomendacao::~recomendacao() {}
/*
vector<string> recomendacao ::separacategoria()
{
    int pos = 0, cont = 0;
    fstream arq;
    string categoria, lim = ", ";
    vector<string> lc;
    arq.open("Produtos.txt", ios::in);

    while (getline(arq, categoria))
    {
        if (cont == 1)
        {
            while (categoria.find(", ") != string::npos)
            {
                pos = categoria.find(", ");
                lc.push_back(categoria.substr(0, pos));
                categoria.erase(0, pos + lim.length());
            }

            lc.push_back(categoria);
        }

        cont++;

        if (cont == 4)
        {
            cont = 0;
        }
    }
    arq.close();
    for (int i = 0; i < lc.size(); i++)
    {
        cout << lc[i] << endl;
    }
    return lc;
}
*/
vector<string> recomendacao ::separacategoria(vector<string> v)
{
    int pos = 0;
    string lim = ", ";
    vector<string> separar;

    for (int i=0;i<v.size();i++)
    {
        while (v[i].find(", ") != std::string::npos)
        {   pos=v[i].find(", ");
            separar.push_back(v[i].substr(0, pos));
            v[i].erase(0, pos + lim.length());
        }
        separar.push_back(v[i]);
    }
    return separar;
}

void recomendacao ::salvacategoria(vector<string> novo)
{
    fstream arq;
    vector<string> cat;
    string temp;

    arq.open("Categorias.txt", ios::in);

    while (getline(arq, temp))
    {
        cat.push_back(temp);
    }
    arq.close();

    for (int i = 0; i < cat.size(); i++)
    {
      
        for (int cont = 0; cont < novo.size(); cont++)
        {   
            
            if(cat[i]==novo[cont]){
                novo[cont]="0";
            }
           
        }
    }

    for (int i = 0; i < novo.size(); i++)
    {
        if(novo[i]!="0"){
            cat.push_back(novo[i]);
        }
        
    }
   arq.open("Categorias.txt", ios::out | ios::trunc);
    for (int i = 0; i < cat.size(); i++)
    {
        arq << cat[i] << endl;
    }
    arq.close();

}

void recomendacao ::historico(vector<string> categorias, string cpf)
{

    fstream arq;
    vector<string> separado;

    if (categorias.size() < 1)
    {
        return;
    }

    separado=separacategoria(categorias);

    arq.open("Historico.txt", ios::out | ios::trunc);

    arq << cpf << endl;

    for (int i = 0; i < separado.size(); i++)
    {
        arq << separado[i] << endl;
    }
    arq.close();
}

 vector<string> recomendacao:: gethistorico(){

    fstream arq;
    string temp;
    vector<string> hist;


    arq.open("Historico.txt", ios::in);

    getline(arq, temp); 

    while(getline(arq, temp))
    {
        hist.push_back(temp);
    }
    arq.close();

    return hist;

 }

void recomendacao :: recomenda(){
fstream arq;
string cpf;

cin>>cpf;
cpf=cpf+".txt";

arq.open(cpf, ios::out);
arq << "gay" << endl;
arq.close();
}