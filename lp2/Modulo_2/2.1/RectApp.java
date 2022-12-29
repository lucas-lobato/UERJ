import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class RectApp{
    public static void main(String[] args){
        RectFrame frame = new RectFrame();
        frame.setVisible(true);
    }
}

class RectFrame extends JFrame {
    Rect r1;
    Rect r2;
    Rect r3;

    RectFrame(){
        this.addWindowFocusListener(
            new WindowAdapter(){
                public void windowClosing (WindowEvent e){
                    System.exit(0);
                }
            }
        );
        this.setTitle("Rects");
        this.setSize(350,350);
        this.r1 = new Rect(50,50,100,30,0,255,0);
        this.r2 = new Rect(50,100,100,30,0,0,255);
        this.r3 = new Rect(175,50,30,80,255,0,0);
    }

    public void paint(Graphics g){
        super.paint(g);
        this.r1.paint(g);
        this.r2.paint(g);
        this.r3.paint(g);
    }
}

class Rect{
    int x, y;
    int w, h;
    int r, g, b;
    
    Rect (int x, int y, int w, int h, int r, int g, int b){
        this.x = x;
        this.y = y;
        this.w = w;
        this.h = h;
        this.r = r;
        this.g = g;
        this.b = b;
       
    }

    void print(){
        System.out.format("Retangulo de tamanho (%d, %d), na posição (%d, %d))\n", this.w, this.h, this.x, this.y);
    }

    void paint(Graphics g){
        g.drawRect(this.x,this.y,this.w,this.h);
        g.setColor(new Color(this.r,this.g,this.b));
        g.fillRect(this.x + 1,this.y + 1,this.w - 1,this.h - 1);
    }
}