#include <stdio.h>
#include <math.h> // include the -lm flag in gcc

float inputf(const char* query) {
    float res;

    printf("Enter %s: ", query);
    scanf("%f", &res);

    return res;
}

int main(void) {
    puts("f(x) = ax^2 + bx + c");
    puts("dt = b^2 - 4ac");
    puts("x1 = (-b - sqrt(dt)) / 2a");
    puts("x2 = (-b + sqrt(dt)) / 2a");
    puts("");

    float a = inputf("a");
    float b = inputf("b");
    float c = inputf("c");

    puts("");

    float dt = pow(b, 2) - 4 * a * c;
    float sqDt = sqrt(dt);

    float x1 = (-b - sqDt) / 2 * a;
    float x2 = (-b + sqDt) / 2 * a;
    
    printf("delta: %f \n", dt);
    printf("sqrt(delta): %f \n", sqDt);
    printf("x1: %f \n", x1);
    printf("x2: %f \n", x2);
    
    return 0;
}