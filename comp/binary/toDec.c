#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if(argc != 2) {
        puts("Usage: <binary number>");
        return 1;
    }

    int binary = atoi(argv[1]);
    int decimal = 0;

    int base = 1;
    
    while (binary) {
        int last = binary % 10;

        binary /= 10;
        decimal += last * base;

        base *= 2;
    }
    
    printf("%i \n", decimal);
}