import java.util.Date;

public class Wydarzenie {
    public Date poczWyd, konWyd;
    public String nazwa;

    public Wydarzenie(Date poczWyd, Date konWyd, String nazwa) {
        this.poczWyd = poczWyd;
        this.konWyd = konWyd;
        this.nazwa = nazwa;
    }
}
