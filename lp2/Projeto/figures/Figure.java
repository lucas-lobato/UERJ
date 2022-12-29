package figures;

import java.awt.Color;
import java.awt.Graphics;
import java.io.Serializable;
import ivisible.IVisible;

public  abstract class Figure implements IVisible, Serializable{
	private static final long serialVersionUID = 1L;
	private int x;
	private int y;
	private int w;
	private int h;
	private Color border;
	private Color fill;
	private Color contour;
	
	public Figure(int x, int y, int w, int h, Color border, Color fill) {
		this.setX(x);
		this.setY(y);
		this.setW(w);
		this.setH(h);
		this.setBorder(border);
		this.setFill(fill);
	}
    
    public void drag(int dx, int dy) {
    	this.x += dx;
    	this.y += dy;
    }
	
	public boolean clicked(int x, int y) {
    	return (this.x <= x && x <= this.x + this.w && this.y <= y && y <= this.y + this.h);
    }
	
	public void paint(Graphics g, boolean focused){
        
    }
	
	//Getters and Setters
    public int getX() {
		return this.x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return this.y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public int getW() {
		return this.w;
	}

	public void setW(int w) {
		this.w = w;
	}

	public int getH() {
		return this.h;
	}

	public void setH(int h) {
		this.h = h;
	}

	public Color getFill() {
		return this.fill;
	}

	public void setFill(Color fill) {
		this.fill = fill;
	}

	public Color getContour() {
		return this.contour;
	}

	public void setContour(Color contour) {
		this.contour = contour;
	}

	public Color getBorder() {
		return this.border;
	}

	public void setBorder(Color border) {
		this.border = border;
	}
}
