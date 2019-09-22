#include <iostream>
#include <string>
#include <fstream>
#include "Cliente.hpp"
#include <vector>
#include <fstream>

using namespace std;


cliente::cliente(){
    cout << "cliente construido"<<endl;
}

cliente::~cliente(){
    cout << "cliente destruido"<<endl;
}

void cliente::isSocio() {

    char x, z;
    cout << "O cliente eh socio?"<< endl;
    do{
        cin >> x;
        z ='a';
        if(cin.fail() ||  (x != 's' && x!='n')){
            cin.clear();
            cin.ignore(32767,'\n');
            cout << "Entrada invalida. Digite novamente:"<< endl;
            z='b';
        }
        
    }while(z!='a');
    this -> socio = x;
}
void cliente :: isSocio(char x){
    this->socio=x;
}

void cliente :: showSocio(){
    if(this->socio == 's'){
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
    cout << "função para encontrar clientes" << endl;
}