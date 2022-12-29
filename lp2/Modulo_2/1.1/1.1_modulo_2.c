#include <stdio.h>

typedef struct
{
    int x, y;
    int w, h;
    int rr, g, b;
    float rot;
} Rect;


void print(Rect* r){
    printf("Retangulo de tamanho (%d, %d), na posição (%d, %d), de cor (%d, %d, %d), com rotação (%0.2f).\n", r -> w, r -> h, r -> x, r -> y, r -> rr, r -> g, r -> b, r -> rot);
}


void main(void){
    Rect r1 = {1,1,10,10,0,128,0,45};
    print(&r1);
}