#include <stdio.h>
#include <stdlib.h>
#include "rect.h"

typedef struct Rect {
    int x;
    int y;
    int w;
    int h;
} Rect;

Rect* rect_new(void){
    Rect* this = malloc(sizeof(Rect));
    int x = 0;
    int y = 0;
    int w = 10;
    int h = 20;

    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    return this;
}

void rect_drag(Rect* this, int dx, int dy){
    this->x = dx;
    this->y = dy;
}

void rect_print(Rect* this) {
    printf("RECT (%d, %d) (%d, %d).\n",
        this->x, this->y, this->w, this->h);
}