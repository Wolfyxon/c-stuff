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
    char* name;
} Hydrocarbon;

const Hydrocarbon ALKANES[SIZE] = {
    {
        .plName = "metan",
        .name = "methane"
    },
    {
        .plName = "etan",
        .name = "ethane"
    },
    {
        .plName = "propan",
        .name = "propane"
    },
    {
        .plName = "butan",
        .name = "butane"
    },
    {
        .plName = "pentan",
        .name = "pentane"
    },
    {
        .plName = "heksan",
        .name = "hexane"
    },
    {
        .plName = "heptan",
        .name = "heptane"
    },
    {
        .plName = "oktan",
        .name = "octane"
    }
};

const Hydrocarbon ALKENES[SIZE] = {
    {
        .plName = "ni mo",
        .name = "nuh uh"
    },
    {
        .plName = "eten (etylen)",
        .name = "ethene (ethylene)"
    },
    {
        .plName = "propen",
        .name = "propene"
    },
    {
        .plName = "but-1-en",
        .name = "butene"
    },
    {
        .plName = "pent-1-en",
        .name = "pentene"
    },
    {
        .plName = "heks-1-en",
        .name = "hexene"
    },
    {
        .plName = "hept-1-en",
        .name = "heptene"
    },
    {
        .plName = "okt-1-en",
        .name = "octane"
    }
};

const Hydrocarbon ALKYNES[SIZE] = {
    {
        .plName = "ni mo",
        .name = "nuh uh"
    },
    {
        .plName = "etyn (acetylen)",
        .name = "ethyne (acetylene)"
    },
    {
        .plName = "propyn",
        .name = "propyne"
    },
    {
        .plName = "but-1-yn",
        .name = "butyne"
    },
    {
        .plName = "pent-1-yn",
        .name = "pentyne"
    },
    {
        .plName = "heks-1-yn",
        .name = "hexyne"
    },
    {
        .plName = "hept-1-yn",
        .name = "heptyne"
    },
    {
        .plName = "okt-1-yn",
        .name = "octyne"
    }
};

void printHc(int c, const Hydrocarbon *array) {
    int idx = c - 1;

    if(idx >= SIZE) {
        puts("Unknown hydrocarbon name");
    } else {
        const Hydrocarbon* c = &array[idx];

        printf("%s (%s) \n", c->name, c->plName);
    }
}

int main(void) {
    int c;
    int h;

    printf("C amount: ");
    scanf("%i", &c);

    printf("H amount: ");
    scanf("%i", &h);

    puts("");

    if(h == 2 * c + 2) {
        puts("Alkane (alkan)");
        printHc(c, ALKANES);

    } else if(h == 2 * c) {
        puts("Alkene (alken)");
        printHc(c, ALKENES);

    } else if(h == 2 * c - 2) {
        puts("Alkyne (alkin)");
        printHc(c, ALKYNES);

    } else {
        puts("error");
    }
}