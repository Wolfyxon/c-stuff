#include <stdio.h>

const size_t SIZE = 3;
const size_t LEN = SIZE * SIZE;

int main(void) {
    int matrix[LEN];

    printf("Enter a %ix%i matrix:\n", SIZE);

    for(int i = 0; i < LEN; i++) {
        scanf("%i", &matrix[i]);
    }

    for(int i = 0; i < SIZE; i++) {
        int sum = 0;
        
        for(int ii = 0; ii < SIZE; ii++) {
            sum += matrix[ (ii * SIZE) + ((i + ii) % SIZE) ];
        }

        printf("%i: %i\n", i + 1, sum);
    }

    return 0;
}