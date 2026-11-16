#include "Animal.hpp"
#include "Pesquisa.hpp"

int pesquisaBinaria(Animal animais[], int tamanho, int frequencia, ContadoresPesquisa& c) {
    int inicio = 0;
    int fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        c.comparacoes++;
        if (animais[meio].frequenciaVisitas == frequencia) {
            return meio;
        }
        if (animais[meio].frequenciaVisitas > frequencia) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}