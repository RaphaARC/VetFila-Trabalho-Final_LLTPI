#include <iostream>
#include "Fila.hpp"

void Fila::enfileirar(const Animal& animal) {
    animais.push(animal);
}

void Fila::desenfileirar() {
    if (animais.empty()) {
        std::cout << "A fila está vazia.\n";
        return;
    }

    animais.pop();
}

/*
  A implementação de std::queue não permite acesso dirto aos elementos da fila por índices ou iterações, 
  então é necessário criar uma cópia da fila para percorrer
*/

void Fila::mostrarFila() const {
    if (animais.empty()) {
        std::cout << "A fila está vazia.\n";
        return;
    }

    std::queue<Animal> copiaFila = animais; // Cria uma cópia da fila para percorrer

    std::cout << "Animais na fila:\n";
    while (!copiaFila.empty()) {
        const Animal& animal = copiaFila.front();
        std::cout << "ID: " << animal.id << ", Nome: " << animal.nome << ", Espécie: " << animal.especie
                  << ", Raça: " << animal.raca << ", Idade: " << animal.idade
                  << ", Nome do Tutor: " << animal.nomeTutor
                  << ", Telefone do Tutor: " << animal.telefoneTutor
                  << ", Frequência de Visitas: " << animal.frequenciaVisitas << endl;
        copiaFila.pop();
    }
}

void Fila::consultarProximo() const {
    if (animais.empty()) {
        std::cout << "A fila está vazia.\n";
        return;
    }

    const Animal& proximoAnimal = animais.front(); // Obtem o próximo
    std::cout << "Próximo animal na fila:\n";
    std::cout << "ID: " << proximoAnimal.id << endl;
    std::cout << "Nome: " << proximoAnimal.nome << endl;
    std::cout << "Espécie: " << proximoAnimal.especie << endl;
    std::cout << "Raça: " << proximoAnimal.raca << endl;
    std::cout << "Idade: " << proximoAnimal.idade << endl;
    std::cout << "Nome do Tutor: " << proximoAnimal.nomeTutor << endl;
    std::cout << "Telefone do Tutor: " << proximoAnimal.telefoneTutor << endl;
    std::cout << "Frequência de Visitas: " << proximoAnimal.frequenciaVisitas << endl;
}

int Fila::obterTamanho() const {
    return animais.size();
}

bool Fila::estaVazia() const {
    return animais.empty();
}