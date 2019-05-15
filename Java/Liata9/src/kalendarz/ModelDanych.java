package kalendarz;



import java.util.GregorianCalendar;
import javax.swing.AbstractListModel;


class ModelDanych extends AbstractListModel
{
    private final int przes;
    public ModelDanych(int p)
    {
        przes = p;
    }
    @Override
    public Object getElementAt (int i)
    {
        GregorianCalendar cal = new GregorianCalendar(Main.currentYear, Main.currentMonth+przes, 1);
        int som = cal.get(GregorianCalendar.DAY_OF_WEEK);
        String s = "";
        if(Main.currentMonth+przes == 9 && Main.currentYear == 1582 && i > 3) s += i+1+10+" ";
        else s += i+1 + " ";
        int res = (Main.currentMonth+przes)%12;
        if(res < 0) res = 12 + res;
        s += Data.Miesiace[res] + " " + Data.Dni[(som-1+i)%7] + " " ;
        return s;
    }
    @Override
    public int getSize ()
    {
        GregorianCalendar cal = new GregorianCalendar(Main.currentYear, Main.currentMonth+przes, 1);
        int nod = cal.getActualMaximum(GregorianCalendar.DAY_OF_MONTH);
        if(Main.currentYear == 1582 && Main.currentMonth+przes == 9) nod = 21;
        return nod;
    }
}