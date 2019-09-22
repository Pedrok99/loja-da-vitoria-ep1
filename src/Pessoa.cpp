#include <iostream>
#include <string>
#include "Pessoa.hpp"

using namespace std;

pessoa :: pessoa(){
    cout << "Pessoa construida"<< endl;
}
pessoa :: ~pessoa(){
    cout << "Pessoa destruida"<< endl;
}

void pessoa :: setnome(){
    string x;
    int z;
    cout << "Digite o nome do cliente:"<<endl;

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
void pessoa :: setnome(string nome){
    this->nome = nome;
}
void pessoa :: setidade(){
    int x, y;
    cout << "Digite a idade do cliente:"<<endl;
    do{
    y=0;
    cin >> x;
    if(x<0 || x>100 || cin.fail()){
        cout <<"Idade invalida. Digite novamente:"<< endl;
        y=1;
    }
    cin.clear();
    cin.ignore(32767,'\n');
    }while(y!=0);
   
   this-> idade = to_string(x);

}
void pessoa :: setidade(string idade){
    this->idade = idade;
}
void pessoa :: setcpf(){
    string x;
    int y; 
    cout << "Digite o CPF do cliente:"<<endl;
    do{
     y=0;
        getline(cin, x);
        for(int i=0;i<x.size();i++){
            if(!isdigit(x[i]) || isspace(x[i]) || x.size()!=11){
            y=1;
        }
    }
    if(y==1){
        cout <<"Cpf invalido. Digite novamente:"<< endl;
    }
    
    }while(y!=0);
   
   this-> cpf = x;

}

void pessoa :: setcpf(string cpf){
    this->cpf= cpf;
}

string pessoa::getcpf(){
    return this->cpf;
}
string pessoa::getidade(){
    return this->idade;
}
string pessoa::getnome(){
    return this->nome;
}

void pessoa :: imprimedados(){
    cout <<"Nome:"<< getnome() << endl;
    cout <<"Idade:"<< getidade() << endl;
    cout << "CPF:"<< getcpf() << endl;
}
