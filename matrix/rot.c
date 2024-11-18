#include <stdio.h>
#include <math.h>

const size_t SIZE = 3;
const size_t LEN = SIZE * SIZE;

int main(void) {
    int matrix[LEN];

    printf("Enter a %ix%i matrix:\n", SIZE);

    for(int i = 0; i < SIZE; i++) {
        scanf("%i %i %i", &matrix[i] + 0, &matrix[i] + 1, &matrix[i] + 2);
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