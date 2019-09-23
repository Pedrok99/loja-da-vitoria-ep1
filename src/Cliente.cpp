#include <iostream>
#include <string>
#include <fstream>
#include "Cliente.hpp"
#include <vector>

using namespace std;


cliente::cliente(){
   // cout << "cliente construido"<<endl;
}

cliente::~cliente(){
   // cout << "cliente destruido"<<endl;
}

void cliente::isSocio() {

    string x, z;
    cout << "O cliente eh socio?[s/n]"<< endl;
    do{
        cin >> x;
        z ="a";
        if(cin.fail() ||  (x != "s" && x!="n")){
            cin.clear();
            cin.ignore(32767,'\n');
            cout << "Entrada invalida. Digite novamente:"<< endl;
            z="b";
        }
    }while(z!="a");
    this -> socio = x;
}
void cliente :: isSocio(string x){
    this->socio=x;
}

void cliente :: showSocio(){
    if(this->socio == "s"){
        cout << "Cliente eh socio"<< endl;
    }else{
        cout << "Cliente nao eh socio"<<endl;
    }
}
void cliente :: saveclient(cliente *p){
    fstream arq;
    arq.open("Clientes.txt", ios::out | ios::app);
    arq << p->getnome() << endl;
    arq << p->getidade() << endl;
    arq << p->getcpf() << endl;
    arq << p->socio << endl;
    arq.close();
}



void cliente :: find(){
    string x, inf;
    int i=0, pos=0, y; 
    fstream arquivo;
    vector<string> v;
    cliente temp;
    cout << "Digite o cpf do cliente a ser encontrado:" << endl;
     do{
        y=0;
        getline(cin, x);
        for(int c=0;c<x.size();c++){
            if(!isdigit(x[c]) || isspace(x[c]) || x.size()!=11){
                y=1;
            }
        }
        if(y==1){
        cout <<"Cpf invalido. Digite novamente:"<< endl;
    }
    
    }while(y!=0);

    arquivo.open("Clientes.txt", ios::in);
    i=0;

    while (getline(arquivo, inf))
    {
        v.push_back(inf);
        if(v[i]==x){
            cout << "Cliente encontrado" << endl;
            pos=i-2;
            y=1;
        }
        i++;
    }
    if(y==1){
        cout << "A posicao do cliente é" << pos << endl;
    }else{
        cout << "cliente nao encontrado !!"<< endl;
    }
    arquivo.close();

}