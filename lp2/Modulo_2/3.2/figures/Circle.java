package figures;

import java.awt.*;

public class Circle{
    int x, y;
    int w, h;
    int r, g, b;
    
    public Circle (int x, int y, int w, int h, int r, int g, int b){
        this.x = x;
        this.y = y;
        this.w = w;
        this.h = h;
        this.r = r;
        this.g = g;
        this.b = b;
       
    }

    public void print(){
        System.out.format("Circulo de diâmetro (%d, %d), na posição (%d, %d))\n", this.w, this.h, this.x, this.y);
    }

    public void paint(Graphics g){
        g.drawOval(this.x,this.y,this.w,this.h);
        g.setColor(new Color(this.r,this.g,this.b));
        g.fillOval(this.x,this.y,this.w,this.h);
    }
}