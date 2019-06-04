#include <iostream>
#include "StosyNowigradu.hpp"

using namespace std;

int main()
{
    bool koniec = false;
    int s;
    while (true)
        {

            cout <<  "1 - Dodaj element na stos" << endl;
            cout <<  "2 - Sprawdz element na stosie" << endl;
            cout <<  "3 - Zdejmij element z stosu" << endl;
            cout <<  "4 - Sprawdz rozmiar stosu" << endl;
            cout <<  "5 - Koniec" << endl;
            cin >> s;
            switch (s)
            {
                case 1:
                    cout << "Podaj element listy który chcesz wypisaæ?" << endl;
                    //z = Console.ReadLine();
                    //Console.WriteLine(lista.Element(Int32.Parse(z)));
                    break;
                case 2:
                    cout << "Podaj element listy który chcesz wypisaæ?" << endl;
                    //z = Console.ReadLine();
                    //Console.WriteLine(listap.Element(Int32.Parse(z)));
                    break;
                case 3:
                    koniec = true;
                    break;
                default:
                    koniec = true;
                    break;

            }

            //Console.WriteLine("Naciœnij dowolny klawisz");
            //Console.ReadLine();
            if (koniec)
                break;
        }


    cout << "Hello world!" << endl;
    return 0;
}
