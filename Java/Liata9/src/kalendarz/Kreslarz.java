package kalendarz;



import java.awt.Color;
import java.awt.Component;
import javax.swing.*;

class Kreslarz extends JLabel implements ListCellRenderer
{
    public Kreslarz()
    {
        setHorizontalAlignment(CENTER);
    }
    @Override
    public Component getListCellRendererComponent(JList val, Object elem, int indeks, boolean zazn, boolean fokus)
    {
        String napis = elem.toString();
        setText(napis);
        if(napis.contains("Niedziela")) setForeground(Color.RED);
        else setForeground(Color.BLACK);
        return this;
    }
}