package kalendarz;


import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.AdjustmentEvent;
import java.awt.event.AdjustmentListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.GregorianCalendar;
import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author stachu
 */
public class Okno extends JFrame implements ActionListener,ChangeListener,AdjustmentListener
{
    public Okno()
    {
        this.setTitle("Kalendarz");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setSize(1200, 620);
        initComponents();
    }
    JTabbedPane zakladki = new JTabbedPane();
    JPanel z1 = new JPanel();
    JPanel z2 = new JPanel();
    JList prev = new JList();
    JList curr = new JList();
    JList next = new JList();
    JButton n = new JButton("Następny");
    JButton p = new JButton("Poprzedni");
    Container pane = this.getContentPane();
    JPanel naprzyciski = new JPanel();
    Spinner spinm1 = new Spinner(Data.Miesiace);
    JSpinner spin1 = new JSpinner(spinm1);
    SpinnerModel spinm2 = new SpinnerNumberModel(Main.currentYear,null,null, 1);
    JSpinner spin2 = new JSpinner(spinm2);
    JScrollBar scroll = new JScrollBar(JScrollBar.HORIZONTAL, Main.currentYear,1,0,10000);
    JTable[] tab = new JTable[12];
    DefaultTableModel[] mtab = new DefaultTableModel[12];
    JScrollPane[] stab = new JScrollPane[12];
    JToolBar pasek = new JToolBar();


    public void initComponents()
    {
        for(int i = 0; i < 12; i++)mtab[i] = new DefaultTableModel(){public boolean isCellEditable(int rowIndex, int mColIndex){return false;}};
        for(int i = 0; i < 12; i++)tab[i] = new JTable(mtab[i]);
        for(int i = 0; i < 12; i++)stab[i] = new JScrollPane(tab[i]);
        for(int i = 0; i < 12; i++)
        {
            stab[i].setBorder(BorderFactory.createTitledBorder(Data.Miesiace[i]));
            stab[i].addMouseListener(new ML());
            tab[i].addMouseListener(new ML());
        }
        zakladki.setBorder(BorderFactory.createEmptyBorder(5,5,5,5));
        pasek.setBorder(BorderFactory.createEmptyBorder(5,5,5,5));
        prev.setModel(new ModelDanych(-1));
        curr.setModel(new ModelDanych(0));
        next.setModel(new ModelDanych(1));
        prev.setCellRenderer(new Kreslarz());
        curr.setCellRenderer(new Kreslarz());
        next.setCellRenderer(new Kreslarz());
        z2.add(prev);
        z2.add(curr);
        z2.add(next);
        initTables();
        z1.setLayout(new GridLayout(4,3,3,3));
        for(int i = 0; i< 12; i++) z1.add(stab[i]);
        zakladki.addTab("rok " + Main.currentYear , z1);
        zakladki.addTab(Data.Miesiace[Main.currentMonth],z2);
        spinm1.setValue(Data.Miesiace[Main.currentMonth]);
        spinm2.setValue(Main.currentYear);
        pasek.setLayout(new GridLayout(3,2,5,5));
        p.addActionListener(this);
        n.addActionListener(this);
        spin1.addChangeListener(this);
        spin2.addChangeListener(this);
        scroll.addAdjustmentListener(this);
        pasek.add(p);
        pasek.add(n);
        pasek.add(spin1);
        pasek.add(spin2);
        pasek.add(scroll);
        pane.add(zakladki);
        pane.add(pasek,BorderLayout.SOUTH);
        this.setVisible(true);
    }
    public void update()
    {
        prev.setModel(new ModelDanych(-1));
        curr.setModel(new ModelDanych(0));
        next.setModel(new ModelDanych(1));
        zakladki.setTitleAt(0, "rok " + Main.currentYear);
        zakladki.setTitleAt(1,Data.Miesiace[Main.currentMonth]);
        spinm1.setValue(Data.Miesiace[Main.currentMonth]);
        spinm2.setValue(Main.currentYear);
        scroll.setValue(Main.currentYear);
        initTables();
    }
    @Override
    public void actionPerformed(ActionEvent e)
    {
        if(e.getSource() == n)
        {
            Main.currentYear++;
            update();
        }
        if(e.getSource() == p)
        {
            Main.currentYear--;
            update();
        }
    }

    @Override
    public void stateChanged(ChangeEvent e)
    {
        Object s = ((JSpinner)e.getSource()).getValue();
        if((JSpinner)e.getSource() == spin1)
        {
            s = (String) s;
            for(int i = 0; i <= 11; i++)
            {
                if(Data.Miesiace[i].equals(s)) Main.currentMonth = i;
            }
        }
        else
        {
            Main.currentYear = (Integer)s;
        }
        update();
    }

    @Override
    public void adjustmentValueChanged(AdjustmentEvent e)
    {
        int i = ((JScrollBar) e.getSource()).getValue();
        Main.currentYear = i;
        update();

    }

    private void initTables()
    {
        String[] Dni = {"Pon","Wt","Śr","Czw","Pt","Sob","Nd"};
        for(int k = 0; k < 12; k++)
        {
            mtab[k].setColumnCount(0);
            tab[k].setRowHeight(20);
            mtab[k].setRowCount(6);
            for (int i=0; i<7; i++) mtab[k].addColumn(Dni[i]);
            tab[k].getTableHeader().setResizingAllowed(false);
            tab[k].getTableHeader().setReorderingAllowed(false);
            tab[k].setColumnSelectionAllowed(true);
            tab[k].setRowSelectionAllowed(true);
            tab[k].setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

            for (int i=0; i<6; i++)
            {
                for (int j=0; j<7; j++)mtab[k].setValueAt(null, i, j);
            }
            GregorianCalendar cal = new GregorianCalendar(Main.currentYear, k, 1);
            int nod = cal.getActualMaximum(GregorianCalendar.DAY_OF_MONTH);
            if(k == 9 && Main.currentYear == 1582) nod = 21;
            int som = cal.get(GregorianCalendar.DAY_OF_WEEK);
            if(som == 1) som = 7;
            else som = som - 1;
            for (int i=1; i<=nod; i++)
            {
                int res = i+som-2;
                int row = new Integer(res/7);
                int column = res%7;
                mtab[k].setValueAt(i, row, column);
                if(k == 9 && Main.currentYear == 1582 && i > 4) mtab[k].setValueAt(i+10, row, column);;
            }
            tab[k].setDefaultRenderer(tab[k].getColumnClass(0),new tableRenderer());
        }
    }

    class ML implements MouseListener
    {

        @Override
        public void mouseClicked(MouseEvent e)
        {
            JScrollPane zrodlo;
            JTable drugie;
            if( e.getSource() instanceof JScrollPane)
            {
                zrodlo = (JScrollPane)e.getSource();

                for(int i = 0; i < 12; i++)
                {
                    if(zrodlo.equals(stab[i])) Main.currentMonth = i;
                }
            }
            if( e.getSource() instanceof JTable)
            {
                drugie = (JTable)e.getSource();

                for(int i = 0; i < 12; i++)
                {
                    if(drugie.equals(tab[i])) Main.currentMonth = i;
                }
            }
            update();
        }

        @Override
        public void mousePressed(MouseEvent e) {

        }

        @Override
        public void mouseReleased(MouseEvent e) {

        }

        @Override
        public void mouseEntered(MouseEvent e) {

        }

        @Override
        public void mouseExited(MouseEvent e) {

        }
    }
    static class tableRenderer extends DefaultTableCellRenderer
    {
        public Component getTableCellRendererComponent (JTable table, Object value, boolean selected, boolean focused, int row, int column)
        {
            super.getTableCellRendererComponent(table, value, selected, focused, row, column);
            if (column == 6)
            {
                setBackground(Color.RED);
            }
            else
            {
                setBackground(Color.WHITE);
            }
            setBorder(null);
            setForeground(Color.black);
            return this;
        }
    }
}