#include <stdio.h>
#include <stdbool.h>
#include <math.h>

enum Function {
    LINEAR,
    SQUARE
};

float inputf(const char* query) {
    float res;

    printf("Enter %s: ", query);
    scanf("%f", &res);

    return res;
}

float linear(float x) {
    float a = inputf("a");
    float b = inputf("b");

    return a * x + b;
}

float square(float x) {
    float a = inputf("a");
    float b = inputf("b");
    float c = inputf("c");
    
    return a * pow(x, 2) + b * x + c;
}

int main(void) {

    char* names[2] = {
        "Linear",
        "Square"
    };
    
    int namesLen = sizeof(names) / sizeof(char*);

    for(int i = 0; i < sizeof(names) / sizeof(char*); i++) {
        printf("%i. %s \n", i + 1, names[i]);
    }

    printf("Enter function type: ");

    int func;
    scanf("%i", &func);
    func--;

    if(func < 0 || func >= namesLen) {
        puts("Unknown function type");
        return main();
    }

    puts("Enter the point:");
    float x = inputf("x");
    float y = inputf("y");

    float res;

    switch (func) {
        case LINEAR:
            res = linear(x);
            break;

        case SQUARE:
            res = square(x);
            break;
    }

    if(res == y) {
        puts("Belongs");
    } else {
        puts("Does not belong");
        printf("f(%f) == %f \n", x, res);
    }
    
}