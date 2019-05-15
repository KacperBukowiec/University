import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Zadanie2 {
    static List<Wydarzenie> notatnik = new ArrayList();

    public Zadanie2() {
    }

    public static void addWydarzenie(Wydarzenie wyd) throws Exception {
        System.out.println("dodajemy" + wyd.nazwa);
        for(int i = 0; i < notatnik.size(); ++i) {
            System.out.println(notatnik.get(i).nazwa);

            if (wyd.nazwa.equals((notatnik.get(i)).nazwa)) {
                throw new Exception("Podane wydarzenie już istnieje");
            }

            else if ((wyd.poczWyd.compareTo(notatnik.get(i).poczWyd) > 0 )&&( wyd.poczWyd.compareTo(notatnik.get(i).konWyd) < 0)) {
                if (wyd.poczWyd.compareTo(notatnik.get(i).konWyd) < 0){
                    System.out.println("GÓWNO");
                }
                throw new Exception("w tym czasie zaplanowane jest inne wydarzenie");
            }
            else if (wyd.konWyd.compareTo((notatnik.get(i)).poczWyd) > 0 && wyd.konWyd.compareTo((notatnik.get(i)).konWyd) < 0 ){
                throw new Exception("w tym czasie zaplanowane jest inne wydarzenie");
            }
            else if (wyd.poczWyd.compareTo((notatnik.get(i)).poczWyd) == 0 && wyd.konWyd.compareTo((notatnik.get(i)).konWyd) == 0 ){
                throw new Exception("w tym czasie zaplanowane jest inne wydarzenie");
            }
        }
        notatnik.add(wyd);
    }

    public static void deleteWydarzenie(String nazwa) {
        for(int i = 0; i < notatnik.size(); ++i) {
            if (( notatnik.get(i)).nazwa.equals(nazwa)) {
                notatnik.remove(i);
                break;
            }
        }

    }

    public void changeTime(String nazwa, Date pocz, Date kon) throws Exception {
        deleteWydarzenie(nazwa);
        Wydarzenie w = new Wydarzenie(pocz, kon, nazwa);
        addWydarzenie(w);
    }
}
