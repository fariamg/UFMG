#include "../include/Empresa.hpp"

Empresa::Empresa() {
    this->total_onibus = 0;
    for (int i = 0; i < 20; i++) 
        this->onibus[i] = nullptr;
}

Empresa::~Empresa() {
    for (int i = 0; i < 20; i++) {
        delete this->onibus[i];
    }
}

Onibus* Empresa::adicionar_onibus(const Onibus* onibus) {
    for (int i = 0; i < total_onibus; ++i) {
        if (this->onibus[i] != nullptr && this->onibus[i]->placa == onibus->placa)
            return nullptr;
    }
    if (total_onibus < 20) {
        this->onibus[total_onibus] = new Onibus(onibus->placa, onibus->capacidade_maxima); 
        total_onibus++;
        return this->onibus[total_onibus - 1];
    }
    return nullptr; 
}

Onibus* Empresa::busca_onibus(const string placa) {
    for (int i = 0; i < total_onibus; ++i) {
        if (this->onibus[i] != nullptr && this->onibus[i]->placa == placa)
            return this->onibus[i];
    }
    return nullptr; 
}

void Empresa::imprimir_estado() {
    for (int i = 0; i < this->total_onibus; i++) {
        if (this->onibus[i] != nullptr) {
            this->onibus[i]->imprimir_estado();
        }
    }
}
