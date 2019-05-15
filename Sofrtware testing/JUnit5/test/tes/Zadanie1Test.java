import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class Zadanie1Test {

    @Test
    public void test() throws Exception {
        String nazwa ="c";
        List<String> lista = Arrays.asList("a","b","c","d","sas");
        List<String> result = Zadanie1.subElem(lista,nazwa);
        List<String> oczekiwane = Arrays.asList("a","b","d","sas");
        assertEquals(oczekiwane,result);

        nazwa ="c";
        lista = Arrays.asList(null,"b","c","d","sas");
        result = Zadanie1.subElem(lista,nazwa);
        oczekiwane = Arrays.asList(null,"b","d","sas");
        assertEquals(oczekiwane,result);

    }

    @Test
    public void testNull() throws Exception{
        String nazwa ="asd";
        List<String> lista = Arrays.asList("a","b","c","d","sas");
        IllegalArgumentException thrown = assertThrows(IllegalArgumentException.class, () -> {
            Zadanie1.subElem(null,null);
        },"Jakaś dana wejściowa ma wartość null" );
        assertTrue(thrown.getMessage().contains("Jakaś dana wejściowa ma wartość null"));

        thrown = assertThrows(IllegalArgumentException.class, () -> {
            Zadanie1.subElem(lista,null);
        },"Jakaś dana wejściowa ma wartość null" );
        assertTrue(thrown.getMessage().contains("Jakaś dana wejściowa ma wartość null"));
        thrown = assertThrows(IllegalArgumentException.class, () -> {
            Zadanie1.subElem(null,nazwa);
        },"Jakaś dana wejściowa ma wartość null" );

        assertTrue(thrown.getMessage().contains("Jakaś dana wejściowa ma wartość null"));

    }


}