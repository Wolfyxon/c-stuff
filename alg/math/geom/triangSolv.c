#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define NONE __FLT_MAX__
#define PI 3.14159265358979323846

#define ALPHA "\u03b1"
#define BETA "\u03b2"
#define GAMMA "\u03b3"

float deg2rad(float deg) {
    return deg * PI / 180;
}

float sinDeg(float deg) {
    return sin(deg2rad(deg));
}

char getEdgeChar(size_t i) {
    switch(i) {
        case 0:
            return 'a';
        case 1:
            return 'b';
        case 2:
            return 'c';
    }
}

char* getAngleChar(size_t i) {
    switch(i) {
        case 0:
            return ALPHA;
        case 1:
            return BETA;
        case 2:
            return GAMMA;
    }
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
    size_t unknownIndex;
    
    size_t knownIndex1 = 999;
    size_t knownIndex2 = 999;
    
    float knownSum = 0;

    for(size_t i = 0; i < 3; i++) {
        float* ptr = anglePtrs[i];;
        float angle = *ptr;

        if(angle == NONE) {
            unknownIndex = i;
            unknownCount++;
        } else {
            knownSum += angle;

            if(knownIndex1 == 999) {
                knownIndex1 = i;
            } else {
                knownIndex2 = i;
            }
        }
    }

    if(unknownCount == 0) {
        return;
    }

    if(unknownCount > 1) {
        fprintf(stderr, "Only 1 angle can be unknown");
        exit(1);
    }

    float result = 180 - knownSum;

    printf(
        "%s = 180 - %s - %s = 180 - %f - %f = 180 - %f = %f \n", 
        getAngleChar(unknownIndex), getAngleChar(knownIndex1), getAngleChar(knownIndex2),
        *anglePtrs[knownIndex1], *anglePtrs[knownIndex2],
        knownSum,
        result
    );

    *anglePtrs[unknownIndex] = result;
}

float solveEdgeFromGammaC(float c, float gamma, float neighborAngle, size_t index) {
    char edgeChar = getEdgeChar(index);
    char* angleChar = getAngleChar(index);

    float sinAng = sinDeg(neighborAngle);
    float sinGam = sinDeg(gamma);
    float top = c * sinAng;
    float result = top / sinGam;

    printf(
        "%c = (c * sin %s) / (sin %s) = (%f * sin %f) / (sin %f) = (%f) / (%f) = %f \n", 
        edgeChar, angleChar, GAMMA,
        gamma, c, neighborAngle,
        top, sinGam,
        result
    );

    return result;
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
    
    printf("--- CALCULATIONS: --- \n");

    float* angles[3] = {&alpha, &beta, &gamma};
    solveAngles(angles);

    // TODO: Understand the black trigonometry magic and add more cases
    if(c != NONE) {
        if(a == NONE) {
            a = solveEdgeFromGammaC(c, gamma, alpha, 0);
        }

        if(b == NONE) {
            b = solveEdgeFromGammaC(c, gamma, beta, 1);
        }
    }

    printf("\n--- RESULTS: --- \n");

    printf("- Edges: - \n");
    printf("a: %f \n", a);
    printf("b: %f \n", b);
    printf("c: %f \n", c);
    
    printf("- Angles: - \n");
    printf("%s: %f \n", ALPHA, alpha);
    printf("%s: %f \n", BETA, beta);
    printf("%s: %f \n", GAMMA, gamma);
    
}
