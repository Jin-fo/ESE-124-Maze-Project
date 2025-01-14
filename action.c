#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory.c"

#define MAX_CHAR 32
#define MAX_i 64
#define MAX_j 64
typedef struct {
    char name[MAX_CHAR];
    char cord[MAX_i][MAX_j];
    int max_i, max_j;
} MAZE;

ANT ant;
int itch;

int action(char act[], MAZE maze, ANT ant) {
    /*>>mark and memory*/{
        /*mark:
        decide to mark/remember position i.e. 'o' where it already been*/
        if(strcmp(act, "MARK")) {
            //push(/*current*/);
            /*show 'o' on maze next update*/
            maze.cord[ant.y][ant.x] = 'o';
            push(ant);
        }

        if(strcmp(act, "PUSH")) {
            push(ant);
        }   

        if(strcmp(act, "POP")) {
            pop();
        }

        if(strcmp(act, "PEEK")) {
            peek();
        }

        if(strcmp(act, "CLEAR")) {
            clear(); 
            
        }

        if(strcmp(act, "BACKTRACK")) {
        }
    }
    /*>>basic move*/{
        if(strcmp(act, "MOVE_F")) {
            ant.x++;
        }
        if(strcmp(act, "MOVE_B")) {
            ant.x--;

        }
        if(strcmp(act, "MOVE_R")) {
            ant.y++;

        }
        if(strcmp(act, "MOVE_L")) {
            ant.y--;
        }
        
    }
    /*>>check and special move*/ {
        /*check foward
        flag(if) not 'mark', return x space until wall i.e. for(!wall){if(!mark){x++}}
        */
        if(strcmp(act, "CWF")) {
            for (itch = 1; maze.cord[ant.y+itch][ant.x] == ' '; itch++);
            itch --;
            ant.direc_x = 0;
            ant.direc_y = 1;
        }
        if(strcmp(act, "CWB")) {
            for (itch = 1; maze.cord[ant.y-itch][ant.x] == ' '; itch++);
            itch --;
            ant.direc_x = 0;
            ant.direc_y = -1;
        }
        if(strcmp(act, "CWR")) {
            for (itch = 1; maze.cord[ant.y][ant.x+itch] == ' '; itch++);
            ant.direc_x = 1;
            ant.direc_y = 0;
            itch --;
            
        }
        if(strcmp(act, "CWL")) {
            for (itch = 1; maze.cord[ant.y][ant.x-itch] == ' '; itch++);
            ant.direc_x = -1;
            ant.direc_y = 0;
            itch --;
        }
        /*jump based on cw's return of x
        cautious jump*/
        if(strcmp(act, "CJPI")) {
            ant.x += ant.direc_x * itch;
            ant.y += ant.direc_y * itch;
        }
        /*bold jump*/
        if(strcmp(act, "BJPI")) {
            ant.x += ant.direc_x * itch;
            ant.y += ant.direc_y * itch;
        }
        
    }
    /*special repeat statment
    RP n t - RP(n action, t tiimes)*/
        if(strcmp(act, "RP")) {
            return 1;
        }
        
    return 0;
}

