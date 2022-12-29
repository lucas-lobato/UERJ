package buttons;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Ellipse2D;
import figures.Figure;

public class ButtonEllipse extends Button{

	public ButtonEllipse(int idx, Figure fig) {
		super(idx, fig);
	}
	
	public void paint(Graphics g, boolean focused) {
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
        g2d.fill(new Ellipse2D.Double(super.getFig().getX(), super.getFig().getY(), super.getFig().getW(), super.getFig().getH()));
	}

}
