package cos;

import java.awt.*;
import java.awt.event.*;
import java.io.IOException;

public class Main{

    public static void main(String[] args) throws IOException {
        Mapa mapa = new Mapa(20);
        System.out.println(mapa.n);
            new MyFrame(mapa);
    }
}
