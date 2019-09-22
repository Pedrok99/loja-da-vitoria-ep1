#include <iostream>
#include <string>
#include "Pessoa.hpp"
#include "Cliente.hpp"
using namespace std;

int main(){

    cliente c;

    c.setnome();
    c.setidade();
    c.setcpf();
    c.isSocio();
    c.saveclient(&c);
    c.imprimedados();
    c.showSocio();
    c.find();

    return 0;
}