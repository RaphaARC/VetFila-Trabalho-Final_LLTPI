#ifndef ANIMAIS_HPP
#define ANIMAIS_HPP

struct Animal {
    int ID;
    Animal* dir;
    Animal* esq;

    Animal(int id) : ID(id), dir(nullptr), esq(nullptr) {}; // lista de inicialização
};

#endif