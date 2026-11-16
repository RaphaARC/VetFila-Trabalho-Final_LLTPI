#include "Ordenacao.hpp"
#include "Animal.hpp"

void selectionSort(Animal animais[], int tamanho, Contadores& c) {
    for (int i = 0; i < tamanho - 1; i++) {
        int maior = i;
        for (int j = i + 1; j < tamanho; j++) {
            c.comparacoes++;
            if (animais[j].frequenciaVisitas >
                animais[maior].frequenciaVisitas) {
                maior = j;
            }
        }
        if (maior != i) {
            Animal aux = animais[i];
            animais[i] = animais[maior];
            animais[maior] = aux;
            c.trocas++;
        }
    }
}


void insertionSort(Animal animais[], int tamanho, Contadores& c) {
    for (int i = 1; i < tamanho; i++) {
        int j = i;
        while (j > 0) {
            c.comparacoes++;
            if (animais[j].frequenciaVisitas >
                animais[j - 1].frequenciaVisitas) {
                Animal aux = animais[j];
                animais[j] = animais[j - 1];
                animais[j - 1] = aux;
                c.trocas++;
                j--;
            }
            else {
                break;
            }
        }
    }
}


int particionar(Animal animais[], int inicio, int fim, Contadores& c) {
    Animal pivo = animais[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        c.comparacoes++;
        if (animais[j].frequenciaVisitas >
            pivo.frequenciaVisitas) {
            i++;
            Animal aux = animais[i];
            animais[i] = animais[j];
            animais[j] = aux;
            c.trocas++;
        }
    }
    Animal aux = animais[i + 1];
    animais[i + 1] = animais[fim];
    animais[fim] = aux;
    c.trocas++;
    return i + 1;
}

void quickSort(Animal animais[], int inicio, int fim, Contadores& c) {
    if (inicio < fim) {
        int posPivo = particionar(animais, inicio, fim, c);
        quickSort(animais, inicio, posPivo - 1, c);
        quickSort(animais, posPivo + 1, fim, c);
    }
}

