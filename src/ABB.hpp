#ifndef ABB_HPP
#define ABB_HPP
#include "Animal.hpp"

class ABB {
    private:

    Animal* raiz; //no inicial da estrutura

    Animal* inserirRecursivo(Animal* atual, int id);
    bool buscarRecursivo(Animal* no, int id) const;
    Animal* removerRecursivo (Animal* no, int id);
    void emOrdemRecursivo (Animal* no) const;

    public:

    ABB() : raiz(nullptr) {};
    void inserir(int id);
    bool buscar(int id) const;
    void remover(int id);
    void emOrdem() const;
    int altura (Animal* no) const;
    int quantNos (Animal* no) const;

};

#endif