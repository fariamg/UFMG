#pragma once
#include "Onibus.hpp"

struct Empresa {
    int total_onibus;
    Onibus* onibus[20];

    Empresa();
    ~Empresa();
    Onibus* adicionar_onibus(const Onibus* onibus);
    Onibus* busca_onibus(string placa);
    void imprimir_estado();
};