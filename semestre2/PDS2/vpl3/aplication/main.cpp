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

            if (empresa->adicionar_onibus(onibus) == nullptr) {
                cout << "ERRO: onibus repetido" << endl;
                delete onibus;
            } else {
                cout << "novo onibus cadastrado" << endl;
            }
        }
        
        if (entrada == 'S') {
            string placa;
            int num_pessoas;
            cin >> placa >> num_pessoas;

            Onibus* onibus = empresa->busca_onibus(placa);
            if (onibus != nullptr) {
                if (onibus->lotacao_atual + num_pessoas <= onibus->capacidade_maxima) {
                    onibus->subir_passageiros(num_pessoas);
                    cout << "passageiros subiram com sucesso" << endl;
                } else {
                    cout << "ERRO: onibus lotado" << endl;
                }
            } else {
                cout << "ERRO: inexistente" << endl;
            }
        }

        if (entrada == 'D') {
            string placa;
            int num_pessoas;
            cin >> placa >> num_pessoas;

            Onibus* onibus = empresa->busca_onibus(placa);
            if (onibus != nullptr) {
                if (onibus->lotacao_atual - num_pessoas >= 0) {
                    onibus->descer_passageiros(num_pessoas);
                    cout << "passageiros desceram com sucesso" << endl;
                } else {
                    cout << "ERRO: faltam passageiros" << endl;
                }
            } else {
                cout << "ERRO: onibus inexistente" << endl;
            }
        }

        if (entrada == 'T') {
            string placa1, placa2;
            int num_pessoas;
            cin >> placa1 >> placa2 >> num_pessoas;

            Onibus* onibus1 = empresa->busca_onibus(placa1);
            Onibus* onibus2 = empresa->busca_onibus(placa2);
            if (onibus1 != nullptr && onibus2 != nullptr) {
                if (onibus1->lotacao_atual - num_pessoas >= 0 && onibus2->lotacao_atual + num_pessoas <= onibus2->capacidade_maxima) {
                    onibus1->transfere_passageiros(onibus2, num_pessoas);
                    cout << "transferencia de passageiros efetuada" << endl;
                } else {
                    cout << "ERRO: transferencia cancelada" << endl;
                }
            } else {
                cout << "ERRO: onibus inexistente" << endl;
            }
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