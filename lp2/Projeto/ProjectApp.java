import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.ArrayList;
import java.util.Random;
import figures.*;
import buttons.*;
import buttons.Button;

class ProjectApp{
    public static void main(String[] args){
        Frame frame = new Frame();
        frame.setVisible(true);
    }
}

class Frame extends JFrame{
	private static final long serialVersionUID = 1L;
	ArrayList<Figure> figs = new ArrayList<Figure>();
	ArrayList<Button> buts = new ArrayList<Button>();
    
	Random rand = new Random();
    Figure Ffocus = null;
    Button Bfocus = null;
    Figure ColorAux = null;
    
    int aux = 0;
    int colorPaintAux = 0;
    
    Color colors[] = {
    		Color.WHITE, Color.BLACK, Color.BLUE, Color.CYAN, Color.DARK_GRAY,
            Color.GREEN, Color.LIGHT_GRAY, Color.MAGENTA, Color.ORANGE, Color.GRAY,
            Color.RED, Color.YELLOW, Color.PINK	
    };
    
	@SuppressWarnings("unchecked")
	Frame(){
    	try {
    		FileInputStream f = new FileInputStream("proj.bin");
    		ObjectInputStream o = new ObjectInputStream(f);
    		this.figs = (ArrayList<Figure>) o.readObject();
    		o.close();
    		
    	} catch (Exception x) {
    		System.out.println("ERRO!");
    	}
    	buts.add(new ButtonRect(1, new Rect(20, 50, 30, 30, Color.BLACK, Color.BLACK)));
    	buts.add(new ButtonEllipse(2, new Ellipse(20,90,30,30, Color.BLACK, Color.BLACK)));
    	buts.add(new ButtonRoundRect(3, new RoundRect(20,130,30,30, Color.BLACK, Color.BLACK)));
    	buts.add(new ButtonTriangle(4, new Triangle(60,50,30,30, Color.BLACK, Color.BLACK)));
    	buts.add(new ButtonPentagon(5, new Pentagon(60,90,30,30, Color.BLACK, Color.BLACK)));
    	buts.add(new ButtonStar(6, new Star(60,130,30,30, Color.BLACK, Color.BLACK)));
    	buts.add(new ButtonDelete(7, new Rect(20, 170, 70, 20, Color.BLACK, Color.BLACK)));
    	buts.add(new ButtonDeleteAll(8, new Rect(20, 200, 70, 20, Color.BLACK, Color.BLACK)));
    	buts.add(new ButtonChangeColor(9, new Rect(20, 230, 70, 20, Color.BLACK, Color.BLACK)));
    	
        this.addWindowListener(
            new WindowAdapter(){
                public void windowClosing(WindowEvent e){
                	try {
                		FileOutputStream f = new FileOutputStream("proj.bin");
                		ObjectOutputStream o = new ObjectOutputStream(f);
                		o.writeObject(figs);
                		o.flush();
                		o.close();
                		
                	} catch (Exception x){
                		
                	}
                    System.exit(0);
                }
            }
        );

        this.addKeyListener(
            new KeyAdapter(){
                public void keyPressed(KeyEvent evt){
                	Point p = MouseInfo.getPointerInfo().getLocation();
                	int x = p.x - getLocation().x;
                	int y = p.y - getLocation().y;
                    int w = rand.nextInt(50);
                    int h = rand.nextInt(50);
                    if(evt.getKeyChar() == 'r'){
                        figs.add(new Rect(x,y, w,h, Color.BLACK,Color.WHITE));
                    } else if(evt.getKeyChar() == 'e'){
                        figs.add(new Ellipse(x,y, w,h, Color.BLACK,Color.WHITE));
                    } else if(evt.getKeyChar() == 'R'){
                        figs.add(new RoundRect(x,y, w,h, Color.BLACK,Color.WHITE));
                    } else if(evt.getKeyChar() == 't') {
                        figs.add(new Triangle(x,y, w,h, Color.BLACK,Color.WHITE));
                    } else if(evt.getKeyChar() == 'p') {
                        figs.add(new Pentagon(x,y, w,h, Color.BLACK, Color.WHITE));
                    } else if(evt.getKeyChar() == 's') {
                        figs.add(new Star(x,y, w,h, Color.BLACK, Color.WHITE));
                    } else if(evt.getKeyCode() == KeyEvent.VK_DELETE || evt.getKeyCode() == KeyEvent.VK_BACK_SPACE){
                    	figs.remove(Ffocus);
                    } else if(evt.getKeyChar() == '+'){
                    	if(Ffocus.getW() < 400 && Ffocus.getH() < 400) {
                        	Ffocus.setH(Ffocus.getH() + Ffocus.getH()/10);
                        	Ffocus.setW(Ffocus.getW() + Ffocus.getW()/10);
                            if(Ffocus.getH()/10 == 0 || Ffocus.getW()/10 == 0) {
                            	Ffocus.setH(Ffocus.getH() + 1);
                            	Ffocus.setW(Ffocus.getW() + 1);
                            }
                        }
                    } else if(evt.getKeyChar() == '-'){
                    	if(Ffocus.getW() > 0 && Ffocus.getH() > 0) {
                    		Ffocus.setH(Ffocus.getH() - Ffocus.getH()/10);
                        	Ffocus.setW(Ffocus.getW() - Ffocus.getW()/10);
                    	}
                    } else if(evt.getKeyCode() == KeyEvent.VK_UP){
                    	Ffocus.setY(Ffocus.getY() - 1);
                    } else if(evt.getKeyCode() == KeyEvent.VK_DOWN){
                    	Ffocus.setY(Ffocus.getY() + 1);
                    } else if(evt.getKeyCode() == KeyEvent.VK_LEFT){
                    	Ffocus.setX(Ffocus.getX() - 1); 
                    } else if(evt.getKeyCode() == KeyEvent.VK_RIGHT){
                    	Ffocus.setX(Ffocus.getX() + 1);
                    } else if(evt.getExtendedKeyCode() == KeyEvent.VK_SPACE){
                    	if(figs.size() > 0) {
                    		if(Ffocus == null) {
                    			Ffocus = figs.get(0);
                    		}
                    		Ffocus = null;
                        	if(aux == 0) {
                        		Ffocus = figs.get(figs.size() - 1);
                        	}
                        	Ffocus = null;
                        	if(aux >= figs.size()) {
                        		aux = 0;
                        	}
                        	if(aux != 0) {
                        		Ffocus = figs.get(aux);
                        	}   	
                        	Ffocus = figs.get(aux);
                        	Ffocus.setContour(Color.red);
                        	figs.remove(Ffocus);
                        	figs.add(Ffocus);
                        	aux += 1;
                    	}
                    } else if(evt.getKeyChar() == 'c'){
                    	Ffocus.setFill(colors[colorPaintAux]);
                    	colorPaintAux += 1;
                    	if(colorPaintAux >= 12) {
                    		colorPaintAux = 0;
                    	}
                    } else if(evt.getKeyChar() == 'C'){
                    	Ffocus.setBorder(colors[colorPaintAux]);
                    	colorPaintAux += 1;
                    	if(colorPaintAux >= 12) {
                    		colorPaintAux = 0;
                    	}
                    } else if(evt.getKeyChar() == 'b'){
                    	Bfocus = null;
                    }
                    repaint();
                }
            }
        );
        
        this.addMouseMotionListener(
        	new MouseMotionAdapter() {
        		public void mouseDragged(MouseEvent evt) {
        			try {
        				int dif_x = (evt.getX() - Ffocus.getX()) - Ffocus.getW()/2;
            			int dif_y = (evt.getY() - Ffocus.getY()) - Ffocus.getH()/2;
            			Ffocus.drag(dif_x, dif_y);
            			repaint();
            			
        			} catch(NullPointerException e) {
        				
        			}
        		}
        	}
        );
        
        this.addMouseListener(
        	new MouseAdapter() {
        		public void mousePressed(MouseEvent evt) {
        			boolean auxClick = false;
        			for(Button but: buts) {
        				if(but.clicked(evt.getX(),evt.getY())) {
	        				Bfocus = but;
	        				if(but.getIdx() == 7 && Ffocus != null) {
								figs.remove(Ffocus);
								Bfocus = null;
								repaint();
							}
							if(but.getIdx() == 8 && !figs.isEmpty()) {
								figs.clear();
								Bfocus = null;
								repaint();
							}
							if(but.getIdx() == 9 && Ffocus != null) {
								Ffocus.setFill(colors[colorPaintAux]);
		                    	colorPaintAux += 1;
		                    	if(colorPaintAux >= 12) {
		                    		colorPaintAux = 0;
		                    	}
		                    	Bfocus = null;
		                    	repaint();
							}
	    					repaint();
	    					auxClick = true;
        				}		
        			}
        			if(Bfocus != null && !(Bfocus.clicked(evt.getX(),evt.getY()))) {
						if(Bfocus.getIdx() == 1) {
							figs.add(new Rect(evt.getX(),evt.getY(), 30,30, Color.BLACK,Color.WHITE));
						}
						if(Bfocus.getIdx() == 2) {
							figs.add(new Ellipse(evt.getX(),evt.getY(), 30,30, Color.BLACK,Color.WHITE));
						}
						if(Bfocus.getIdx() == 3) {
							figs.add(new RoundRect(evt.getX(),evt.getY(), 30,30, Color.BLACK,Color.WHITE));
						}
						if(Bfocus.getIdx() == 4) {
							figs.add(new Triangle(evt.getX(),evt.getY(), 30,30, Color.BLACK,Color.WHITE));
						}
						if(Bfocus.getIdx() == 5) {
							figs.add(new Pentagon(evt.getX(),evt.getY(), 30,30, Color.BLACK,Color.WHITE));
						}
						if(Bfocus.getIdx() == 6) {
							figs.add(new Star(evt.getX(),evt.getY(), 30,30, Color.BLACK,Color.WHITE));
						}
        			}
        			
        			for(Figure fig: figs) {
        				if(fig.clicked(evt.getX(),evt.getY())) {
	        				Ffocus = fig;
	        				figs.remove(fig);
	        				figs.add(Ffocus);
	    					Ffocus.setContour(Color.red);
	    					repaint();
	    					break;
        				} else {
        					if(auxClick == false) {
        						Ffocus = null;
        					}
        				}
        			}
        			repaint();
        		}
        	}
        );
        this.setTitle("Projeto");
        this.setSize(600,600);
    }

    public void paint(Graphics g){
        super.paint(g);
        for(Figure fig: this.figs){
        	if(fig == Ffocus) {
        		fig.paint(g, true);
        	}
        	else {
        		fig.paint(g, false);
        	}
        }
        for(Button but: this.buts){
        	if(but == Bfocus) {
        		but.paint(g, true);
        	}
        	else {
        		but.paint(g, false);
        	}
        }
    }
}
