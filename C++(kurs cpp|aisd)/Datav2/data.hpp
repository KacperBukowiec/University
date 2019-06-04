#include <iostream>
#include <time.h>
#include <windows.h>

class Data
{
    private:
       int year;
       int month;
       int day;


    public:
        int iledni() const;
        bool poprawna();
        Data& operator++(int);
        int operator-(Data const& d);
        Data& operator--(int);
        Data& operator+=(const int & n);
        Data& operator-=(const int & n);

        static bool przestepny(int year);
        Data();
        Data(int dzien, int miesiac, int rok);
        static int dniodpoczroku[2][13];
        static int dniwmiesiacach[2][13];

        int getDay() const;
        int getMonth() const;
        int getYear() const;
        void setDay(int x);
        void setMonth(int x);
        void setYear(int x);
};
