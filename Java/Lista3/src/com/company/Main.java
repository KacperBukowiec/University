package com.company;

public class Main {

    public static void main(String[] args) throws Exception {
        Para p = new Para("s",1.0);
        Para p1 = new Para("f",1.0);
        Para p2 = new Para("g",1.0);
        Para p3 = new Para("r",1.0);
        Para p4 = new Para("re",1.0);
        //Para p3 = new Para("r",1.0);

        Para p5 = new Para("rsdf",1.0);
        ZbiorNaTablicy x = new ZbiorNaTablicy(2);
        ZbiorNaTablicyDynamicznej y = new ZbiorNaTablicyDynamicznej();
        //x.wstaw(p);
        //x.wstaw(p1);
        //x.wstaw(p2);

        y.wstaw(p);
        y.wstaw(p1);
        y.wstaw(p2);
        y.wstaw(p3);
        y.wstaw(p4);
        y.wstaw(p5);

    }
}
