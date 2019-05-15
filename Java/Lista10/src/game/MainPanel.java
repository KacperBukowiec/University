package game;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class MainPanel extends JPanel {
    static int mPosX = 5,mPosY = 5;
    int n, m, x, y;
    int jednostka;

    private static int vis[][] = new int[20][20];
    private static boolean[][] prezent = new boolean[20][20];
    public static int c1[] = {1, -1, 0, 0}, c2[] = {0, 0, -1, 1};

    public MainPanel(int n, int m, int x, int y) // n kol m wiersze x szerokosc y wysokosc
    {
        this.setSize(x , y );
        this.n = n;
        this.m = m;
        this.x = x ;
        this.y = y ;
        jednostka = x / n;
        boolean[][] prezent = new boolean[20][20];
        //mGap = y / m - 5;
        //this.addKeyListener(keyList);
        init();
    }
    private KeyListener keyList = new KeyAdapter()
    {
        @Override
        public void keyPressed (KeyEvent ev)
        {
            switch (ev.getKeyCode())
            {
                case KeyEvent.VK_A:
                    mPosX = (mPosX - 1 + Main.szerPlanszy) % Main.szerPlanszy;
                    break;
                case KeyEvent.VK_D:
                    mPosX = (mPosX + 1 + Main.szerPlanszy) % Main.szerPlanszy;
                    break;
                case KeyEvent.VK_W:
                    mPosY = (mPosY - 1 + Main.wysPlanszy) % Main.wysPlanszy;
                    break;
                case KeyEvent.VK_S:
                    mPosY = (mPosY + 1 + Main.wysPlanszy) % Main.wysPlanszy;
                    break;
                case KeyEvent.VK_SPACE:
                    if (Main.lPrezentow > 0) {
                        Main.lPrezentow--;
                        prezent[mPosX][mPosY] = true;
                    }

                    break;
                case KeyEvent.VK_P:
                    Main.koniecGry = false;
                    break;
            }
        }
    };

    void init()
    {
        this.addKeyListener(keyList);
        this.setFocusable(true);
        this.requestFocus();

        //x = (int) Math.floor(Math.random() * L11.n);
        //y = (int) Math.floor(Math.random() * L11.m);
        //while((MainPanel.checkVis(x,y, 15)) == false)
        //{
        //    x = (int) Math.floor(Math.random() * L11.n);
        //    y = (int) Math.floor(Math.random() * L11.m);
        //}
    }

    @Override
    public void paint(Graphics g)
    {
        super.paint(g);
        if(Main.koniecGry == false)
        {

            for (int i = 0;i<Main.szerPlanszy;i++){
                g.drawLine(0,jednostka*i,Main.szerPlanszy * jednostka,jednostka*i);
                g.drawLine(jednostka*i,0,jednostka*i, Main.wysPlanszy * jednostka);
            }
            g.setColor(Color.RED);
            g.fillRect(mPosX *jednostka+(jednostka/2 -20),mPosY *jednostka +(jednostka/2 -20) ,40,40);
            g.setColor(Color.BLACK);

            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(prezent[i][j] == true)
                        g.drawString("PREZENT", i * jednostka + 10, j * jednostka + 10);

            //for(Kreska kreska : MainPanel.lista)
                //g.drawLine(kreska.x1, kreska.y1, kreska.x2, kreska.y2);
            for(Bachor dziecko : MainFrame.dzieci)
            {
                g.drawOval(dziecko.x * jednostka, dziecko.y * jednostka, jednostka, jednostka);
                if(dziecko.state == 0)
                    g.drawLine(dziecko.x * jednostka, dziecko.y * jednostka, dziecko.x * jednostka + jednostka, dziecko.y * jednostka + jednostka);
                if(dziecko.state == 2)
                    g.drawString("ŚPI", dziecko.x * jednostka + 30, dziecko.y * jednostka + 40);
                g.drawString(Integer.toString(dziecko.id), dziecko.x  * jednostka, (dziecko.y + 1) * jednostka);
            }
            //g.drawString("MIKOŁAJ", mikX * nGap + 15, mikY * mGap + 15);
            //for(int i = 0; i < n; i++)
            //    for(int j = 0; j < m; j++)
            //        if(prezent[i][j] == true)
            //            g.drawString("PREZENT", i * nGap + 15, j * mGap + 55);
        }
    }


    public static synchronized void setVis(int x, int y, int nr)
    {
        vis[x][y] = nr;
    }

    public static synchronized boolean checkVis(int x, int y, int nr)
    {
        if(vis[x][y] != 0)
            return false;
        else
            vis[x][y] = nr;
        return true;
    }

    public static synchronized int getMikY() {
        return MainPanel.mPosY;
    }

    public static synchronized void setmPosXikY(int mikY) {
        MainPanel.mPosY = mikY;
    }

    public static synchronized int getMikX() {
        return MainPanel.mPosX;
    }

    public static synchronized int getVis(int x, int y)
    {
        return MainPanel.vis[x][y];
    }

    public static synchronized void setPrez(int x, int y, boolean b)
    {
        prezent[x][y] = b;
    }

    public static synchronized boolean getPrez(int x, int y)
    {
        return prezent[x][y];
    }

}
