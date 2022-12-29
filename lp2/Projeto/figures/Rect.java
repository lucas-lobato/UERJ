package figures;

import java.awt.*;
import java.awt.Graphics;

public class Rect extends Figure{
	private static final long serialVersionUID = 1L;

	public Rect(int x, int y, int w, int h, Color border, Color fill){
        super(x, y, w, h, border, fill);
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
        g2d.drawRect(this.getX(), this.getY(), this.getW(), this.getH());
        g.setColor(this.getFill());
        g.fillRect(this.getX() + 1,this.getY() + 1,this.getW() - 1,this.getH() - 1);
        g.setColor(Cfocus);
        g2d.drawRect(this.getX() - 1, this.getY() - 1, this.getW() + 2, this.getH() + 2);
    }
}
