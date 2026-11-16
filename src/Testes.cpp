
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <algorithm>
#include <iomanip>

#include "Animal.hpp"
#include "Ordenacao.hpp"
#include "Pesquisa.hpp"
#include "Fila.hpp"
#include "ABB.hpp"

using namespace std;

// ==================================================
// 1. GERACAO DOS ANIMAIS
// ==================================================

vector<Animal> gerarAnimais(int quantidade) {
    vector<Animal> animais;

    mt19937 gerador(42);
    uniform_int_distribution<int> distribuicao(1, 100);

    for (int i = 0; i < quantidade; i++) {
        Animal a;

        a.id = 1000 + i;
        a.nome = "Animal" + to_string(i);
        a.especie = "Cachorro";
        a.raca = "Vira-lata";
        a.idade = 2;
        a.nomeTutor = "Tutor" + to_string(i);
        a.telefoneTutor = "31999990000";
        a.frequenciaVisitas = distribuicao(gerador);

        animais.push_back(a);
    }

    return animais;
}

// ==================================================
// 2. TESTES DE ORDENACAO
// ==================================================

void testarOrdenacao(const vector<Animal>& animais) {

    vector<Animal> vetorSelection = animais;
    vector<Animal> vetorInsertion = animais;
    vector<Animal> vetorQuick = animais;

    Contadores cSelection;
    Contadores cInsertion;
    Contadores cQuick;

    selectionSort(
        vetorSelection.data(),
        static_cast<int>(vetorSelection.size()),
        cSelection
    );

    insertionSort(
        vetorInsertion.data(),
        static_cast<int>(vetorInsertion.size()),
        cInsertion
    );

    quickSort(
        vetorQuick.data(),
        0,
        static_cast<int>(vetorQuick.size()) - 1,
        cQuick
    );

    cout << "\n========== ORDENACAO ==========\n";

    cout << left << setw(20) << "Algoritmo"
         << setw(18) << "Comparacoes"
         << "Trocas\n";

    cout << string(50, '-') << endl;

    cout << left << setw(20) << "Selection Sort"
         << setw(18) << cSelection.comparacoes
         << cSelection.trocas << endl;

    cout << left << setw(20) << "Insertion Sort"
         << setw(18) << cInsertion.comparacoes
         << cInsertion.trocas << endl;

    cout << left << setw(20) << "QuickSort"
         << setw(18) << cQuick.comparacoes
         << cQuick.trocas << endl;
}

// ==================================================
// 3. TESTES DE PESQUISA
// ==================================================

void testarPesquisa(
    const vector<Animal>& animais,
    Fila& fila,
    ABB& abb
) {

    vector<Animal> vetorOrdenado = animais;

    Contadores ordenacaoAuxiliar;

    selectionSort(
        vetorOrdenado.data(),
        static_cast<int>(vetorOrdenado.size()),
        ordenacaoAuxiliar
    );

    // PESQUISA SEQUENCIAL

    cout << "\n========== PESQUISA SEQUENCIAL ==========\n";

    ContadoresPesquisa cFilaEncontrado;
    Animal encontrado;

    string tutorExistente =
        "Tutor" + to_string(animais.size() - 1);

    bool resultadoFila = fila.pesquisarTutor(
        tutorExistente,
        encontrado,
        cFilaEncontrado
    );

    cout << "Tutor procurado: " << tutorExistente << endl;
    cout << "Encontrado: " << (resultadoFila ? "Sim" : "Nao") << endl;
    cout << "Comparacoes: " << cFilaEncontrado.comparacoes << endl;

    ContadoresPesquisa cFilaAusente;

    bool resultadoFilaAusente = fila.pesquisarTutor(
        "TutorInexistente",
        encontrado,
        cFilaAusente
    );

    cout << "\nPesquisa de tutor inexistente:\n";
    cout << "Encontrado: "
         << (resultadoFilaAusente ? "Sim" : "Nao") << endl;
    cout << "Comparacoes: " << cFilaAusente.comparacoes << endl;

    // PESQUISA BINARIA

    cout << "\n========== PESQUISA BINARIA ==========\n";

    int frequenciaExistente =
        vetorOrdenado[vetorOrdenado.size() / 2].frequenciaVisitas;

    ContadoresPesquisa cBinariaEncontrado;

    int posicao = pesquisaBinaria(
        vetorOrdenado.data(),
        static_cast<int>(vetorOrdenado.size()),
        frequenciaExistente,
        cBinariaEncontrado
    );

    cout << "Frequencia procurada: "
         << frequenciaExistente << endl;

    cout << "Encontrada: "
         << (posicao != -1 ? "Sim" : "Nao") << endl;

    cout << "Comparacoes: " << cBinariaEncontrado.comparacoes << endl;

    ContadoresPesquisa cBinariaAusente;

    int posicaoAusente = pesquisaBinaria(
        vetorOrdenado.data(),
        static_cast<int>(vetorOrdenado.size()),
        101,
        cBinariaAusente
    );

    cout << "\nPesquisa de frequencia inexistente:\n";

    cout << "Encontrada: "
         << (posicaoAusente != -1 ? "Sim" : "Nao") << endl;

    cout << "Comparacoes: " << cBinariaAusente.comparacoes << endl;

    // PESQUISA NA ABB

    cout << "\n========== PESQUISA NA ABB ==========\n";

    int idExistente = animais.back().id;

    ContadoresPesquisa cABBEncontrado;

    bool resultadoABB = abb.buscar(
        idExistente,
        cABBEncontrado
    );

    cout << "ID procurado: " << idExistente << endl;

    cout << "Encontrado: "
         << (resultadoABB ? "Sim" : "Nao") << endl;

    cout << "Comparacoes: " << cABBEncontrado.comparacoes << endl;

    ContadoresPesquisa cABBAusente;

    bool resultadoABBAusente = abb.buscar(
        -1,
        cABBAusente
    );

    cout << "\nPesquisa de ID inexistente:\n";

    cout << "Encontrado: "
         << (resultadoABBAusente ? "Sim" : "Nao") << endl;

    cout << "Comparacoes: " << cABBAusente.comparacoes << endl;
}

// ==================================================
// 4. EXECUCAO COMPLETA DOS TESTES
// ==================================================

void executarTestes(int quantidade) {

    cout << "\n\n";
    cout << "========================================\n";
    cout << "       TESTES COM " << quantidade << " ANIMAIS\n";
    cout << "========================================\n";

    vector<Animal> animais = gerarAnimais(quantidade);

    cout << "Animais gerados: " << animais.size() << endl;

    // PREPARACAO DA FILA

    Fila fila;

    for (const Animal& a : animais) {
        fila.enfileirar(a);
    }

    // PREPARACAO DA ABB

    ABB abb;

    vector<int> ids;

    for (const Animal& a : animais) {
        ids.push_back(a.id);
    }

    mt19937 geradorIds(123);
    shuffle(ids.begin(), ids.end(), geradorIds);

    for (int id : ids) {
        abb.inserir(id);
    }

    cout << "Animais na fila: " << fila.obterTamanho() << endl;
    cout << "Nos na ABB: " << abb.quantNos() << endl;
    cout << "Altura da ABB: " << abb.altura() << endl;

    // EXECUCAO DOS TESTES

    testarOrdenacao(animais);

    testarPesquisa(animais, fila, abb);
}

// ==================================================
// 5. PROGRAMA PRINCIPAL
// ==================================================

int main() {

    executarTestes(50);

    executarTestes(500);

    return 0;
}
