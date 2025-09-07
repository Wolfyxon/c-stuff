// Compile: gcc -nostdlib -Wno-builtin-declaration-mismatch main.c
// TODO: Make my own std

#define NULL 0
#define SYS_WRITE 1
#define SYS_EXIT 60
#define STDOUT 1

typedef unsigned long long int uint64;

int write(int loc, char* buf, int size) {
    int result;

    asm(
        "mov %1, %%rax \n" // Syscall type
        "mov %2, %%rdi \n" // Write location
        "mov %3, %%rsi \n" // Buffer
        "mov %4, %%rdx \n" // Size
        "syscall"
        : "=r" (result)
        : "r" ((uint64) SYS_WRITE),
          "r" ((uint64) loc),
          "r" ((uint64) buf),
          "r" ((uint64) size)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );

    return result;
}

int strlen(char* str) {
    int i = 0;

    while(str[i] != NULL) {
        i++;
    }

    return i;
}

void exit(int code) {
    while(1) {
        asm (
            "mov %0, %%rax \n"
            "mov %1, %%rdi \n"
            "syscall"
            :
            : "r" ((uint64) SYS_EXIT),
              "r" ((uint64) code)
            : "%rax", "%rdi"
        );
    }
}

void print(char* str) {
    write(STDOUT, str, strlen(str));
}

void _start(void) {
    print("Hello World\n");
    exit(0);
}
