#include <stdio.h>

void print(int vect[], int n);

void multiply(int vect[], int n, double v);

int main() {
    int n;
    scanf("%d", &n);

    int vect[n];

    for (int i = 0; i < n; i++) {
        int number;
        scanf("%d", &number);

        vect[i] = number;
    }

    int v; 
    scanf("%d", &v);

    print(vect, n);

    multiply(vect, n, v);

    print(vect, n);

    multiply(vect, n, 1.0/v);

    print(vect, n);
}

void multiply(int vect[], int n, double v) {
    for (int i = 0; i < n; i++) {
        vect[i] = vect[i] * v;
    }
}

void print(int vect[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vect[i]);
    }
    printf("\n");
}