package com.company;

public class Para {
    public final String key;
    private double value;


    public Para(String k,double v) throws Exception {
        //Wyjątki
        if(k=="" || k==null){
            throw new Exception("key can not be empty");

        }
        key = k;
        value = v;

    }

    public double getValue(){
        return value;
    }
    public void setValue(double x){
        value = x;
    }

    public String toString(){
        return key + " : " + Double.toString(value);
    }
    @Override
    public boolean equals(Object other){
        if (!(other instanceof  Para)) return false;
        if (((Para) other).key==key) return true;
        else return false;

    }
}
