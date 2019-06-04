#include "Punkt.h"


    Punkt::Punkt(double wspx,double wspy)
    : x(wspx),y(wspy){}

    Punkt::Punkt(const Punkt &punkt)
    : x(punkt.x),y(punkt.y){}

    Punkt::Punkt(const Punkt &punkt, const Wektor &wektor)
    : x(punkt.x + wektor.dx),y(punkt.y + wektor.dy){}

    void Punkt::wypisz ()
    {
    cout << "x:" << x << "y:" << y << endl;
    }


