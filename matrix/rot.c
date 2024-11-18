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



    puts("");
}

void printMatrix(int matrix[SIZE]) {
    for(int i = 0; i < LEN; i++) {
        printf("%i ", matrix[i]);

        if(i % SIZE == 0) puts("");
    }
}