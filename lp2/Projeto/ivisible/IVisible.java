package ivisible;

import java.awt.Graphics;


public interface IVisible {
	public boolean clicked (int x, int y);
	public void paint (Graphics g, boolean focused);
}
