import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Ellipse2D.Double;

class EllipseApp{
    public static void main(String[] args){
        EllipseFrame frame = new EllipseFrame();
        frame.setVisible(true);
    }
}

class EllipseFrame extends JFrame {
    Ellipse e1;
    Ellipse e2;
    Ellipse e3;

    EllipseFrame(){
        this.addWindowFocusListener(
            new WindowAdapter(){
                public void windowClosing (WindowEvent e){
                    System.exit(0);
                }
            }
        );
        this.setTitle("Ellipses");
        this.setSize(350,350);
        this.e1 = new Ellipse(50,50,100,30,0,255,0);
        this.e2 = new Ellipse(50,100,100,30,0,0,255);
        this.e3 = new Ellipse(175,50,30,80,255,0,0);
    }

    public void paint(Graphics g){
        super.paint(g);
        this.e1.paint(g);
        this.e2.paint(g);
        this.e3.paint(g);
    }
}

class Ellipse{
    int x, y;
    int w, h;
    int r, g, b;
    
    Ellipse (int x, int y, int w, int h, int r, int g, int b){
        this.x = x;
        this.y = y;
        this.w = w;
        this.h = h;
        this.r = r;
        this.g = g;
        this.b = b;
       
    }

    void print(){
        System.out.format("Ellipse de tamanho (%d, %d), na posição (%d, %d))\n", this.w, this.h, this.x, this.y);
    }

    void paint(Graphics g){
        Graphics2D g2d = (Graphics2D) g;
        g2d.draw(new Ellipse2D.Double(this.x,this.y,this.w,this.h));
        g.setColor(new Color(this.r,this.g,this.b));
        g2d.fill(new Ellipse2D.Double(this.x,this.y,this.w,this.h));
    }
}