package cos;

import java.awt.*;
import java.awt.event.*;
import java.io.IOException;

public class MyFrame extends Frame {
    private WindowListener frameList = new WindowAdapter()
    {
        @Override
        public void windowClosing (WindowEvent ev)
        {
            MyFrame.this.dispose();
        }
    };
/*
    private Color kolor = Color.BLACK;

    private KeyListener keyList = new KeyAdapter()
    {
        @Override
        public void keyPressed (KeyEvent ev)
        {
            switch (ev.getKeyCode())
            {
                case KeyEvent.VK_W: // klawisz 'R'
                    kolor = Color.RED;
                    break;
                case KeyEvent.VK_A: // klawisz 'G'
                    kolor = Color.GREEN;
                    break;
                case KeyEvent.VK_S: // klawisz 'B'
                    kolor = Color.BLUE;
                    break;
                case KeyEvent.VK_D:
                    kolor = Color.BLUE;
                    break;
                default: // inne klawisze
                    kolor = Color.BLACK;
                    break;
            }
        }
    };
    */

    Mapa mapa;
    private MyCanvas can;
    public MyFrame(Mapa map) throws IOException {

        super("kolorowe kwadraty");
        mapa = map;
        can = new MyCanvas(mapa);
        setSize(1000, 1000);
        setLocation(100, 100);
        add(can, BorderLayout.CENTER);

        //can.addKeyListener(keyList);
        //can.addMouseListener(mouseList);
        can.setFocusable(true);
        can.requestFocus();
        addWindowListener(frameList);
        setVisible(true);
    }











}
