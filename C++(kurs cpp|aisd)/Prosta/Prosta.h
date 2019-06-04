#ifndef PROSTA_H
#define PROSTA_H

#include <iostream>
#include "Punkt.h"
#include "Wektor.h"
using namespace std;

class Prosta
{
    private:
        double a;
        double b;
        double c;
    public:
        Prosta operator=(const Prosta&) = delete;
        Prosta() = default;
        Prosta(double pa, double pb, double pc);
        Prosta(const Prosta &prosta) = delete;
        Prosta(const Punkt &punkt1, const Punkt &punkt2);
        Prosta(const Prosta prosta, const Wektor &wektor);
        Prosta(const Wektor &wektor);
        void normalizuj(double aa,double bb, double cc);
        bool prostpadly_wektor(const Wektor &wektor1);
        bool punkt_na(const Punkt &punkt1);

        double getA() const;
        double getB() const;
        double getC() const;
};

#endif // PROSTA_H
