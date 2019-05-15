package cos;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.IOException;

public class MyCanvas extends Canvas {

    int ePosX=0 ,ePosY=0;
    Image badacz,win ;
    Mapa mapa;
    int n;
    Komnata[][] matrix;
    int square;



    public void paint(Graphics g){



        g.setColor(Color.CYAN);

        for (int i=0;i<n; i++){
            for (int j=0;j<n;j++){
                g.fillRect( i*(square + 10), j*(square+ 10) , square, square);

                if (matrix[i][j].w2==true){
                    g.setColor(Color.black);
                    g.fillRect((i*(square + 10))+square , j*(square+ 10)+square/2 ,10,10);
                    g.setColor(Color.CYAN);
                }
                if (matrix[i][j].w3==true){
                    g.setColor(Color.black);
                    g.fillRect((i*(square + 10))+square/2-5 , j*(square+ 10)+square ,10,10);
                    g.setColor(Color.CYAN);
                }
                if (matrix[i][j].w0==true){
                    g.setColor(Color.black);
                    g.fillRect((i*(square + 10))-10 , j*(square+ 10)+square/2 ,10,10);
                    g.setColor(Color.CYAN);
                }
                if (matrix[i][j].w1==true){
                    g.setColor(Color.black);
                    g.fillRect((i*(square + 10))+square/2-5 , j*(square+ 10)-10 ,10,10);
                    g.setColor(Color.CYAN);
                }
            }
        }
        g.drawImage(badacz,ePosX*(square+10)+square/2-10,ePosY*(square+10)+square/2-10,null);
        g.setColor(Color.green);
        g.fillRect( (n-1)*(square + 10), (n-1)*(square+ 10) , square, square);

        if (ePosX==n-1 && ePosY==n-1){
            g.drawImage(win,0,0,null);
        }

    }
    public MyCanvas(Mapa map) throws IOException {
        super();
        this.addKeyListener(keyList);
        mapa=map;
        n = mapa.n;
        matrix = mapa.map;
        square = (800 - n * 10)/n;
        badacz = ImageIO.read(getClass().getResource("\\resources\\images\\eksplorator.gif"));
        win = ImageIO.read(getClass().getResource("\\resources\\images\\win.gif"));
    }

    private KeyListener keyList = new KeyAdapter()
    {
        @Override
        public void keyPressed (KeyEvent ev)
        {
            switch (ev.getKeyCode())
            {
                case KeyEvent.VK_W:
                    if (matrix[ePosX][ePosY].w1==true) {
                        ePosY -= 1;
                        MyCanvas.this.repaint();
                    }
                    break;
                case KeyEvent.VK_A:
                    if (matrix[ePosX][ePosY].w0) {
                        ePosX -= 1;
                        MyCanvas.this.repaint();
                    }
                    break;
                case KeyEvent.VK_S:
                    if (matrix[ePosX][ePosY].w3) {
                        ePosY += 1;
                        MyCanvas.this.repaint();
                    }
                    break;
                case KeyEvent.VK_D:
                    if (matrix[ePosX][ePosY].w2) {
                        ePosX += 1;
                        MyCanvas.this.repaint();
                    }
                    break;
            }
        }
    };





}
