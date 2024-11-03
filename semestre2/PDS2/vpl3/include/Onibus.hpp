#pragma once
#include <string>

using namespace std;

struct Onibus {
    string placa;
    int capacidade_maxima, lotacao_atual;   

    Onibus();
    ~Onibus();
    Onibus(string placa, int capacidade_maxima);
    void subir_passageiros(int quantidade);
    void descer_passageiros(int quantidade);
    void transfere_passageiros(Onibus* outro_onibus, int quantidade);
    void imprimir_estado();
};