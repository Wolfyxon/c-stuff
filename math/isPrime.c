#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if(argc != 2) {
        puts("Usage: <number>");
        return 1;
    }

    int n = atoi(argv[1]);

    for(int i = 1; i < n; i++) {
        if(i != 1 && n % i == 0) {
            puts("false");
            return 0;
        }
    }

    puts("true");
}