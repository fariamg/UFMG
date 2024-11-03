#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, column;

    scanf("%d", &row);
    scanf("%d", &column);

    int **M = (int **) malloc(row * sizeof(int *));
    if (M == NULL) 
        return 1;
    
    for (int i = 0; i < row; i++) {
        M[i] = (int *) malloc(column * sizeof(int));
        if (M[i] == NULL) 
            return 1;
        
        for (int j = 0; j < column; j++) 
            scanf("%d", &M[i][j]);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) 
            printf("%d ", M[i][j]);
        printf("\n");
    }

    for (int i = 0; i < row; i++) 
        free(M[i]);
    free(M);

    return 0;
}