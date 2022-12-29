public class RectApp{
    public static void main (String[] args){
        Rect r1 = new Rect(1, 1, 10, 10, 0, 125, 0, 0);
        r1.print();
        r1.area();
        r1.drag(1,1);
    }
}

class Rect{
    int x, y;
    int w, h;
    int r, g, b;
    float rot;
    Rect (int x, int y, int w, int h, int r, int g, int b, float rot){
        this.x = x;
        this.y = y;
        this.w = w;
        this.h = h;
        this.r = r;
        this.g = g;
        this.b = b;
        this.rot = rot;
    }

    void print(){
        System.out.format("Retangulo de tamanho (%d, %d), na posição (%d, %d), de cor (%d, %d, %d), com rotação (%f)\n", this.w = w, this.h = h, this.x = x, this.y = y, this.r = r, this.g = g, this.b = b, this.rot = rot);
    }

    void area(){
        int a;
        a = this.w * this.h;
        System.out.println("Area do retangulo = " + a);
    }

    void drag(int dx, int dy){
        int valor = dx + 10;
        int valor2 = dy + 10;
        System.out.println("Retangulo movido para a posição ( " + valor + "," + valor2 + " )");
    }
}