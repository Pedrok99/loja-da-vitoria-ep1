#include <iostream>
#include <string>
#include "Pessoa.hpp"
using namespace std;

int main(){

    pessoa p1;

    p1.setnome();
    p1.setidade();
    p1.setcpf();
    p1.imprimedados();

    return 0;
}