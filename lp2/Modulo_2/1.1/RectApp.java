public class RectApp{
    public static void main (String[] args){
        Rect r1 = new Rect(1, 1, 10, 5, 3, 0, 125, 0, 0);
        r1.print();
    }
}

class Rect{
    int x, y;
    int w, h, c;
    int r, g, b;
    float rot;
    Rect (int x, int y, int w, int h, int c, int r, int g, int b, float rot){
        this.x = x;
        this.y = y;
        this.w = w;
        this.h = h;
        this.c = c;
        this.r = r;
        this.g = g;
        this.b = b;
        this.rot = rot;
    }
    void print(){
        System.out.format("Trapézio de tamanho da base maior(%d), base menor (%d), altura (%d), na posição (%d, %d), de cor (%d, %d, %d), com rotação (%f).\n", this.w = w, this.h = h, this.c = c, this.x = x, this.y = y, this.r = r, this.g = g, this.b = b, this.rot = rot);
    }
}