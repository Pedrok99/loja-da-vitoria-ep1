#ifndef produto_hpp
#define produto_hpp

#include <iostream>
#include <string>
using namespace std;

class produto {
    private:
        string nome, categoria;
        int preco, quantidade;
    public:
        produto();
        ~produto();

        void setnome();
        void setcategoria();
        void setpreco();
        void setquantidade();
};

#endif