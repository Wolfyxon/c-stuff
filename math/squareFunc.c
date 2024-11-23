#include <stdio.h>

float inputf(const char* query) {
    float res;

    printf("Enter %s: ", query);
    scanf("%f", &res);

    return res;
}

int main(void) {
    puts("f(x) = ax^2 + bx + c");

    float a = inputf("a");
    float b = inputf("b");
    float c = inputf("c");

    puts("");

    return 0;
}