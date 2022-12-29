import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import figures.*;


class PackApp{
    public static void main(String[] args){
        PackFrame frame = new PackFrame();
        frame.setVisible(true);
    }
}

class PackFrame extends JFrame {
    Rect r1;
    Ellipse e1;
    Circle c1;

    PackFrame(){
        this.addWindowFocusListener(
            new WindowAdapter(){
                public void windowClosing (WindowEvent e){
                    System.exit(0);
                }
            }
        );
        this.setTitle("Ellipses and Rects");
        this.setSize(350,350);
        this.e1 = new Ellipse(50,100,100,30,0,255,0);
        this.r1 = new Rect(50,50,100,30,255,0,0);
        this.c1 = new Circle(75,150,50,50,0,0,255);
        
    }

    public void paint(Graphics g){
        super.paint(g);
        this.e1.paint(g);
        this.r1.paint(g);
        this.c1.paint(g);
    }
}