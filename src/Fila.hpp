#ifndef FILA_HPP
#define FILA_HP

#include <queue>
#include "Animal.hpp"

class Fila {
private:
    std::queue<Animal> animais; 
    // Fila de animais, usando std:: queue para facilitar a implementação, colocando a struct Animal como tipo de dado da fila

public:
    Fila();
    void enfileirar(const Animal& animal); // Adiciona um animal à fila
    void desenfileirar(); // Remove um animal da fila
    bool estaVazia() const; // Verifica se há pelo menos um animal na fila
    int obterTamanho() const; // Retorna o tamanho da fila
    void consultarProximo() const; // Consulta o próximo animal na fila de espera sem removê-lo
    void mostrarFila() const; // Exibe todos os animais na fila
};

#endif //FILA_HPP