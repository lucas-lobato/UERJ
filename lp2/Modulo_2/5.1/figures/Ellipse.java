package figures;

import java.awt.*;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Ellipse2D.Double;
import java.util.Random;


public class Ellipse{
    int x, y;
    int w, h;
    
    public Ellipse (int x, int y, int w, int h){
        this.x = x;
        this.y = y;
        this.w = w;
        this.h = h;
       
    }

    public void print(){
        System.out.format("Ellipse de tamanho (%d, %d), na posição (%d, %d))\n", this.w, this.h, this.x, this.y);
    }

    public void paint(Graphics g){

        Random rand = new Random();
        int R = rand.nextInt(255);
        int G = rand.nextInt(255);
        int B = rand.nextInt(255);

        Graphics2D g2d = (Graphics2D) g;
        g2d.draw(new Ellipse2D.Double(this.x,this.y,this.w,this.h));
        g.setColor(new Color(R,G,B));
        g2d.fill(new Ellipse2D.Double(this.x,this.y,this.w,this.h));
    }
}