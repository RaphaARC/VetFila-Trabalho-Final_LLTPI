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
bool ABB::buscarRecursivo(AnimalBusca* no, int id) const{
    if(no == nullptr){return false;}
    if(id == no->ID){return true;}
    if(id < no->ID){return buscarRecursivo(no->esq, id);}
    if(id > no->ID){return buscarRecursivo(no->dir, id);}
}

// utiliza buscarRecursivo para buscar um animal na árvore usando o id como chave
bool ABB::buscar(int id) const{
    return buscarRecursivo(raiz, id);
}

//remove os nós da estrutura e retorna seus endereços
AnimalBusca* ABB::removerRecursivo(AnimalBusca* no, int id){
    if(no == nullptr){
        return nullptr;
    }
    if(id < no->ID){
        no->esq = removerRecursivo(no->esq, id);
    }
    else if(id > no->ID){
        no->dir = removerRecursivo(no->dir, id);
    }
    else{
        if(no->esq == nullptr && no->dir == nullptr){
            delete no;
            return nullptr;
        }else if(no->esq == nullptr){
            AnimalBusca* aux = no->dir;
            delete no;
            return aux;
        }else if(no->dir == nullptr){
            AnimalBusca* aux = no->esq;
            delete no;
            return aux;
        }
        else{
            AnimalBusca* sucessor = menorValor(no->dir);
            no->ID = sucessor->ID;
            no->dir = removerRecursivo(no->dir, sucessor->ID);
        }
    }
    return no;
}

//utiliza removerRecursivo para remover um nó da árvore
void ABB::remover(int id){
    raiz = removerRecursivo(raiz, id);
}

// imprime os animais em ordem crescente de ID
void ABB::emOrdemRecursivo(AnimalBusca* no) const{ 
    if(no == nullptr) {return;} //caso base
    emOrdemRecursivo(no -> esq);
    cout << no -> ID << " ";
    emOrdemRecursivo(no -> dir);
}

// utiliza emOrdemRecursivo para mostrar os animais na árvore em ordem crescente referente aos IDs
void ABB::emOrdem() const{
    emOrdemRecursivo(raiz);
}

AnimalBusca* ABB::menorValor(AnimalBusca* no) const{
    while(no->esq != nullptr){
        no = no->esq;
    }
    return no;
}

int ABB::alturaRecursiva(AnimalBusca* no) const{
    if(no == nullptr){
        return -1;
    }
    int alturaEsq = alturaRecursiva(no->esq);
    int alturaDir = alturaRecursiva(no->dir);
    if(alturaEsq > alturaDir){
        return alturaEsq + 1;
    }
    return alturaDir + 1;
}

int ABB::altura() const{
    return alturaRecursiva(raiz);
}

int ABB::quantidadeNosRecursiva(AnimalBusca* no) const{
    if(no == nullptr){
        return 0;
    }
    return 1 +
    quantidadeNosRecursiva(no->esq) +
    quantidadeNosRecursiva(no->dir);
}

int ABB::quantidadeNos() const{
    return quantidadeNosRecursiva(raiz);
}

void ABB::liberarRecursivo(AnimalBusca* no){
    if(no == nullptr){
        return;
    }
    liberarRecursivo(no->esq);
    liberarRecursivo(no->dir);
    delete no;
}

// destrutor
ABB::~ABB(){
    liberarRecursivo(raiz);
}