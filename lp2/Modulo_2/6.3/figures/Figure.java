package figures;

import java.awt.Graphics;

public class Figure{
    int x, y;
    int w, h;

    public void paint(Graphics g){
        
    }

    public void print(){
        System.out.format("Figura de tamanho (%d, %d) na posição (%d, %d).\n", this.x = x, this.y = y, this.w = w, this.h = h);
    }
}