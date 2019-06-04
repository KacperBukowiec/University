#include "Prosta.h"
#include <stdexcept>
#include <cmath>



    void Prosta::normalizuj(double aa,double bb, double cc)
    {
        double mi;
        if (c<0)
            mi =1/sqrt(aa*aa+bb*bb);
        else
            mi =(-1)/sqrt(aa*aa+bb*bb);
        a = aa*mi;
        b = bb*mi;
        c = cc*mi;
    }
    bool Prosta::prostpadly_wektor(const Wektor &wektor1)
    {
        if ((wektor1.dx == a)&&(wektor1.dy == b))
            return true;
        else
            return false;
    }

    bool Prosta::punkt_na(const Punkt &punkt1)
    {
        if( abs(a*punkt1.x + b*punkt1.y + c) <0.01)
            return true;
        else
            return false;
    }

    Prosta::Prosta(double pa,double pb, double pc)
    {
        if (pa==0 || pb==0 || pc==0)
        {
            throw invalid_argument("nie mo¿na utwo¿yæ prostej");
        }
        normalizuj(pa,pb,pc);
    }

    //Prosta::Prosta(const Prosta &prosta)
    //{
    //    normalizuj(prosta.a,prosta.b,prosta.c);
    //}

    Prosta::Prosta(const Punkt &punkt1, const Punkt &punkt2)
    {
        if (punkt1.x==punkt2.x && punkt1.y==punkt2.y)
            throw invalid_argument("nie mo¿na jednoznacznie utworzyæ prostej");
        normalizuj(punkt2.y - punkt1.y,punkt1.x - punkt2.x,punkt2.x * punkt1.y - punkt1.x * punkt2.y);
    }

    Prosta::Prosta(const Prosta prosta, const Wektor &wektor)
    {
        normalizuj(prosta.a , prosta.b , prosta.c - (prosta.a * wektor.dx) - wektor.dy);
    }

    Prosta::Prosta(const Wektor &wektor)
    {
        Punkt pom(wektor.dx, wektor.dy);
        double wzr = -1/(wektor.dx / wektor.dy);
        normalizuj(-wzr,1,-(pom.y - wzr * pom.x));
    }

    double Prosta::getA() const
    {
        return a;
    }
    double Prosta::getB() const
    {
        return b;
    }
    double Prosta::getC() const
    {
        return c;
    }
