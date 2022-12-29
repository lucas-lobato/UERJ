package buttons;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Polygon;
import figures.Figure;

public class ButtonPentagon extends Button{
	
	private Polygon polygon;
	
	public ButtonPentagon(int idx, Figure fig) {
		super(idx, fig);
	}

	public void paint(Graphics g, boolean focused){
    	
    	int x_array[] = {super.getFig().getX(), super.getFig().getX() + super.getFig().getW()/2, super.getFig().getX() + super.getFig().getW(), super.getFig().getX() + (int)(super.getFig().getW() * 0.75), super.getFig().getX() + super.getFig().getW()/4};
        int y_array[] = {super.getFig().getY() + super.getFig().getH()/2, super.getFig().getY(), super.getFig().getY() + super.getFig().getH()/2, super.getFig().getY() + super.getFig().getH(), super.getFig().getY() + super.getFig().getH()};
        Polygon polygon = new Polygon(x_array, y_array, 5);
        this.polygon = polygon;
        
        Color CbackGround;
    	if(focused == true) {
    		CbackGround = Color.GRAY;
    	}
    	else {
    		CbackGround = Color.WHITE;
    	}
        
    	Graphics2D g2d = (Graphics2D) g;
        g.setColor(CbackGround);
        g2d.fillRect(super.getFig().getX() - 5, super.getFig().getY() - 5, super.getFig().getW() + 10, super.getFig().getH() + 10);
        g2d.setColor(super.getFig().getFill());
        g2d.drawRect(super.getFig().getX() - 5, super.getFig().getY() - 5, super.getFig().getW() + 10, super.getFig().getH() + 10);
        g2d.setColor(super.getFig().getFill());
        g2d.fillPolygon(this.polygon);
    }
}
