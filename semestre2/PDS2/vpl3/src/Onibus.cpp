#include "../include/Onibus.hpp"
#include <iostream>

Onibus::Onibus() {
    this->placa = "";
    this->capacidade_maxima = 0;
    this->lotacao_atual = 0;
}

Onibus::Onibus(string placa, int capacidade_maxima) {
    this->placa = placa;
    this->capacidade_maxima = capacidade_maxima;
}

Onibus::~Onibus() {
}

void Onibus::subir_passageiros(int quantidade) {
    this->lotacao_atual += quantidade;
}

void Onibus::descer_passageiros(int quantidade) {
    this->lotacao_atual -= quantidade;
}

void Onibus::transfere_passageiros(Onibus* outro_onibus, int quantidade) {
    this->descer_passageiros(quantidade);
    outro_onibus->subir_passageiros(quantidade);
}

void Onibus::imprimir_estado() {
    cout << this->placa << "(" << this->lotacao_atual << "/" << this->capacidade_maxima << ")" << endl;
}
