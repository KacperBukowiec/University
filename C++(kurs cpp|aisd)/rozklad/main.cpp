#include <iostream>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

bool  is_prime(int64_t number)
{
    int64_t square;
    square = sqrt(number);
    if (number%2==0)
        return false;
    if (number%3==0)
        return false;
    for (int64_t i=6;i<=square;i=i+6)
    {
        if(number%(i+1)==0||number%(i-1)==0)
        {
            return false;
        }

    }
    return true;
}


vector<int64_t> rozklad(int64_t liczba)
{
    int64_t dzielnik;
    dzielnik=2;
    vector<int64_t> wektor;
    if (liczba<0)
    {
        wektor.push_back(-1);
    //    liczba = liczba * -1;
    }
    while (liczba > 1||liczba<-1)
    {
        if (liczba%dzielnik==0)
        {
            wektor.push_back(dzielnik);
            liczba = liczba/dzielnik;
        }
        else
        {
            dzielnik++;
        }
    }
    return wektor;
}

void wypisz(vector<int64_t> wektor, int64_t liczba)
{
    bool straz = true;
    straz = 1;
    cout << liczba << " = ";
    for (int64_t i : wektor)
    {
        if(!straz)
            cout << " * ";
        else
            straz = false;
        cout << i;

    }
    cout << endl;
}

int64_t zmien(string str)
{
    int64_t out=0;
    int64_t licznik=1;
    if(str[0]=='-')
    {
        for(int i=str.length()-1;i>0;i--)
        {
        out = out + (int)(str[i]-'0') * licznik;
        licznik = licznik*10;
        }
    return out* -1 ;
    }
    else
    {
    for(int i=str.length()-1;i>-1;i--)
    {
        out = out + (int)(str[i]-'0') * licznik;
        licznik = licznik*10;
    }
    return out;
    }
}


int main(int argc, char** argv)
{
    //if (argc == 1)
    //{
    //    cerr << "rozklad.exe <<Brak liczby do rozkladu>>" <<endl;
    //}
    //vector<int64_t> kop;
    //kop=rozklad(1024);
    //wypisz(kop);
    //cout << atoll(argv[1]) <<endl;
    int64_t zmienna;
    string lancuch;
    for (int i = 1;i<argc;i++)
    {
        lancuch=string(argv[i]);
        zmienna=zmien(lancuch);


        //zmienna = atoll(argv[i]);
        if (is_prime(zmienna)==1)
            cout << zmienna << " = " << zmienna << endl;
        else
            wypisz((rozklad(zmienna)),zmienna);
    }
    //cout << is_prime(9223372036854775783)<< endl;
    return 0;
}
