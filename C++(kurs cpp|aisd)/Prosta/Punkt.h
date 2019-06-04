#ifndef PUNKT_H
#define PUNKT_H

#include <iostream>
#include "Wektor.h"
using namespace std;

class Punkt
{
    public:
        const double x=0;
        const double y=0;
    Punkt operator=(const Punkt&) = delete;
    Punkt() = default;
    Punkt(double wspx,double wspy);
    Punkt(const Punkt &punkt);
    Punkt(const Punkt &punkt, const Wektor &wektor);
    void wypisz ();

};

#endif // PUNKT_H
