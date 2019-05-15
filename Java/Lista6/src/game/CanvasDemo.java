package game;


import javax.swing.*;
import java.awt.*;

public class CanvasDemo extends JFrame {
    private MyCanvas canvas = new MyCanvas();


    public void CanvasDemo() {
        setLayout(new BorderLayout());
        setSize(500, 500);
        setTitle("Canvas dd");
        add("Center", canvas);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setLocationRelativeTo(null);
        setVisible(true);
    }
}


