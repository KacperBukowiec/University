#include "datagodz.hpp"
using namespace std;



    Datagodz::Datagodz()
    {
    SYSTEMTIME st;
    GetLocalTime(&st);
    setDay(st.wDay);
    setMonth(st.wMonth);
    setYear(st.wYear);
    hour=st.wHour;
    minute=st.wMinute;
    second=st.wSecond;
    }
    Datagodz::Datagodz(int dzien,int miesiac,int rok,int sekunda,int minuta,int godzina)
    {
    setDay(dzien);
    setMonth(miesiac);
    setYear(rok);
    hour= godzina;
    minute= minuta;
    second= sekunda;
    }
    Datagodz& Datagodz::operator--(int)
        {
        second--;
        if(second==-1)
        {
            second=59;
            minute--;
            if(minute==-1)
            {
                minute=59;
                hour--;
                if(hour==-1)
                {
                    hour=23;
                    this->Data::operator--(3);
                    /*
                    setDay(getDay()-1);
                    int p=0;
                    if (Data::przestepny(getYear()))
                        p=1;
                    if (getDay()==-1)
                    {
                        setMonth(getMonth()-1);

                        if (getMonth()==0)
                        {
                            setMonth(12);
                            setYear(getYear()-1);
                        }
                        setDay(dniwmiesiacach[p][getMonth()]);
                    }
                }Datagodz::
                */

                }
            }

        }
        return *this;
    }
    Datagodz& Datagodz::operator++(int)
    {
        second++;
        if(second==60)
        {
            second=0;
            minute++;
            if(minute==60)
            {
                minute=0;
                hour++;
                if(hour==24)
                {
                    hour=0;
                    this->Data::operator++(3);
                }
            }
        }
        return *this;
    }

    Datagodz& Datagodz::operator+=(const int & n)
    {
        for(int i=0;i<n;i++)
        {
            this->operator++(42);
        }
        return *this;
    }
    Datagodz& Datagodz::operator-=(const int & n)
    {
        for(int i=0;i<n;i++)
        {
            this->operator--(42);
        }
        return *this;
    }
    bool Datagodz::operator==(Datagodz const& z)
    {

        auto a=make_tuple(getYear(),getMonth(),getDay(),getHour(),getMinute(),getSecond());
        auto b=make_tuple(z.getYear(),z.getMonth(),z.getDay(),z.getHour(),z.getMinute(),z.getSecond());
        return a==b;
    }
    bool Datagodz::operator<(Datagodz const& z)
    {

        auto a=make_tuple(getYear(),getMonth(),getDay(),getHour(),getMinute(),getSecond());
        auto b=make_tuple(z.getYear(),z.getMonth(),z.getDay(),z.getHour(),z.getMinute(),z.getSecond());
        return a<b;

    }
    int Datagodz::getHour() const
    {
        return hour;
    }
    int Datagodz::getMinute() const
    {
        return minute;
    }
    int Datagodz::getSecond() const
    {
        return second;
    }
    void  Datagodz::setHour(int x)
    {
        hour=x;
    }
    void  Datagodz::setSecond(int x)
    {
        second=x;
    }
    void  Datagodz::setMinute(int x)
    {
        minute=x;
    }
