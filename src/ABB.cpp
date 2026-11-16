#include "AnimalABB.hpp"
#include "ABB.hpp"
#include <iostream>
using namespace std;

// insere um animal na árvore
AnimalBusca* ABB::inserirRecursivo(AnimalBusca* atual, int id){
    if(atual == nullptr){return new AnimalBusca(id);}
    if(id < atual -> ID){
        atual -> esq = inserirRecursivo(atual -> esq, id);
    }else if(id > atual -> ID){
        atual -> dir = inserirRecursivo(atual -> dir, id);
    }
    return atual;
}

// usa inserir recursivo para inserir um animal na árvore
void ABB::inserir(int id){
    raiz = inserirRecursivo(raiz, id);
}

// busca um animal na árvore e retorna true se tiver encontrado e false se não
bool ABB::buscarRecursivo(AnimalBusca* no, int id, ContadoresPesquisa& c) const{
    if(no == nullptr){return false;}
    c.comparacoes++;
    if(id == no->ID){return true;}
    c.comparacoes++;
    if(id < no->ID){return buscarRecursivo(no->esq, id, c);}
    return buscarRecursivo(no->dir, id, c);
}

// utiliza buscarRecursivo para buscar um animal na árvore usando o id como chave
bool ABB::buscar(int id, ContadoresPesquisa& c) const{
    return buscarRecursivo(raiz, id, c);
}

AnimalBusca* ABB::removerRecursivo(AnimalBusca* no, int id) {
    if (no == nullptr) {
        return nullptr;
    }
    if (id < no->ID) {
        no->esq = removerRecursivo(no->esq, id);
    }
    else if (id > no->ID) {
        no->dir = removerRecursivo(no->dir, id);
    }
    else {
        if (no->esq == nullptr && no->dir == nullptr) {
            delete no;
            return nullptr;
        }
        if (no->esq == nullptr) {
            AnimalBusca* aux = no->dir;
            delete no;
            return aux;
        }
        if (no->dir == nullptr) {
            AnimalBusca* aux = no->esq;
            delete no;
            return aux;
        }
        AnimalBusca* sucessor = no->dir;
        while (sucessor->esq != nullptr) {
            sucessor = sucessor->esq;
        }
        no->ID = sucessor->ID;
        no->dir = removerRecursivo(no->dir, sucessor->ID);
    }
    return no;
}

void ABB::remover(int id) {
    raiz = removerRecursivo(raiz, id);
}

// imprime os animais em ordem crescente de ID
void ABB::emOrdemRecursivo(AnimalBusca* no) const{ 
    if(no == nullptr) {return;} //caso base
    emOrdemRecursivo(no -> esq);
    cout << no -> ID;
    emOrdemRecursivo(no -> dir);
}

// utiliza emOrdemRecursivo para mostrar os animais na árvore em ordem crescente referente aos IDs
void ABB::emOrdem() const{
    emOrdemRecursivo(raiz);
}

void ABB::liberarRecursivo(AnimalBusca* no) {
    if (no == nullptr) {
        return;
    }
    liberarRecursivo(no->esq);
    liberarRecursivo(no->dir);
    delete no;
}

int ABB::alturaRecursiva(AnimalBusca* no) const {
    if (no == nullptr) {
        return -1;
    }

    int alturaEsq = alturaRecursiva(no->esq);
    int alturaDir = alturaRecursiva(no->dir);

    if (alturaEsq > alturaDir) {
        return alturaEsq + 1;
    }

    return alturaDir + 1;
}

int ABB::altura(){
    return alturaRecursiva(raiz);
}

int ABB::quantNosRecursivo(AnimalBusca* no) const {
    if (no == nullptr) {
        return 0;
    }

    return 1 + quantNosRecursivo(no->esq) + quantNosRecursivo(no->dir);
}

int ABB::quantNos(){
    return quantNosRecursivo(raiz);
}

ABB::~ABB(){
    liberarRecursivo(raiz);
}