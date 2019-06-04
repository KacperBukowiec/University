#include "Wektor.h"
#include "Punkt.h"
#include "Prosta.h"
#include <cmath>

Wektor zlorz(Wektor wektor1, Wektor wektor2)
{
    Wektor cisz(wektor1.dx + wektor2.dx, wektor1.dy + wektor2.dy);
    return cisz;
}
bool rownolegle(const Prosta &prosta1,const Prosta &prosta2)
{
    if (abs((prosta1.getA() * prosta2.getB() - prosta2.getA() * prosta1.getB())) < 0.01)
        return true;
    else
        return false;
    }

Punkt przeciecie(const Prosta &prosta1,const Prosta &prosta2)
{
    double d ;
    d = prosta1.getA() * prosta2.getB() - prosta2.getA() * prosta1.getB();
    Punkt sa((prosta1.getB() * prosta2.getC() - prosta2.getB() * prosta1.getC())/d,-((prosta1.getA() * prosta2.getC() - prosta2.getA() * prosta1.getC())/d));
    return sa;
}

bool prostopadle(Prosta prosta1,Prosta prosta2)
{
    if ((prosta1.getA()-prosta2.getA()==atan(1)*2) ||(prosta1.getA()-prosta2.getA()==-atan(1)*2))
        return true;
    else
        return false;
}

