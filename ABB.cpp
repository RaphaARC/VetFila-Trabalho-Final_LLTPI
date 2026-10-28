#include "Animal.hpp"
#include "ABB.hpp"
#include <iostream>
using namespace std;

// insere um animal na árvore
Animal* ABB::inserirRecursivo(Animal* atual, int id){
    if(atual == nullptr){return new Animal(id);}
    if(id < atual -> ID){
        atual -> esq = inserirRecursivo(atual -> esq, id);
    }else if(id > atual -> ID){
        atual -> dir = inserirRecursivo(atual -> dir, id);
    }
    return atual;
}

// usa inserir recursivo para inserir um animal na árvore
void ABB::inserir(int id){
    inserirRecursivo(raiz, id);
}

// busca um animal na árvore e retorna true se tiver encontrado e false se não
bool ABB::buscarRecursivo(Animal* no, int id) const{
    if(no == nullptr){return false;}
    if(id == no->ID){return true;}
    if(id < no->ID){buscarRecursivo(no->esq, id);}
    if(id > no->ID){buscarRecursivo(no->dir, id);}
}

// utiliza buscarRecursivo para buscar um animal na árvore usando o id como chave
bool ABB::buscar(int id) const{
    buscarRecursivo(raiz, id);
}

Animal* ABB::removerRecursivo(Animal* no, int id) {
    if(no == nullptr){return no;}
    if(id == no -> ID) {
        Animal* aux = no;
        delete aux;
        return no;
    }else if(id < no ->ID){
        removerRecursivo(no->esq, id);
    }
    removerRecursivo(no->dir,id);
}

// imprime os animais em ordem crescente de ID
void ABB::emOrdemRecursivo(Animal* no) const{ 
    if(no == nullptr) {return;} //caso base
    emOrdemRecursivo(no -> esq);
    cout << no -> ID;
    emOrdemRecursivo(no -> dir);
}

// utiliza emOrdemRecursivo para mostrar os animais na árvore em ordem crescente referente aos IDs
void ABB::emOrdem() const{
    emOrdemRecursivo(raiz);
}