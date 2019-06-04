#ifndef WEKTOR_H
#define WEKTOR_H

#include <iostream>
using namespace std;

class Wektor
{
    public:
        const double dx=0;
        const double dy=0;
    Wektor operator=(const Wektor&) = delete;
    Wektor() = default;
    Wektor(const Wektor &wektor);
    Wektor(double x,double y);


};


#endif // WEKTOR_H
