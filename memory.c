#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int direc_x;
    int direc_y;
    int x; //j
    int y; //i
} ANT;

static ANT memory[MAX_SIZE];
static int top = 0;

/*>helping functions*/ 
    int is_Empty() {
        if (top == 0) {
            return 1;
        } else {
            return 0;
        }

    }

    int is_Full() {
        if(top == MAX_SIZE) {
            return 1;
        } else {
            return 0;
        }
    }

/*>memory functions*/ 
    ANT peek() {
        if (!is_Empty()) {
            return memory[top-1];
        } else {
            printf("stack is empty\n");
        }
    }

    void push(ANT pos) {
        if(!is_Full()){
            memory[top] = pos;
            top++;
        } else {
            printf("stack is full\n");
        }
    }

    void pop() {
        //peek(); return whats pop
        if(!is_Empty()) {
            top--;
        }
    }

    void clear() {
        top = 0;
    }









