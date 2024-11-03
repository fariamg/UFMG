#include <stdio.h>
#include <stdlib.h>

void readVect(int *vect, int size);

int main() {
    int n;
    scanf("%d", &n);

    int *p;
    p = (int *) malloc(n * sizeof(int));
    if(p == NULL) 
        return 1;
    
    readVect(p, n);

    for (int i = 0; i < n; i++) {
        printf("%d\n", p[i]);
    }
    printf("\n");

    free(p);

    return 0;
}

void readVect(int *vect, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &vect[i]);
    }
}