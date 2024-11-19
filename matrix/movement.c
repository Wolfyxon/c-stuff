#include <stdio.h>
#include <curses.h> // Make sure to include the -lncurses flag

const int SIZE = 8;

int main(void) {    
    int map[SIZE * SIZE];

    int x = SIZE / 2;
    int y = SIZE / 2;

    while(1) {
        initscr();

        addstr("Controls:\n");
        addstr("  wasd - move\n");
        addstr("  x    - exit\n");
        
        char inp = getch();
        
        endwin();

        if(inp == -1) continue;

        switch (inp) {
            case 'x':
                puts("Bye");
                return 0;
        }

        clear();
    }
}
