#include <stdio.h>
#include <math.h> 

typedef struct {
    double comprimentoSepala, larguraSepala, comprimentoPetala, larguraPetala;
    char tipo[50];
} Iris;

void classificar(Iris nao_identificada, Iris registros_identificados[], int n);

float calcularDistancia(Iris a, Iris b);

int main() {
    int n;
    scanf("%d", &n);

    Iris vect[n ];

    for (int i = 0; i < n; i++) {
        Iris newIris;
        scanf("%lf %lf %lf %lf %s", &newIris.comprimentoSepala, &newIris.larguraSepala, &newIris.comprimentoPetala, &newIris.larguraPetala, newIris.tipo);
        vect[i] = newIris;
    }

    Iris naoIdentificada;
    scanf("%lf %lf %lf %lf", &naoIdentificada.comprimentoSepala, &naoIdentificada.larguraSepala, &naoIdentificada.comprimentoPetala, &naoIdentificada.larguraPetala);

    classificar(naoIdentificada, vect, n);
}

float calcularDistancia(Iris a, Iris b) {
    return sqrt(pow(a.comprimentoSepala - b.comprimentoSepala, 2) +
                pow(a.larguraSepala - b.larguraSepala, 2) +
                pow(a.comprimentoPetala - b.comprimentoPetala, 2) +
                pow(a.larguraPetala - b.larguraPetala, 2));
}

void classificar(Iris nao_identificada, Iris registros_identificados[], int n) {
    int indice_menor_distancia = 0;
    float menor_distancia = calcularDistancia(nao_identificada, registros_identificados[0]);

    for (int i = 1; i < n; i++) {
        float distancia_atual = calcularDistancia(nao_identificada, registros_identificados[i]);
        if (distancia_atual < menor_distancia) {
            menor_distancia = distancia_atual;
            indice_menor_distancia = i;
        }
    }

    printf("%s\n", registros_identificados[indice_menor_distancia].tipo);
}