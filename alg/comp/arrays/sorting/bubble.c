#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("Enter at least 2 numbers in command line args \n");
        return 1;
    }

    int len = argc - 1;
    int array[len];

    for(int i = 1; i < argc; i++) {
        array[i - 1] = atoi(argv[i]);
    }

    bool ok = false;

    while(!ok) {
        ok = true;

        for(int i = 1; i < len; i++) {
            int last = array[i - 1];
            int curr = array[i];

            if(last < curr) {
                array[i - 1] = curr;
                array[i] = last;

                ok = false;
            }
        }
    }

    for(int i = 0; i < len; i++) {
        printf("%i ", array[i]);
    }

    puts("");
}