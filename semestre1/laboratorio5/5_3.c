#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[50];
    char brand[50];
    float price;
} Product;


int main() {
    Product produtos[8];
    char marcas_unicas[8][50];
    int contagem_marcas[8] = {0};
    float soma_precos_marcas[8] = {0.0};
    int num_marcas_unicas = 0;
    float soma_total = 0.0;
    int i, j, encontrado;

    for (i = 0; i < 8; i++) {
        scanf("%s %s %f", produtos[i].name, produtos[i].brand, &produtos[i].price);
        soma_total += produtos[i].price;

        encontrado = 0;
        for (j = 0; j < num_marcas_unicas; j++) {
            if (strcmp(produtos[i].brand, marcas_unicas[j]) == 0) {
                contagem_marcas[j]++;
                soma_precos_marcas[j] += produtos[i].price;
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            strcpy(marcas_unicas[num_marcas_unicas], produtos[i].brand);
            contagem_marcas[num_marcas_unicas] = 1;
            soma_precos_marcas[num_marcas_unicas] = produtos[i].price;
            num_marcas_unicas++;
        }
    }

    for (i = 0; i < num_marcas_unicas; i++) {
        printf("%s %d\n", marcas_unicas[i], contagem_marcas[i]);
    }

    printf("media total %.2f\n", soma_total / 8);

    for (i = 0; i < num_marcas_unicas; i++) {
        printf("media %s %.2f\n", marcas_unicas[i], soma_precos_marcas[i] / contagem_marcas[i]);
    }

    return 0;
}