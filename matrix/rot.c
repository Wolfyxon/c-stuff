#include <stdio.h>
#include <math.h>

const size_t SIZE = 3;
const size_t LEN = SIZE * SIZE;

void printMatrix(int matrix[SIZE]);

int main(void) {
    int matrix[LEN];

    printf("Enter a %ix%i matrix:\n", SIZE);

    for(int i = 0; i < LEN; i++) {
        scanf("%i", &matrix[i]);
    }

    puts("Rotated 90* clockwise:");

    int matrix_90cw[LEN];

    // Transposition - swapping columns and rows
    for(int col = 0; col < SIZE; col++) {
        for(int row = 0; row < SIZE; row++) {
            matrix_90cw[row * SIZE + col] = matrix[col * SIZE + row]; 
        }
    }
    
    printMatrix(matrix_90cw);

    puts("");
}

void printMatrix(int matrix[SIZE]) {
    for(int i = 0; i < LEN; i++) {
        printf("%i ", matrix[i]);

        if((i + 1) % SIZE == 0) puts("");
    }
}