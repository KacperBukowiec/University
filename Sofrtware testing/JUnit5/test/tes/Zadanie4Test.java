import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Zadanie4Test {


    @Test
    public void test(){
        UnitTest1 test = new UnitTest1();
        int result = test.addNum( 5 , 10);
        assertEquals(15,result);

    }

}