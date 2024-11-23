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
    float a = inputf("a");
    float b = inputf("b");
    float c = inputf("c");
    
    return (a * pow(x, 2) + b * x + c) == y;
}

int main(void) {

    char* names[1] = {
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

    bool res;

    switch (func) {
        case SQUARE:
            res = square(x, y);
            break;
    }

    if(res) {
        puts("Belongs");
    } else {
        puts("Does not belong");
    }
    
}