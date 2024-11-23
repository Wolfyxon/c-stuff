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

float square(float x, float y) {
    float a = inputf("a");
    float b = inputf("b");
    float c = inputf("c");
    
    return a * pow(x, 2) + b * x + c;
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

    float res;

    switch (func) {
        case SQUARE:
            res = square(x, y);
            break;
    }

    if(res == y) {
        puts("Belongs");
    } else {
        puts("Does not belong");
        printf("f(%f) == %f \n", x, res);
    }
    
}