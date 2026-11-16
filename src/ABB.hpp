#ifndef ABB_HPP
#define ABB_HPP
#include "AnimalABB.hpp"
#include "Pesquisa.hpp"

class ABB {
    private:

    AnimalBusca* raiz; //no inicial da estrutura

    AnimalBusca* inserirRecursivo(AnimalBusca* atual, int id);
    bool buscarRecursivo(AnimalBusca* no, int id, ContadoresPesquisa& c) const;
    AnimalBusca* removerRecursivo (AnimalBusca* no, int id);
    void emOrdemRecursivo (AnimalBusca* no) const;
    void liberarRecursivo(AnimalBusca* no);
    int alturaRecursiva (AnimalBusca* no) const;
    int quantNosRecursivo (AnimalBusca* no) const;

    public:

    ABB() : raiz(nullptr) {};
    void inserir(int id);
    bool buscar(int id, ContadoresPesquisa& c) const;
    void remover(int id);
    void emOrdem() const;
    int altura();
    int quantNos();
    ~ABB();

};

#endif