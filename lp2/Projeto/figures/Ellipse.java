package figures;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;
import java.awt.Color;


public class Ellipse extends Figure{
    private static final long serialVersionUID = 1L;
   
	public Ellipse (int x, int y, int w, int h, Color border, Color fill){
    	super(x,y,w,h,border,fill);
    }

    public void paint(Graphics g, boolean focused){
    	Color Cfocus;
    	if(focused == true) {
    		Cfocus = Color.red;
    	}
    	else {
    		Cfocus = new Color(0,0,0,0);
    	}
        Graphics2D g2d = (Graphics2D) g;
        g.setColor(this.getBorder());
        g2d.draw(new Ellipse2D.Double(this.getX(),this.getY(),this.getW(),this.getH()));
        g.setColor(this.getFill());
        g2d.fill(new Ellipse2D.Double(this.getX(),this.getY(),this.getW(),this.getH()));
        g.setColor(Cfocus);
        g2d.draw(new Ellipse2D.Double(this.getX() - 1, this.getY() - 1, this.getW() + 2, this.getH() + 2));
    }
}
