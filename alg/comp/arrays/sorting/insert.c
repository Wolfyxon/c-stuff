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

    for(int i = 1; i < len; i++) {
        int current = array[i];
        int j = i - 1;

        while(j >= 0 && array[j] > current) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = current;
    }

    for(int i = 0; i < len; i++) {
        printf("%i ", array[i]);
    }

    puts("");
}