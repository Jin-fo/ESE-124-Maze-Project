#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "action.c"
#include "memory.c"

#define MAX_CHAR 32
#define MAX_i 64
#define MAX_j 64
// Declare MAZE structure

void check_fopen(FILE *name) {
    if (name != NULL) {
        printf("[o]File Open Successfull - %p\n", name);
    } else {
        printf("[!]NULL FILE ERROR - %p[!]", name);
        exit(1);
    }
}
//read a unkown dimension of mazes from text file into a 2-d array
void read_maze(FILE *name, MAZE maze) {
    int i=0, j, cond=1;

    while (cond) {
        // Read characters until a newline or end of file
        for (j = 0; maze.cord[i][j] != '\n'; j++) {
            if ((maze.cord[i][j] = fgetc(name)) == EOF) {
                cond = 0;
            } else {
                printf("%c", maze.cord[i][j]);
            }
        }
        
        maze.cord[i][j] = '\n';
        i++; // Move to the next row
    }
    maze.cord[i][j] = '\0';

    maze.max_i = i;
    maze.max_j = j-1;
    //printf("\n[o]reading completed (row = %d, colume = %d)\n", i, maze.max_j);
}

void update_maze(MAZE maze) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (i == ant.y && j == ant.x) {
                printf("A");
            } else {
                printf("%c", maze.cord[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n=0;
    MAZE *maze = (MAZE*)malloc(sizeof(MAZE)*n);

    ANT ant; 

    FILE *inp_maze, *inp_tell, *oup; /*open intell.txt & maze.txt>>*/{
        inp_tell = fopen("intelligent.txt", "r");
            check_fopen(inp_tell);

    /*>*/printf("[>]select maze: "); scanf("%[^ \n]s", maze[n].name); getchar();
        /*ignore .txt format*/{
         strcat(maze[n].name, ".txt");
         }
        inp_maze = fopen(maze[n].name, "r");
            check_fopen(inp_maze);
        
        oup = fopen("output.txt", "w");
    }
        printf("[o]reading... %s\n", maze[n-1].name);
            read_maze(inp_maze, maze[n-1]);
            fclose(inp_maze);

        printf("\n[>]select Ant location (i, j): "); scanf("%d %d", ant.y, ant.x); getchar();
            update_maze(maze[n-1]); /*DEBUGING: in theory it should work*/
        
    char cur_act[MAX_CHAR];

    
    while (fscanf(inp_tell, "%s", cur_act) != EOF /*&& !exit*/) {
        printf("%s", cur_act);
        if (action(cur_act, maze[n-1], ant)) {
            //fscanf(inp, "")
        }
            update_maze(maze[n-1]);
            fprintf(oup, "%s", cur_act);
    }   
    n++;
    fclose(inp_tell);
    fclose(oup);
    free(maze);
}