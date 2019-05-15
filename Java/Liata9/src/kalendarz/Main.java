package kalendarz;

import java.util.GregorianCalendar;

/**
 *
 * @author stachu
 */
public class Main
{
    static int currentYear, currentMonth;
    public static void main(String[] args)
    {
        GregorianCalendar cal = new GregorianCalendar();
        currentMonth = cal.get(GregorianCalendar.MONTH);
        currentYear = cal.get(GregorianCalendar.YEAR);
        new Okno();
    }
}