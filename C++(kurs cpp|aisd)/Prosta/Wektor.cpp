#include "Wektor.h"


    Wektor::Wektor(const Wektor &wektor)
         : dx(wektor.dx),dy(wektor.dy){}


    Wektor::Wektor(double x,double y)
    : dx(x),dy(y){}
