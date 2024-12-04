#include <stdio.h>
#define SIZE 8

/*

alkane (PL: alkan):
    C_{n} H_{2n + 2}

alkene (PL: alken):
    C_{n} H_{2n}

alkyne (PL: alkin):
    C_{n} H_{2n-2}

*/

typedef struct {
    char* plName;
    //char* name;
} Hydrocarbon;

const Hydrocarbon ALKENES[SIZE] = {
    {
        .plName = "ni mo"
    },
    {
        .plName = "eten (etylen)"
    },
    {
        .plName = "propen"
    },
    {
        .plName = "but-1-en"
    },
    {
        .plName = "pent-1-en"
    },
    {
        .plName = "heks-1-en"
    },
    {
        .plName = "hept-1-en"
    },
    {
        .plName = "okt-1-en"
    }
};

void printHc(int c, const Hydrocarbon *array) {
    int idx = c - 1;

    if(idx >= SIZE) {
        puts("Unknown hydrocarbon name");
    } else {
        const Hydrocarbon* c = &array[idx];

        printf("%s \n", c->plName);
    }
}

int main(void) {
    int c;
    int h;

    printf("C amount: ");
    scanf("%i", &c);

    printf("H amount: ");
    scanf("%i", &h);

    if(h == 2 * c + 2) {
        puts("Alkane (alkan)");

    } else if(h == 2 * c) {
        puts("Alkene (alken)");
        printHc(c, ALKENES);

    } else if(h == 2 * c - 2) {
        puts("Alkyne (alken)");

    } else {
        puts("error");
    }
}