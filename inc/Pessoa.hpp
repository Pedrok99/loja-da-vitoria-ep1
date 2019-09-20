#ifndef pessoa_hpp
#define pessoa_hpp

#include <iostream>
#include <string>

using namespace std;

class pessoa {
    private:
        string nome, socio;
        string cpf, idade;
    public:
        pessoa();
        ~pessoa();
        void setnome();
        string getnome();
        void setidade();
        string getidade();
        void setcpf();
        string getcpf();
        void issocio();
        string showsocio();
        void imprimedados();
        //virtual void abst ()=0; 
};
#endif