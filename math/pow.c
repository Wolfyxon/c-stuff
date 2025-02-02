#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if(argc != 3) {
        puts("Usage: <number> <power>");
        return 1;
    }

    int n = atoi(argv[1]);
    int power = atoi(argv[2]);

    int res = n;

    for(int i = 0; i < power - 1; i++) {
        res *= n;
    }

    printf("%i \n", res);
}