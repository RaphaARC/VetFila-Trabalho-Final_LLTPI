#ifndef ANIMALABB_HPP
#define ANIMALABB_HPP

struct AnimalBusca {
    int ID;
    AnimalBusca* dir;
    AnimalBusca* esq;

    AnimalBusca (int id) : ID(id), dir(nullptr), esq(nullptr) {}; // lista de inicialização
};

#endif