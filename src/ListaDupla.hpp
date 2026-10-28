#ifndef LISTA_HPP
#define LISTA_HPP

#include <list>
#include "Animal.hpp"

class ListaDupla {
private:
    std::list<Animal> registros;
    std::list<Animal>::iterator itAtual; // Iterador para o registro atual na lista

public:
    ListaDupla();
    void adicionarRegistro(const Animal& acao);
    void mostrarHistorico() const;
    void irParaAnterior();
    void irParaProximo();
    void desfazerUltimaAcao();
    bool estaVazia() const;
    int obterTamanho() const;
    void limparHistorico();
};

#endif //LISTA_HPP