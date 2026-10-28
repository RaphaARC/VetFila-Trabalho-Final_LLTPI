#include <iostream>
#include "ListaDupla.hpp"
using namespace std;

ListaDupla::ListaDupla() {
    itAtual = registros.begin();
}

void ListaDupla::adicionarRegistro(const Animal& acao) {
    registros.push_back(acao);
    itAtual = registros.end();
}

void ListaDupla::mostrarHistorico() const {
    if (registros.empty()) {
        cout << "Nenhum procedimento encontrado no histórico." << endl;
        return;
    }

    cout << "Histórico de Procedimentos:" << endl;
    for (const auto& registro : registros) {
        cout << "ID: " << registro.id << ", Nome do Animal: " << registro.nome
             << ", Espécie: " << registro.especie << ", Raça: " << registro.raca
             << ", Idade: " << registro.idade << ", Nome do Tutor: " << registro.nomeTutor
             << ", Telefone do Tutor: " << registro.telefoneTutor
             << ", Frequência de Visitas: " << registro.frequenciaVisitas
             << endl << endl;
    }
}


/*
    Os próximos dois métodos permitem navegar entre os registros. Pesquisei um pouco e descobri o uso de pop_back(),
    mas esse comando deleta o ultimo registro da lista. Como não quero deletar registros, tive que descobrir alternativas a isso. 
    Busquei novamente na internet e descobri os iteradores, então vou usar iteradores para navegar.
*/

void ListaDupla::irParaAnterior() {
    // Navegar para o registro anterior sem remover o registro atual
    if(estaVazia()) {
        cout << "A lista está vazia." << endl;
        return;
    }
    
    if (itAtual != registros.begin()) {
        --itAtual;
    } else {
        cout << "Já está no primeiro registro." << endl;
    }
}

void ListaDupla::irParaProximo() {
    // Navegar para o registro seguinte sem remover o registro atual
    if(estaVazia()) {
        cout << "A lista está vazia." << endl;
        return;
    }
    
    if (itAtual != registros.end()) {
        ++itAtual;
    } else {
        cout << "Já está no último registro." << endl;
    }
}

void ListaDupla::desfazerUltimaAcao() {
    if (!registros.empty()) {
        registros.pop_back(); // Remove o último procedimento registrado no histórico
        cout << "Último procedimento removido do histórico." << endl;
    } else {
        cout << "A lista está vazia. Nenhuma ação para desfazer." << endl;
    }
}

void ListaDupla::limparHistorico() {
    registros.clear();
    cout << "Histórico de procedimentos limpo." << endl;
}

bool ListaDupla::estaVazia() const {
    return registros.empty();
}

int ListaDupla::obterTamanho() const {
    return registros.size();
}