#include <iostream>
#include <set>

#include <cstring>
#include <cmath>

using namespace std;
using str = set<string>;

enum class imie : uint16_t {
    Jakub,
    Kubus,
    Kuba,
    Rozpruwacz,
    Kubek,
    Puchatek
};

void oblicz_delte(double a, double b , double c){
    if (auto delta = b*b - 4*a*c;delta > 0){
        double x1 = (-b + sqrt(delta)) / 2 * a;
        double x2 = (-b - sqrt(delta)) / 2 * a;
        cout << "są dwa miejsca zerowe: " << x1 << " , " << x2 << endl;
    }
    else if (delta == 0){
        double x0 = -b/2*a;
        cout << "jest jedno miejsce zerowe: " << x0 << endl;
    }
    else{
        cout << "delta ujemna, nie ma miejsc zerowych" << endl;
    }

}

void wypisz(string komunikat, imie odbiorca){
    string odbiorca_str;
    switch (odbiorca){
        case imie::Jakub:
            odbiorca_str = "Jakub";
            break;
        case imie::Kubus:
            odbiorca_str = "Kubus";
            break;
        case imie::Kuba:
            odbiorca_str = "Kuba";
            break;
        case imie::Rozpruwacz:
            odbiorca_str = "Rozpruwacz";
            break;
        case imie::Kubek:
            odbiorca_str = "Kubek";
            break;
        case imie::Puchatek:
            odbiorca_str = "Puchatek";
            break;
    }

    cout << komunikat + " " + odbiorca_str << endl;
}

auto lucas(unsigned n){
    //if (n==0)
    //    return 2;
    //if (n==1)
    //   return 1;
    if (n<2)
        return 2-n;
    return lucas(n-1) + lucas(n-2);
}


int main() {

    //Zadanie 1
    cout << "jakib ??'" << endl;

    //Zadanie 2
    // A Normal string
    string string1 = " \")\"()()\"\"()\") " ;
    // A Raw string
    string string2 = R"d(\"(\"()(\)"")\"\"()\"))d";

    cout << string1 << endl;

    cout << string2 << endl;



    //zadanie 3
    str s{"ciszek", "a", "assasdf", "Jakub", "Grobelny",R"(TRYHARD)"};

    for (auto st : s){
        cout << st << endl;
    }

    //Zadanie 4
    wypisz("jakub to",imie::Jakub);

    //Zadanie 5
    cout << lucas(4) << endl;

    //Zadanie 6
    oblicz_delte(1,2,1);

    return 0;

    cout << string1 << endl;

    cout << string2 << endl;



    return 0;
}