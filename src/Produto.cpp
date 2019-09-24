#include <iostream>
#include <string>
#include "Produto.hpp"
#include <fstream>
#include <vector>

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
    string x, y, out="";
    int z;
    char n;
 do{   
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
    out=out+x;

    cout << "O produto se encaixa em outra categoria?[s/n]" << endl;
    do{
        cin >> n;
        y ="a";
        if(cin.fail() ||  (n != 's' && n!='n')){
            cin.clear();
            cin.ignore(32767,'\n');
            cout << "Entrada invalida. Digite novamente:"<< endl;
            y="b";
        }
        
    }while(y!="a");
    if(n=='s'){
        out=out+", ";
    }else{
        this->categoria=out;
    }

    cin.clear();
    cin.ignore(32767,'\n');

 }while(n=='s');  
}

void produto :: setpreco(){
    int x, y=0;
    cout << "Digite o preco do produto" << endl;
    do{
    y=0;
    cin >> x;
    if(cin.fail() || x<0){
        y=1;
        cin.clear();
        cin.ignore(32767,'\n');
        cout << "Entrada invalida. Digite-a novamente:" << endl;
    }

    }while(y==1);
    this->preco = x;
}

void produto :: setquantidade(){
    int x, y=0;
    cout << "Digite a quantidade de produtos" << endl;
    do{
    cin >> x;
    if(cin.fail() || x<0){
        y=1;
        cin.clear();
        cin.ignore(32767,'\n');
        cout << "Entrada invalida. Digite-a novamente:" << endl;
    }

    }while(y==1);
    this->quantidade = x;
}

string produto :: getnome(){
    return this->nome;
}

string produto :: getcategoria(){
    return this->categoria;
}

float produto :: getpreco(){
    return this->preco;
}

int produto :: getquantidade(){
    return this->quantidade;
}

void produto :: saveproduct(produto *p){
    fstream arq;
    arq.open("Produtos.txt", ios::out | ios::app);
    arq << p->getnome() << endl;
    arq << p->getcategoria() << endl;
    arq << p->getpreco() << endl;
    arq << p->getquantidade() << endl;
    arq.close();
}

vector<string> produto :: getlista(){
    fstream arq;
    string x;
    int i=0;
    vector <string> v;
    arq.open("Produtos.txt", ios::in);
    cout << "lista de produtos:\n"<< endl;
    while(getline(arq, x)){
        cout << "Codigo#:" << i << endl;
        cout << "Produto:" << x << endl;
        v.push_back(x);
        getline(arq, x);
        cout << "Categoria(s):" << x << endl;
        v.push_back(x);
        getline(arq, x);
        cout << "Preco:" << x << endl;
        v.push_back(x);
        getline(arq, x);
        cout << "Quantidade:" << x << "\n" << endl;
        v.push_back(x);
        i++;
    }
return v;
}

void produto :: carrinho(vector<string> pro){
    string x;
    int y, i, p1, quant;
    vector<string> backup=pro;
    cout << "Digite o codigo do produto para adicionar ao carrinho:"<<endl;
    do{
    y=0;
    cin >> i;
    if(cin.fail() || i<0 || (i*4)>pro.size()){
        y=1;
        cin.clear();
        cin.ignore(32767,'\n');
        cout << "Codigo invalido. Digite-o novamente:" << endl;
    }
    }while(y==1);
    p1=i;
    cout << "Produto selecionado:" << pro[p1*4] << endl;
    cout << "Digite a quantidade desejada:" << endl;
    do{
    y=0;
    cin >> i;
    if(cin.fail() || i<0 ){
        y=1;
        cin.clear();
        cin.ignore(32767,'\n');
        cout << "Entrada invalida."<< endl;
    }
    }while(y==1);

    // testar se é maior q a quant

}