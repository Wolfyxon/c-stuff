#include <stdio.h>

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

    return 0;
}