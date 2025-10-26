#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define NONE __FLT_MAX__
#define PI 3.14159265358979323846

float deg2rad(float deg) {
    return deg * PI / 180;
}

float sinDeg(float deg) {
    return sin(deg2rad(deg));
}

float getNum(char** argv, size_t index) {
    char* arg = argv[index];

    if(strcmp(arg, "x") == 0) {
        return NONE;
    }

    return atof(arg);
}

void solveAngles(float* anglePtrs[3]) {
    size_t unknownCount = 0;
    float* unknownPtr;
    
    float knownSum = 0;

    for(size_t i = 0; i < 3; i++) {
        float* ptr = anglePtrs[i];;
        float angle = *ptr;

        if(angle == NONE) {
            unknownPtr = ptr;
            unknownCount++;
        } else {
            knownSum += angle;
        }
    }

    if(unknownCount == 0) {
        return;
    }

    if(unknownCount > 1) {
        fprintf(stderr, "Only 1 angle can be unknown");
        exit(1);
    }

    *unknownPtr = 180 - knownSum;
}

float solveEdgeFromGammaC(float c, float gamma, float neighborAngle) {
    return (c * sinDeg(neighborAngle)) / sinDeg(gamma);
}

void main(int argc, char** argv) {
    if(argc != 7) {
        fprintf(stderr, "Usage: <a> <b> <c> <alpha> <gamma> <beta> \n");
        fprintf(stderr, "Use 'x' to mark a value as unknown (it will be solved) \n");
        exit(1);
    }

    // Edges
    float a = getNum(argv, 1);
    float b = getNum(argv, 2);
    float c = getNum(argv, 3);

    // Angles
    float alpha = getNum(argv, 4);
    float beta = getNum(argv, 5);
    float gamma = getNum(argv, 6);
    
    // Solving stuff

    float* angles[3] = {&alpha, &beta, &gamma};
    solveAngles(angles);

    // TODO: Understand the black trigonometry magic and add more cases
    if(c != NONE) {
        if(a == NONE) {
            a = solveEdgeFromGammaC(c, gamma, alpha);
        }

        if(b == NONE) {
            b = solveEdgeFromGammaC(c, gamma, beta);
        }
    }

    // Results
    printf("- Edges: - \n");
    printf("a: %f \n", a);
    printf("b: %f \n", b);
    printf("c: %f \n", c);
    
    printf("- Angles: - \n");
    printf("Alpha: %f \n", alpha);
    printf("Beta: %f \n", beta);
    printf("Gamma: %f \n", gamma);
    
}
