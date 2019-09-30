#include <iostream>
#include <string>
#include "Pessoa.hpp"
#include "Cliente.hpp"
#include "Produto.hpp"
#include "Recomendacao.hpp"
#include <vector>
using namespace std;

int main()
{
  int opc, checker;
  string aux, tempchar;
  cliente c;
  produto p;
  recomendacao r;
  vector<string> vet, vaux, temp;

  do
  {
    cout << "\n\n"
         << endl;
    cout << "=========================================" << endl;
    cout << "=-         LOJINHA DA VICTORIA         -=" << endl;
    cout << "=========================================" << endl;

    cout << "\t\t   Menu\n"
         << endl;
    cout << "\t1 - Modo Venda" << endl;
    cout << "\t2 - Modo Estoque" << endl;
    cout << "\t3 - Modo Recomendacao" << endl;
    cout << "\t0 - Sair\n"
         << endl;
    cout << "Digite o numero da opcao : " << endl;

    do
    {
      checker = 0;
      cin >> opc;
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(10000, '\n');
        checker = 1;
        cout << "Entrada Invalida!! \n"
             << endl;
      }
    } while (checker == 1);

    switch (opc)
    {
    case 1:

      cin.clear();
      cin.ignore(10000, '\n');
      c = c.find();
      if (c.getnome() == "0")
      {
        cout << "Por favor cadastre o cliente:\n"
             << endl;
        c.setnome();
        c.setidade();
        c.setcpf();
        c.isSocio();
        c.saveclient(&c);
      }
      else
      {
      }
      cout << "Nome : " << c.getnome() << "\n"
           << endl;
      cout << "Pressione qualquer tecla para ir a lista de produtos :" << endl;

      getline(cin, tempchar);
      cout << "Listando Produtos...\n"
           << endl;
      vet = p.getlista();
      if (vet[0] == "0")
        {
          break;
        }
      r.historico(p.carrinho(vet, c.getSocio()), c.getcpf());
      r.salvahistorico();
      cout << "Compra encerrada. Retornando ao menu..." << endl;

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
          cout << "Opcao Invalida !! Digite novamente:\n"
               << endl;
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
        cout << "Produto adicionado !!\n\n"
             << endl;
      }
      else
      {
        vaux = p.getlista();
        if (vaux[0] == "0")
        {
          break;
        }
        cout << "Digite o codigo do produto que sera atualizado:" << endl;
        do
        {

          checker = 0;
          cin >> opc;
          if (cin.fail() || (opc * 4) >= (int)vaux.size() || opc < 0)
          {
            cout << "Opcao Invalida !! Digite Novamente:" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            checker = 1;
          }
        } while (checker == 1);
        p.attproduto(p.getlista(), opc);
      }
      opc = 1;
      break;
    case 3:
      temp = r.analisahist();
      if (temp[0] == "*")
      {
        break;
      }
      r.recomenda(temp);

      break;

    default:
      break;
    };
  } while (opc != 0);

  return 0;
}