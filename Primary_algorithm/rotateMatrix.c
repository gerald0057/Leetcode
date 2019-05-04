#include <stdio.h>
#define SIZE 3

void swapINT(int* numA, int* numB){
    if (numA != numB){
        *numA += *numB;
        *numB = *numA - *numB;
        *numA = *numA - *numB;
    }    
}

void rotate(int (*matrix)[SIZE], int matrixRowSize, int *matrixColSizes) {
    int i = 0, j = 0;

    for (i = 0; i < matrixRowSize; ++i)
        for (j = i; j < *matrixColSizes; ++j)
            swapINT(&matrix[i][j], &matrix[j][i]);

    for (i = 0; i < matrixRowSize; ++i)
        for (j = 0; j < *matrixColSizes / 2; ++j)
            swapINT(&matrix[i][j], &matrix[i][*matrixColSizes - 1 - j]);
}

int main(void){
    int size = SIZE;
    int mat[SIZE][SIZE] = {0};

    int i = 0, j = 0;
    for (; i < size;  ++i)
        for (j = 0; j < size; ++j)
            mat[i][j] = i * size + j + 1;
    
    rotate(mat, size, &size);

    for (i = 0; i < size;  ++i){
        for (j = 0; j < size; ++j)
            printf("%2d ", mat[i][j]);
        printf("\n");
    }

    return 0;
}
