#include <stdio.h>
#include <stdbool.h>
#include <math.h>

enum Function {
    SQUARE
};

float inputf(const char* query) {
    float res;

    printf("Enter %s: ", query);
    scanf("%f", &res);

    return res;
}

bool square(float x, float y) {
    return false;
}

int main(void) {

    char* names[1] = {
        "Square"
    };
    
    for(int i = 0; i < sizeof(names) / sizeof(char*); i++) {
        printf("%i. %s \n", i + 1, names[i]);
    }

    printf("Enter function type: ");

    int func;
    scanf("%i", &func);
    func--;

    puts("Enter the point:");
    float x = inputf("x");
    float y = inputf("y");
    
}