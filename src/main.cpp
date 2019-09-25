#include <iostream>
#include <string>
#include "Pessoa.hpp"
#include "Cliente.hpp"
#include "Produto.hpp"
#include <vector>
using namespace std;

void limpa()
{
  cout << "\n\n\n\n\n\n"
       << endl;
}

int main()
{
  int opc, checker;
  string aux;
  cliente c;
  produto p;
  vector<string> vet, vaux;

  do
  {
    cout << "=========================================" << endl;
    cout << "=          LOJINHU DU PEDRINHU          =" << endl;
    cout << "=========================================" << endl;

    cout << "\t\t   Menu\n"
         << endl;
    cout << "1 - Modo Venda" << endl;
    cout << "2 - Modo Estoque" << endl;
    cout << "3 - Modo Recomendacao" << endl;
    cout << "0 - Sair" << endl;

    do
    {
      checker = 0;
      cin >> opc;
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(10000, '\n');
        checker = 1;
      }
    } while (checker == 1);

    limpa();

    switch (opc)
    {
    case 1:

      cin.clear();
      cin.ignore(10000, '\n');
      c = c.find();
      if (c.getnome() == "0")
      {
        cout << "Por favor cadastre o cliente." << endl;
        c.setnome();
        c.setidade();
        c.setcpf();
        c.isSocio();
        c.saveclient(&c);
      }
      else
      {
      }
      cout << c.getnome() << endl;
      // c.imprimedados();
      // c.showSocio();
      cout << "Pressione qualquer tecla para ir ao catalogo de produtos..." << endl;
      getchar();
      vet = p.getlista();
      p.carrinho(vet, c.getSocio());
      cout << "Insira qualquer coisa para retornar ao menu :" << endl;

      break;

    case 2:
      cout << "0 - Novo Produto." << endl;
      cout << "1 - Produto existente." << endl;
      do
      {
        checker = 0;
        cin >> opc;
        if (cin.fail() || opc >= 2)
        {
          cout << "Opcao Invalida" << endl;
          cin.clear();
          cin.ignore(10000, '\n');
          checker = 1;
        }
      } while (checker == 1);

      if (opc == 0)
      {
        cin.clear();
        cin.ignore(10000, '\n');
        p.setnome();
        p.setcategoria();
        p.setquantidade();
        p.setpreco();
        p.saveproduct(&p);
        cout << "Produto adicionado !!" << endl;
      }
      else
      {
        vaux = p.getlista();
        do
        {
          cout << "Digite o codigo do produto que sera atualizado" << endl;
          checker = 0;
          cin >> opc;
          cout << vaux.size() << endl;
          if (cin.fail() || (opc * 4) >= vaux.size() || opc < 0)
          {
            cout << "Opcao Invalida" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
          }
        } while (checker == 1);
        p.attproduto(p.getlista(), opc);
      
      }
      opc=1;
      break;

    default:
      break;
    };
  } while (opc != 0);

  return 0;
}