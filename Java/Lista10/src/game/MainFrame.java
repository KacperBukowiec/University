package game;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MainFrame extends JFrame {
    MainPanel mainPanel = new MainPanel(Main.szerPlanszy, Main.wysPlanszy, Main.x, Main.y);
    static public Bachor dzieci[] = new Bachor[12];

    public MainFrame() {
        this.setTitle("Mikołaj i dzieciaki");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setSize(Main.x+20, Main.y+20);
        this.setResizable(false);
        initComponents();
        this.setVisible(true);
    }


    private void initComponents()
    {
        add(mainPanel);
        ActionListener listener = new ActionListener(){
            public void actionPerformed(ActionEvent event){
                repaint();
            }
        };
        Timer displayTimer = new Timer(50, listener);
        displayTimer.start();
        for(int i = 0; i < 12; i++)
        {
            dzieci[i] = new Bachor(i);
            new Thread(dzieci[i]).start();
        }
    }






}
