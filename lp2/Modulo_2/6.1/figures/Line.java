package figures;

import javax.swing.*;
import java.awt.*;
import java.awt.geom.Line2D;

public class Line extends Figure{
    int x, y;
    int w, h;

    public Line(int x, int y, int w, int h){
        this.x = x;
        this.y = y;
        this.w = w;
        this.h = h;
    }

    public void print(){
        System.out.format("Reta de tamanho (%d, %d) na posição (%d, %d).\n", this.x = x, this.y = y, this.w = w, this.h = h);
    }

    public void paint(Graphics g){
        Graphics2D g2d = (Graphics2D) g;
        g2d.draw(new Line2D.Double(this.x, this.y, this.w, this.h));
    }
}