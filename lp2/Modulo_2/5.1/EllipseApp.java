import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.Random;
import java.util.ArrayList;

import figures.*;


class EllipseApp{
    public static void main(String[] args){
        EllipseFrame frame = new EllipseFrame();
        frame.setVisible(true);
    }
}

class EllipseFrame extends JFrame {

    ArrayList<Ellipse> ep = new ArrayList<Ellipse>();
    Random rand = new Random();

    EllipseFrame(){
        this.addWindowFocusListener(
            new WindowAdapter(){
                public void windowClosing (WindowEvent e){
                    System.exit(0);
                }
            }
        );

        this.addKeyListener(
            new KeyAdapter(){
                public void keyPressed(KeyEvent evt){
                    if(evt.getKeyChar() == 'e'){
                        int x = rand.nextInt(350);
                        int y = rand.nextInt(350);
                        int h = rand.nextInt(50);
                        int w = rand.nextInt(50);
                        ep.add(new Ellipse(x,y,w,h));
                        repaint();
                    }
                }
            }
        );
    
        this.setTitle("Ellipses List");
        this.setSize(350,350);
    }

    public void paint(Graphics g){
        super.paint(g);
        for(Ellipse e: this.ep){
            e.paint(g);
        }
    }
}