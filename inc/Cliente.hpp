#ifndef cliente_hpp
#define cliente_hpp

#include <iostream>
#include <string>
#include "Pessoa.hpp"

using namespace std;

class cliente : public pessoa {
    private:
        char socio;
    public:
        cliente();
        ~cliente();
        void abst (){}; 
        void isSocio();
        void isSocio(char x);
        void showSocio();
        void saveclient(cliente *p); 
        void find();  
};

#endif