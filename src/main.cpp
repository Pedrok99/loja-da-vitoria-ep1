#include <iostream>
#include <string>
#include "Pessoa.hpp"
#include "Cliente.hpp"
using namespace std;

int main(){
  int opc, y;
  cliente c;
system("cls");

do{
  cout << "========================================="<< endl;
  cout << "=          LOJINHU DU PEDRINHU          ="<< endl;
  cout << "========================================="<< endl;

  cout <<"\tMenu" << endl;
  cout <<"1 - Cadastramento de Clientes"<< endl;
  cout <<"2 - Modo Venda"<< endl;
  cout <<"3 - Modo Estoque"<< endl;
  cout <<"4 - Modo Recomendacao"<< endl;
  cout <<"0 - Sair" << endl;

  do{
  y=0;
  cin >> opc;
  if(cin.fail()){
  cin.clear();
  cin.ignore(10000, '\n');
  y=1;
  }
  }while(y==1);

  system("cls");

  switch (opc)
  {
  case 1:
  cin.clear();    
  cin.ignore(10000, '\n');
  c.setnome();
  c.setidade();
  c.setcpf();
  c.isSocio();
  c.saveclient(&c);
  cout << "Cliente cadastrado e salvo com sucesso !!" << endl;
  break;

  case 2:
    
  break;



  default:
  break;
  };
}while(opc!=0);
   
return 0;
}