#ifndef recomendacao_hpp
#define recomendacao_hpp
#include <iostream>
#include <string>
#include "Produto.hpp"

class recomendacao : public produto
{

public:
    recomendacao();
    ~recomendacao();
    vector<string> separacategoria();
    vector<string> separacategoria(vector<string> v);
    void historico(vector<string> categorias, string cpf);
    vector<string> gethistorico();
    void recomenda(vector<string> vet);
    void salvahistorico();
    vector<string> analisahist();
};
#endif