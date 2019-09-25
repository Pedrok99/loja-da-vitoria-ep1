#ifndef produto_hpp
#define produto_hpp

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class produto
{
private:
    string nome, categoria;
    float preco;
    int quantidade;

public:
    produto();
    ~produto();

    void setnome();
    string getnome();
    void setcategoria();
    string getcategoria();
    void setpreco();
    float getpreco();
    void setquantidade();
    //void setquantidade();
    int getquantidade();
    void saveproduct(produto *p);
    vector<string> getlista();
    void carrinho(vector<string> pro, string s);
    void attproduto(vector<string> pro, int cod);
};

#endif