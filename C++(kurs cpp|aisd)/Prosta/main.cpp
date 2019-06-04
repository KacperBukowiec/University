#include <iostream>
#include "Wektor.h"
#include "Punkt.h"
#include "Prosta.h"
#include "Funkcje.h"
#include <cmath>
using namespace std;

int main()
{
    Wektor p1;
    Prosta pp(6,4,5);
    Prosta pp1(6,4,9);
    Prosta pp2(3,6,1);
    Prosta ds(Punkt (1,3),Punkt (5,8));

    cout << atan(1)*4 << endl;
    cout << rownolegle( pp , pp1 ) << endl;
    przeciecie(pp1,pp2).wypisz();
    cout << ds.punkt_na(Punkt (1,3)) <<endl;
    cout << pp.getA() << endl;
    cout << pp.getB() << endl;
    cout << pp.getC() << endl;

    return 0;
}

