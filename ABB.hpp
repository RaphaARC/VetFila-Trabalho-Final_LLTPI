#ifndef ABB_HPP
#define ABB_HPP
#include "AnimalABB.hpp"

class ABB {
    private:

    AnimalBusca* raiz; //no inicial da estrutura

    AnimalBusca* inserirRecursivo(AnimalBusca* atual, int id);
    bool buscarRecursivo(AnimalBusca* no, int id) const;
    AnimalBusca* removerRecursivo (AnimalBusca* no, int id);
    void emOrdemRecursivo (AnimalBusca* no) const;
    int alturaRecursiva(AnimalBusca* no) const;
    int quantidadeNosRecursiva (AnimalBusca* no) const;
    void liberarRecursivo(AnimalBusca* no);

    public:

    ABB() : raiz(nullptr) {};
    ~ABB() {};
    void inserir(int id);
    bool buscar(int id) const;
    void remover(int id);
    void emOrdem() const;
    int altura () const;
    int quantidadeNos () const;
    AnimalBusca* ABB::menorValor(AnimalBusca* no) const;

};

#endif