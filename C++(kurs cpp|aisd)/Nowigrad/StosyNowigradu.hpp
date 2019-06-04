#ifndef STOSYNOWIGRADU_H
#define STOSYNOWIGRADU_H

#include <iostream>


using namespace std;

class Stos
{
    private:
        int Size;
        int IloscE = 0 ;
        string *Tablica;

        Stos(int Janek);
        Stos();
        Stos(initializer_list< string > &Lista);
        Stos(const Stos &stos);
        Stos(Stos &&);
        ~Stos();


        void wloz(string Radowid);
        string sciagnij();
        string sprawdz();
        int rozmiar();
};

#endif // STOSYNOWIGRADU_
