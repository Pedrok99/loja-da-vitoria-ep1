#include <iostream>
#include <string>
#include <fstream>

using namespace std;

fstream arquivo;
int contador=0, x, i, rule=0;
string dados[100], dado, search;


int main(){ 

    arquivo.open("Listadeclientes.txt", ios:: in | ios::app);

    while(getline(arquivo, dado)){
        dados[contador]= dado;
        contador++;
    }

    cout << "Digite o nome do cliente que deseja fazer alteracoes: " << endl;
    getline(cin , search);

    for(i=0; i<contador; i++){
        if(dados[i]==search){
            cout << "Cliente encontrado!"<< endl;
            rule = 1;
            break;
        } 
    }
    if(rule == 0){
        cout << "Cliente nao encontrado !" << endl;
        return 0;
    }

    cout << "O que gostaria de editar ?" << endl;
    cout << "1.Nome" << endl;
    cout << "2.Idade" << endl;
    cin >> x;

    switch (x)
    {
    case 1:
        cout << "Digite o novo nome: "<< endl;
        getline(cin >> ws, dados[i]);
        break;
    case 2:
        cout << "Digite a nova idade: "<< endl;
        getline(cin >> ws, dados[++i]);
        break;
    
    default:
        cout << "Operação cancelada" <<endl;
        return 0;
        break;
    }

    for(i=0; i<contador; i++){
        cout << dados[i] << endl; 
    }
    arquivo.close();

    arquivo.open("Listadeclientes.txt", ios:: out | ios::trunc);

    for(i=0; i<contador; i++){
        arquivo << dados[i] << endl;
    }

    arquivo.close();

    return 0;
}