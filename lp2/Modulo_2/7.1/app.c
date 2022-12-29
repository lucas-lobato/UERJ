#include <stdio.h>
#include <stdlib.h>

typedef struct Color {
    int r, g, b;
} Color;

typedef struct figure {
    int x, y, w, h, A;
    Color contour, fill;

    void (*print) (struct figure*);
} figure;

typedef void (*figure_print) (struct figure*);

////////////////////////////////////////

typedef struct triangle {
    figure super;
    int x;
    int y;
    int w;
    int h;
    int A;
    int array_x[3];
    int array_y[3];
} triangle;

void triangle_print(triangle* this) {
    figure* sup = (figure*) this;
    printf("Triângulo de tamanho (%d, %d) na posicao (%d, %d) e area(%d).\n",
        sup->w, sup->h, sup->x, sup->y, sup->A);
}

triangle* triangle_new(int x, int y, int w, int h) {
    triangle* this = malloc(sizeof(triangle));
    figure* sup = (figure*) this;
    sup->print = (figure_print) triangle_print;
    sup->x = x;
    sup->y = y;
    sup->w = w;
    sup->h = h;
    sup->A = (w * h)/2;

    this->array_x[0] = x;
    this->array_x[1] = x + w / 2;
    this->array_x[2] = x + w;
    
    this->array_y[0] = y + h;
    this->array_y[1] = y;
    this->array_y[2] = y + h;

    return this;
}

////////////////////////////////////////

typedef struct Ellipse {
    figure super;
    int x;
    int y;
    int w;
    int h;
    int A;
} Ellipse;

void ellipse_print(Ellipse* this) {
    figure* sup = (figure*) this;
    printf("Ellipse de tamanho (%d, %d) na posicao (%d, %d) e area(%d).\n",
        sup->w, sup->h, sup->x, sup->y, sup->A);
}

Ellipse* ellipse_new(int x, int y, int w, int h) {
    Ellipse* this = malloc(sizeof(Ellipse));
    figure* sup = (figure*) this;
    sup->print = (figure_print) ellipse_print;
    sup->x = x;
    sup->y = y;
    sup->w = w;
    sup->h = h;
    sup->A = (w/2) * (h/2) * 3.14;

    return this;
}

////////////////////////////////////////

int main () {
    figure* figs[5] = {
        (figure*) triangle_new(20, 20, 10, 10),
        (figure*) ellipse_new(0, 0, 10, 15),
        (figure*) triangle_new(10, 20, 20, 10),
        (figure*) ellipse_new(10, 10, 10, 20),
        (figure*) triangle_new(0, 0, 5, 5)
    };

    for (int i = 0; i < 5; i++) 
        figs[i]->print(figs[i]);

    for (int i = 0; i < 5; i++) 
        free(figs[i]);

    return 0;
}
