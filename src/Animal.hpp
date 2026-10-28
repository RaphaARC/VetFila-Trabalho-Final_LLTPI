#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
using namespace std;

struct Animal {
    int id; // ID do animal
    string nome; // Nome do animal
    string especie; // Espécie do animal
    string raca; // Raça do animal
    int idade; // Idade do animal
    string nomeTutor; // Nome do tutor
    string telefoneTutor; // Telefone do tutor
    int frequenciaVisitas; // Frequência de visitas
};

#endif // ANIMAL_HPP 