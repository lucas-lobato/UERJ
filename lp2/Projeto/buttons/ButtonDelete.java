package buttons;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import figures.Figure;

public class ButtonDelete extends Button{

	public ButtonDelete(int idx, Figure fig) {
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
        Font font = new Font("Serif", Font.PLAIN, 16);
        g2d.setFont(font);
        g2d.drawString("Delete", super.getFig().getX() + 7, super.getFig().getY() + 16);
	}
}