#include <iostream>
#include <string>
#include "Produto.hpp"

using namespace std;

produto :: produto(){}
produto :: ~produto(){}

void produto::setnome(){
    string x;
    int z;
    cout << "Digite o nome do produto:"<<endl;
    do{
    z=0;
    getline(cin, x);
    for(int i=0;i<x.size();i++){
        if(isalpha(x[i]) || isspace(x[i])) {}
        else{
            cout << "Nome invalido!! Insira-o novamente:"<<endl;
            z=1;
            break;
        }
     }
    }while(z!=0);
    this->nome=x;  
}

void produto :: setcategoria(){
   string x, y;
    int z;
    cout << "Digite a categoria do produto:"<<endl;
    do{
    z=0;
    getline(cin, x);
    for(int i=0;i<x.size();i++){
        if(isalpha(x[i]) || isspace(x[i])) {}
        else{
            cout << "Nome invalido!! Insira-o novamente:"<<endl;
            z=1;
            break;
        }
     }
    }while(z!=0);

    cout << "O produto se encaixa em outra categoria?[s/n]" << endl;
    do{
        cin >> x;
        y ="a";
        if(cin.fail() ||  (x != "s" && x!="n")){
            cin.clear();
            cin.ignore(32767,'\n');
            cout << "Entrada invalida. Digite novamente:"<< endl;
            y="b";
        }
    }while(y!="a");
    
    this->nome=x;  
}