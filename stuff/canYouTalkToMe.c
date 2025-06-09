#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int choice(char* options[]) {
    size_t len = 0;

    while(options[len] != NULL) {
        len++;
    }
    
    for(size_t i = 0; i < len; i++) {
        printf("%i - %s\n", i + 1, options[i]);
    }

    int inp;
    
    printf("Answer: ");
    scanf("%i", &inp);

    inp--;

    if(inp < 0 || inp >= len) {
        return choice(options);
    }

    return inp;
}

bool yes_no() {
    return choice((char*[]){
        "Yes",
        "No",
        NULL
    }) == 0;
}

void print(char* text) {
    printf("%s\n", text);
}

void main() {
    print("Can you talk to me? - The guide ");
    print("If the answer is 'No', keep the talk short.");
    print("");

    print("Am I doing something?");
    if(!yes_no()) {
        printf("Yes \n");
        return;
    }

    print("Do I look focused at it?");
    if(!yes_no()) {
        print("Most likely yes");
        return;
    }

    print("What is it?");
    switch(choice((char*[]){
        "Something manual",
        "Reading a book",
        "Using the phone",
        "Using a computer",
        "Other",
        NULL
    })) {
        case 0: {
            print("Most likely yes");
            return;
        }
        case 1: {
            print("Is it a school book?");
            if(!yes_no()) {
                print("No");
                return;
            } else {
                print("Most likely yes");
                return;
            }
        }
        case 2: {
            print("Am I just scrolling?");

            if(yes_no()) {
                print("Yes");
                return;
            }

            print("Am I solving a quiz or reading something?");
            
            if(!yes_no()) {
                print("Most likely yes");
                return;
            } else {
                print("No");
                return;
            }
        }
        case 3: {
            print("Am I playing a game?");

            if(yes_no()) {
                print("Most likely yes");
                return;
            }

            print("Am I programming?");

            if(yes_no()) {
                print("Maybe");
                return;
            }

            print("Am I researching something?");

            if(yes_no()) {
                print("Probably not");
                return;
            }

            print("Am I violently typing commands?");

            if(yes_no()) {
                print("DO NOT");
                return;
            }

            print("Most likely yes");
        }
        case 4: {
            print("Most likely yes");
            return;
        }
    }
}
