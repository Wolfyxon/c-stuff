#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if(argc != 2) {
        puts("Usage: <decimal number>");
        return 1;
    }

    int decimal = atoi(argv[1]);
    
    int len = 0;
    int binary[64];

    for(len; decimal; len++) {
        binary[len] = decimal % 2;
        decimal /= 2;
    }

    for(int i = 0; i < len; i++) {
        printf("%i", binary[len - i - 1]);
    }

    puts("");
    
}