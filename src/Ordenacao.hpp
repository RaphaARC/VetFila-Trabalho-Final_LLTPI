#ifndef ORDENACAO_HPP
#define ORDENACAO_HPP
#include "Animal.hpp"

struct Contadores {
    long long comparacoes = 0; // entre frequência dos animais
    long long trocas = 0; //trocas de registros definidos pelos algoritmos
};

void quickSort(Animal animais[], int inicio, int fim, Contadores& c);
void insertionSort(Animal animais[], int tamanho, Contadores& c);
void selectionSort(Animal animais[], int tamanho, Contadores& c);

#endif