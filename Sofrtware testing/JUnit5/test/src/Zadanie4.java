public class Zadanie4 {
    public String czyIstnieje(int x1, int y1, int x2,int y2 ,int x3, int y3) throws Exception{
        double a = Math.sqrt(Math.pow(Math.abs(x1-x2),2)+Math.pow(Math.abs(y1-y2),2));
        double b = Math.sqrt(Math.pow(Math.abs(x3-x2),2)+Math.pow(Math.abs(y3-y2),2));
        double c = Math.sqrt(Math.pow(Math.abs(x1-x3),2)+Math.pow(Math.abs(y1-y3),2));
         if (!(Math.abs(b - c) < a && a<(b+c) && Math.abs(b - c) <(b+c))){
             throw new Exception("nie można zbusować trójkąta");
         }

         if (a==b &&b==c){
             return "równoboczny";
         }
         else if (a==b || b==c || a==c) {
             return "równoramienny";
         }
        return "różnoboczny";
    }
}
