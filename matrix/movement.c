#include <stdio.h>
#include <curses.h> // Make sure to include the -lncurses flag

const int SIZE = 8;
const int LEN = SIZE * SIZE;

void moveCell(int* map, int x, int y, int dirX, int dirY) {
    int oldIdx = (SIZE * y) + x;
    int newIdx = (SIZE * ((y + dirY) % SIZE)) + ((x + dirX) % SIZE);

    int oldCell = map[oldIdx]; 
    int newCell = map[newIdx];
    
    map[oldIdx] = newCell;
    map[newIdx] = oldCell;
}

int main(void) {    
    int map[LEN];
    
    for(int i = 0; i < LEN; i++) {
        if(i == LEN / 2 + SIZE / 2) {
            map[i] = 1;
        } else {
            map[i] = 0;
        }
    }

    int x = SIZE / 2;
    int y = SIZE / 2;

    while(1) {
        initscr();

        addstr("Controls:\n");
        addstr("  wasd - move\n");
        addstr("  x    - exit\n\n");
        
        for(int iy = 0; iy < SIZE; iy++) {
            for(int ix = 0; ix < SIZE; ix++) {
                int cell = map[(iy * SIZE) + ix];
                
                char ch = '.';
                if(cell) ch = 'o';
                
                addch(ch);
                addch(' ');
            }

            addstr("\n");
        }

        char inp = getch();
        
        endwin();

        if(inp == -1) continue;

        int dirX = 0;
        int dirY = 0;

        switch (inp) {
            case 'x':
                puts("Bye");
                return 0;

            case 'a':
                dirX = -1;
                break;
        }

        moveCell(map, x, y, dirX, dirY);

        x += dirX;
        y += dirY;


        clear();
    }
}
