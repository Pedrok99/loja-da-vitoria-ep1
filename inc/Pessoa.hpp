#ifndef pessoa_hpp
#define pessoa_hpp

#include <iostream>
#include <string>

using namespace std;

class pessoa {
    private:
        string nome, cpf, idade;
    public:
        pessoa();
        ~pessoa();
        void setnome();
        void setnome(string nome);
        string getnome();
        void setidade();
        void setidade(string idade);
        string getidade();
        void setcpf();
        void setcpf(string cpf);
        string getcpf();
        void imprimedados();
        virtual void abst ()=0; 
};
#endif