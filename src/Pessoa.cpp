#include <iostream>
#include <string>
#include "Pessoa.hpp"

using namespace std;

pessoa :: pessoa(){
    cout << "corno construido"<< endl;
}
pessoa :: ~pessoa(){
    cout << "corno destruido"<< endl;
}

void pessoa :: setnome(){
    string x;
    int z;
    do{
    z=0;
    getline(cin, x);
    for(int i=0;i<x.size();i++){
        if(isalpha(x[i]) || isspace(x[i])) {}
        else{
            cout << "O nome do cliente nao deve possuir caracteres especiais ou numeros!!"<<endl;
            cout << "Insira-o novamente:"<< endl;
            z=1;
            break;
        }
     }
    }while(z!=0);
    this->nome=x;  
}

void pessoa :: imprimenome(){
    cout << nome << endl;
}
