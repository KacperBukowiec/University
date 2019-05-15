package com.company;

public class ZbiorNaTablicy extends Zbior {
    public Para tablica[];

    ZbiorNaTablicy(int x) throws Exception {
        if (x<2){
            throw new Exception("Wrong size");
        }
        tablica = new Para[x];
    }

    /**
     *
     * @param k
     * @return Z
     * @throws Exception
     */
    @Override
    public Para szukaj(String k) throws Exception {
        for (int i=0; i < tablica.length; i++ ){
                if(tablica[i].key == k){
                return tablica[i];
            }
        }
        return null;
    }



    @Override
    public void wstaw(Para p) throws Exception {
        boolean loop_check=true;
        loop_check = isLoopCheck(p, loop_check);
        if (loop_check) throw new Exception("Array is too small");
    }

    boolean isLoopCheck(Para p, boolean loop_check) {
        for (int i=0; i < tablica.length ; i++ ){
            if (tablica[i]==p){
                loop_check=false;
                break;
            }
            if (tablica[i] == null) {
                tablica[i] = p;
                loop_check=false;
                break;
            }
        }
        return loop_check;
    }

    @Override
    public double czytaj(String k) throws Exception {
        for (int i=0; i < tablica.length ; i++ ){
            if(tablica[i].key == k){
                return tablica[i].getValue();
            }
        }
        throw new Exception("No such key");
    }

    @Override
    public void ustaw(Para p) throws Exception {
        for (int i=0; i < tablica.length ; i++ ){
            if(tablica[i] == p){
                tablica[i].setValue(p.getValue());
            }
        }

        wstaw(p);
        // nie wiem czy zadziała ustaw(p) więc to daje dla bezpieczeństwa
        //for (int i=0; i < tablica.length ; i++ ){
        //    if (tablica[i] == null) {
        //     tablica[i] = p;
        //       break;
        //   }
        //}
        //throw new Exception("Array is too small");
    }

    @Override
    public void czysc() {
        for (int i=0; i < tablica.length ; i++ ){
            tablica[i] = null;
        }
    }

    @Override
    public int ile() {
        int counter = 0;
        for (int i=0; i < tablica.length; i++ ){
            if(tablica[i]== null)return counter;
            else counter++;
        }
        return counter;
    }
}
