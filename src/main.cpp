#include <iostream>
#include <string>
#include "Pessoa.hpp"
#include "Cliente.hpp"
#include "Produto.hpp"
#include <vector>
using namespace std;

int main(){
  int opc, checker;
  string aux;
  cliente c;
  produto p;
  vector<string> vet; 
 
system("cls");

do{
  cout << "========================================="<< endl;
  cout << "=          LOJINHU DU PEDRINHU          ="<< endl;
  cout << "========================================="<< endl;

  cout <<"\t\t   Menu\n" << endl;
  cout <<"1 - Modo Venda"<< endl;
  cout <<"2 - Modo Estoque"<< endl;
  cout <<"3 - Modo Recomendacao"<< endl;
  cout <<"0 - Sair" << endl;

  do{
  checker=0;
  cin >> opc;
  if(cin.fail()){
  cin.clear();
  cin.ignore(10000, '\n');
  checker=1;
  }
  }while(checker==1);

  system("cls");

  switch (opc)
  {
  case 1:
    cin.clear();
    cin.ignore(10000,'\n');/*
    c=c.find();
    aux=c.getnome();
   if(c.getnome()=="0"){
      cout << "Por favor cadastre-o." << endl;
      c.setnome();
      c.setidade();
      c.setcpf();
      c.isSocio();
    }else{
    }
    c.imprimedados();
    c.showSocio();
    c.saveclient(&c);*/
    vet=p.getlista();
    
  break;

  case 2:
    
  break;



  default:
  break;
  };
}while(opc!=0);
   
return 0;
}