#include "StosyNowigradu.hpp"




Stos::Stos(int Janek)
{
    Size = Janek;
    Tablica = new string[Size];
}

Stos::Stos()
{
    Size = 1;
    Tablica = new string[Size];
}

Stos::Stos(initializer_list<string> &Lista)
{
    Size = Lista.size();
    Tablica = new string[Size];
    IloscE = Size;
    for(int i=0; i<Size ; i++)
    {
        Tablica[i] = Lista[i];
    }
}

Stos::Stos(const Stos &stos)
{
    Size = stos.Size();
    IloscE = Size;
    Tablica = new string[Size];
    for(int i=0; i<Size ; i++)
    {
        Tablica[i] = stos[i]
    }
}
//??????????????????????????????????????????????
Stos::Stos(const Stos &&stos)
{
    Size = stos.Size();
    IloscE = Size;
    Tablica = new string[Size];
    for(int i=0; i<Size ; i++)
    {
        Tablica[i] = stos[i]
    }
    Tablica = nullptr;
}


Stos::~Stos()
{
    delete Tablica;
}

Stos::rozmiar()
{
    return IloscE;
}


Stos::sciagnij()
{
    IloseE = IloscE - 1;
    return Tablica[IloscE + 1];
}

Stos::sprawdz()
{
    return Tablica[IloscE]
}

Stos::wloz(string Radowid)
{
    if(Size=IloscE)
    {
        string* temp = new string[Size+1];
        for(int i=0; i<Size ; i++)
        {
            temp[i] = Tablica[i];
        }
        temp[Size + 1] = Radowid;
        Size++;
        delete Tablica;
        Tablica = temp;
    }
    else
    {
        Tablica[IloscE+1] = Radowid;
    }
    IloscE++;

}



















