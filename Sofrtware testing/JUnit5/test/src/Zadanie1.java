import java.util.ArrayList;
import java.util.List;

public class Zadanie1 {


    public static List<String> subElem(List<String> lista , String napis) throws Exception{
        if (lista == null || napis == null) {
            throw new IllegalArgumentException("Jakaś dana wejściowa ma wartość null");
        }
        List<String> out = new ArrayList<>();
        for (int i=0;i<lista.size();i++){
            if (lista.get(i) == null){
                out.add(null);
            }
            else if (!(lista.get(i).equals(napis))){
                out.add(lista.get(i));
            }

        }
        return out;
    }

}
