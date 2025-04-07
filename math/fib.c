#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: <length> \n");
        return 1;
    }

    int len = atoi(argv[1]);
    
    int fib = 0;
    int prev = 0;
    int next = 1;

    for(int i = 0; i < len; i++) {
        fib = prev + next;
        
        prev = next;
        next = fib;

        printf("%i ", fib);
    }

    puts("");
}