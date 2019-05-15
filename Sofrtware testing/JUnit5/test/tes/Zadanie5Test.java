import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Zadanie5Test {

    @Test
    public  void test() throws Exception {
        String result = Zadanie5.IntegerToRomanNumeral(12);
        assertEquals("XII",result);
        result = Zadanie5.IntegerToRomanNumeral(199);
        assertEquals("CXCIX",result);
        result = Zadanie5.IntegerToRomanNumeral(1099);
        assertEquals("MXCIX",result);
        result = Zadanie5.IntegerToRomanNumeral(46);
        assertEquals("XLVI",result);
        result = Zadanie5.IntegerToRomanNumeral(19);
        assertEquals("XIX",result);
        assertThrows(Exception.class, () -> {
            Zadanie5.IntegerToRomanNumeral(0);
        } );

        assertThrows(Exception.class, () -> {
            Zadanie5.IntegerToRomanNumeral(4001);
        } );
    }


}