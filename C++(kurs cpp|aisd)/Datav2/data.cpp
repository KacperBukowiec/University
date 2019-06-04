#include "data.hpp"
#include <stdexcept>
using namespace std;
int Data::dniodpoczroku[2][13] = {
{0,31,59,90,120,151,181,212,243,273,304,334,365}, // lata zwyk³e
{0,31,60,91,121,152,182,213,244,274,305,335,366} // lata przestêpne
};

int Data::dniwmiesiacach[2][13] = {
{0,31,28,31,30,31,30,31,31,30,31,30,31}, // lata zwyk³e
{0,31,29,31,30,31,30,31,31,30,31,30,31} // lata przestêpne
};

Data::Data()
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    day = st.wDay;
    month = st.wMonth;
    year = st.wYear;
}


Data::Data(int dzien, int miesiac, int rok)
{
    day = dzien;
    month = miesiac;
    year = rok;
    if (!poprawna())
    {
        throw invalid_argument("zła data");
    }


}

int Data::iledni() const
{
    int przes=year/4 - year/100 + year/400;
    int p=0;
    if (Data::przestepny(year))
        p=1;
    return (przes*366+(year-przes)*365+dniodpoczroku[p][month-1]+day)-1;
}



bool Data::poprawna()
{
    if((year==1582)&&(month==10)&&(day>4)&&(day<15))
        return false;
    int p=0;
    if (Data::przestepny(year))
        p=1;
    if (day>dniwmiesiacach[p][month] || month>12)
        return false;
    return true;
}

//do z;robienia
int Data::operator -(Data const& d)
{
    /*
    int y = year - d.year;
    int m=month-d.month+1;
    int da=day-d.day+1;

    if (m<1)
    {
        y--;
        m+=12;
    }
    if (da<1)
        m--;
    if (m<1)
    {
        y--;
        m+=12;
    }
     if(da<0)
     {
         m--;
         da=da+dniwmiesiacach[0][m];
     }
    // cout << da << m << y << endl;
    Data z(da,m,y);
    */
    return this->iledni() - d.iledni();
}

Data& Data::operator ++(int)
{
    if((year==1582)&&(month==10)&&(day==4))
    {
        day=15;
        return *this;
    }
    day++;
    int p=0;
    if (Data::przestepny(year))
        p=1;
    if (day==(dniwmiesiacach[p][month]+1))
    {
        month++;
        day=1;
        if (month==13)
        {
            year++;
            month=1;
        }

    }
    return *this;
}


 Data& Data::operator --(int)
{

    if((year==1582)&&(month==10)&&(day==15))
    {
        day=4;
        return *this;
    }
    int p=0;
    if (Data::przestepny(year))
        p=1;
    if (day==1)
    {
        if (month==1)
        {
            year--;
            day=31;
            month=12;
        }
        month--;
        day=dniwmiesiacach[p][month];
    }
    day--;
    return *this;
}

Data& Data::operator+=(const int & n)
{
    for(int i=0;i<n;i++)
    {
        this->operator++(42);
    }
    return *this;
}

Data& Data::operator-=(const int & n)
{
    for(int i=0;i<n;i++)
    {
        this->operator--(42);
    }
    return *this;
}

bool Data::przestepny(int year)
{
    if (year%4==0)
    {
        if (year%100==0)
        {
            if (year%400==0)
                return true;
            return false;
        }
        return true;
    }
    return false;
}

    int Data::getDay() const
    {
        return day;
    }
    int Data::getMonth() const
    {
        return month;
    }
    int Data::getYear() const
    {
        return year;
    }
    void Data::setDay(int x)
    {
        day=x;
    }
    void Data::setMonth(int x)
    {
        month=x;
    }
    void Data::setYear(int x)
    {
        year=x;
    }
