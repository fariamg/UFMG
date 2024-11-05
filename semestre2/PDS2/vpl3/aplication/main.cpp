#include <iostream>
#include "../include/Onibus.hpp"
#include "../include/Empresa.hpp"

using namespace std;

int main() {
    char entrada;
    cin >> entrada;
    Empresa* empresa = new Empresa();

    while (entrada != 'F') {
        if (entrada == 'C') {
            string placa;
            int capacidade;
            cin >> placa >> capacidade;
            
            Onibus* onibus = new Onibus(placa, capacidade);

            if (!empresa->adicionar_onibus(onibus)) {
                cout << "ERRO: onibus repetido" << endl;
                delete onibus;
                continue;
            }
            
            cout << "novo onibus cadastrado" << endl;
        }

        if (entrada == 'S') {
            string placa;
            int num_pessoas;
            cin >> placa >> num_pessoas;

            Onibus* onibus = empresa->busca_onibus(placa);

            if (!onibus) {
                cout << "ERRO: onibus inexistente" << endl;
                continue;
            }

            if (onibus->lotacao_atual + num_pessoas > onibus->capacidade_maxima) 
                cout << "ERRO: onibus lotado" << endl;
                continue;
            
            onibus->subir_passageiros(num_pessoas);
            cout << "passageiros subiram com sucesso" << endl;
        }

        if (entrada == 'D') {
            string placa;
            int num_pessoas;
            cin >> placa >> num_pessoas;

            Onibus* onibus = empresa->busca_onibus(placa);

            if (!onibus) {
                cout << "ERRO: onibus inexistente" << endl;
                continue;
            }

            if (onibus->lotacao_atual - num_pessoas < 0) {
                cout << "ERRO: faltam passageiros" << endl;
                continue;
            }

            onibus->descer_passageiros(num_pessoas);
            cout << "passageiros desceram com sucesso" << endl;
        }

        if (entrada == 'T') {
            string placa1, placa2;
            int num_pessoas;
            cin >> placa1 >> placa2 >> num_pessoas;

            Onibus* onibus1 = empresa->busca_onibus(placa1);
            Onibus* onibus2 = empresa->busca_onibus(placa2);

            if (!onibus1 || !onibus2) {
                cout << "ERRO: onibus inexistente" << endl;
                continue;
            }

            if (onibus1->lotacao_atual - num_pessoas < 0 || onibus2->lotacao_atual + num_pessoas > onibus2->capacidade_maxima) {
                cout << "ERRO: transferencia cancelada" << endl;
                continue;
            }

            onibus1->transfere_passageiros(onibus2, num_pessoas);
            cout << "transferencia de passageiros efetuada" << endl;
        }

        if (entrada == 'I') {
            empresa->imprimir_estado();
        }

        if (entrada == 'F') {
            break;
        }

        cin >> entrada;
    }
    return 0;
}