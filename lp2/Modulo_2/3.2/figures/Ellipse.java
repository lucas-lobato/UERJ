package figures;

import java.awt.*;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Ellipse2D.Double;


public class Ellipse{
    int x, y;
    int w, h;
    int r, g, b;
    
    public Ellipse (int x, int y, int w, int h, int r, int g, int b){
        this.x = x;
        this.y = y;
        this.w = w;
        this.h = h;
        this.r = r;
        this.g = g;
        this.b = b;
       
    }

    public void print(){
        System.out.format("Ellipse de tamanho (%d, %d), na posição (%d, %d))\n", this.w, this.h, this.x, this.y);
    }

    public void paint(Graphics g){
        Graphics2D g2d = (Graphics2D) g;
        g2d.draw(new Ellipse2D.Double(this.x,this.y,this.w,this.h));
        g.setColor(new Color(this.r,this.g,this.b));
        g2d.fill(new Ellipse2D.Double(this.x,this.y,this.w,this.h));
    }
}