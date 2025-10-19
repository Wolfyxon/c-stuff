#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
    float radius;
} Circle;

Circle newCircle(float x, float y, float radius) {
    Circle circ = {
        .x = x,
        .y = y,
        .radius = radius
    };
    
    return circ;
}

void main(int argc, char* argv[]) {
    if(argc < 7) {
        fprintf(stderr, "Usage: <x1> <y1> <radius1>  <x2, y2> <radius2> \n");
        exit(1);
    }
    
    Circle circ1 = newCircle(atof(argv[1]), atof(argv[2]), atof(argv[3]));
    Circle circ2 = newCircle(atof(argv[4]), atof(argv[5]), atof(argv[6]));
    
    float dist = sqrt(pow(circ2.x - circ1.x, 2) + pow(circ2.y - circ1.y, 2));
    printf("Distance d = sqrt((x2 - x1) + (y2 - y1)) = %f \n\n", dist);

    float rSum = abs(circ1.radius + circ2.radius);
    float rSub = abs(circ1.radius - circ2.radius);
    float rSubRev = abs(circ2.radius - circ1.radius);

    // TODO: English translation
    if(dist == rSum) {
        printf("Styczne zewnętrznie, because: \n");
        printf("|r1 + r2| = d \n");
        printf("|%f + %f| = %f \n", circ1.radius, circ2.radius, dist);
        return;
    }

    if(dist == rSub) {
        printf("Styczne wewnętrznie, because: \n");
        printf("|r1 - r2| = d \n");
        printf("|%f - %f| = %f \n", circ1.radius, circ2.radius, dist);
        return;
    }

    if(rSubRev < dist < rSum) {
        printf("Przecinające się, because: \n");
        printf("|r2 - r1| < d < |r1 + r2| \n");
        printf("|%f - %f| < %f < |%f + %f| \n", circ2.radius, circ1.radius, dist, circ1.radius, circ2.radius);
        printf("%f < %f < %f \n", rSubRev, dist, rSum);
        
        return;
    }

    printf("The circles are not touching. \n");
}

