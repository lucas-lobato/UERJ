package buttons;

import java.awt.Graphics;
import figures.Figure;
import ivisible.IVisible;

public class Button implements IVisible{
	private int idx;
	private Figure fig;
	
	public Button(int idx, Figure fig) {
		this.setIdx(idx);
		this.fig = fig;
	}
	
	public boolean clicked(int x, int y) {
		return (fig.getX() <= x && x <= fig.getX() + fig.getW() && fig.getY() <= y && y <= fig.getY() + fig.getH());
		
	}

	public void paint(Graphics g, boolean focused) {
        
	}

	//Getters and Setters
	public int getIdx() {
		return this.idx;
	}

	public void setIdx(int idx) {
		this.idx = idx;
	}

	public Figure getFig() {
		return this.fig;
	}

	public void setFig(Figure fig) {
		this.fig = fig;
	}

}
