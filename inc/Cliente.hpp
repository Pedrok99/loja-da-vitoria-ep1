#ifndef cliente_hpp
#define cliente_hpp

#include <iostream>
#include <string>
#include "Pessoa.hpp"

using namespace std;

class cliente : public pessoa {
    private:
        string socio;
    public:
        cliente();
        ~cliente();
        void abst (){}; 
        void isSocio();
        void isSocio(string x);
        void showSocio();
        void saveclient(cliente *p); 
        void find();  
};

#endif