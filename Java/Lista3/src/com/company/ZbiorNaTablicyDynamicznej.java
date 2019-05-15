package com.company;

public class ZbiorNaTablicyDynamicznej extends ZbiorNaTablicy {

    ZbiorNaTablicyDynamicznej() throws Exception {
        super(2);
    }


    @Override
    public void wstaw(Para p) throws Exception {
        boolean loop_check = true;
        loop_check = isLoopCheck(p, loop_check);
        if (loop_check) {
            Para[] tablica2 = new Para[tablica.length];
            for (int i = 0; i < tablica.length; i++) {
                tablica2[i] = tablica[i];
            }
            tablica = new Para[tablica.length * 2];
            for (int i = 0; i < tablica2.length; i++) {
                System.out.println(i);
                tablica[i] = tablica2[i];
            }

        }
    }

    @Override
    public void ustaw(Para p) throws Exception {
        for (int i = 0; i < tablica.length; i++) {
            if (tablica[i].key == p.key) {
                tablica[i].setValue(p.getValue());
            }
        }

        wstaw(p);
    }
}
