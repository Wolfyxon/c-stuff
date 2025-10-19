#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(int argc, char* argv[]) {
    if(argc < 3) {
        fprintf(stderr, "Usage: <radius> <triangle angle> \n");
        exit(1);
    }

    float radius = atof(argv[1]);
    float angle = atof(argv[2]);

    float archNoPi = (angle / 360) * 2 * radius;
    float trimAreaNoPi = (angle / 360) * pow(radius, 2);

    printf("Arch l = (alpha / 360) * 2 * pi * 2 = %f pi \n", archNoPi); 
    printf("Trim area P = (alpha / 360) * pi * r^2 = %f pi \n", trimAreaNoPi);
}
