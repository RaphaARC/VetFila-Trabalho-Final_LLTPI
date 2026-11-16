#ifndef PESQUISA_HPP
#define PESQUISA_HPP
#include "Animal.hpp"
using namespace std;

struct ContadoresPesquisa
{
    long long comparacoes = 0;
};

int pesquisaBinaria(Animal animais[], int tamanho, int frequencia, ContadoresPesquisa& c);

#endif