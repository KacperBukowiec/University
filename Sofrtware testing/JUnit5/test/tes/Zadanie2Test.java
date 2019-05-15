import org.junit.jupiter.api.Test;

import java.util.Date;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class Zadanie2Test {


    @Test
    public void testAdd() throws Exception {
        Zadanie2 x = new Zadanie2();
        Date pocz = new Date(2019,1,1);
        Date kon = new Date(2019,2,2);
        Wydarzenie w = new Wydarzenie(pocz,kon,"jeden");
        Zadanie2.addWydarzenie(w);
        List<Wydarzenie> not = Zadanie2.notatnik;
        Wydarzenie ww = not.get(0);
        assertEquals(ww.poczWyd,pocz);
        assertEquals(ww.konWyd,kon);
        assertEquals(ww.nazwa,"jeden");


        pocz = new Date(2018,1,1);
        kon = new Date(2018,2,2);
        Wydarzenie w0 =  new Wydarzenie(pocz,kon,"jeden");

        Exception thrown = assertThrows(Exception.class, () -> {
            Zadanie2.addWydarzenie(w0);
        },"tekst" );
        assertTrue(thrown.getMessage().contains("Podane wydarzenie już istnieje"));

        pocz = new Date(2019,1,1);
        kon = new Date(2019,2,2);
        Wydarzenie w2 =  new Wydarzenie(pocz,kon,"dwa");

        thrown = assertThrows(Exception.class, () -> {
            Zadanie2.addWydarzenie(w2);
        },"tekst" );
        System.out.println(thrown.getMessage());
        assertTrue(thrown.getMessage().contains("w tym czasie zaplanowane jest inne wydarzenie"));

        pocz = new Date(2019,1,15);
        kon = new Date(2019,1,20);
        Wydarzenie w3 =  new Wydarzenie(pocz,kon,"dwa");

        thrown = assertThrows(Exception.class, () -> {
            Zadanie2.addWydarzenie(w3);
        },"tekst" );
        System.out.println(thrown.getMessage());
        assertTrue(thrown.getMessage().contains("w tym czasie zaplanowane jest inne wydarzenie"));


        pocz = new Date(2019,1,15);
        kon = new Date(2019,3,1);
        Wydarzenie w4 =  new Wydarzenie(pocz,kon,"dwa");

        thrown = assertThrows(Exception.class, () -> {
            Zadanie2.addWydarzenie(w4);
        },"tekst" );
        System.out.println(thrown.getMessage());
        assertTrue(thrown.getMessage().contains("w tym czasie zaplanowane jest inne wydarzenie"));



        pocz = new Date(2019,2,2);
        kon = new Date(2019,3,1);
        Wydarzenie w5 =  new Wydarzenie(pocz,kon,"dwaasdas");
        Zadanie2.addWydarzenie(w5);

        pocz = new Date(2018,2,2);
        kon = new Date(2019,1,1);
        Wydarzenie w6 =  new Wydarzenie(pocz,kon,"trzysadasd");
        Zadanie2.addWydarzenie(w6);


    }



}