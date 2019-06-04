#include <iostream>
#include <time.h>
#include <windows.h>
#include "data.hpp"
#include <tuple>


class Datagodz final : public Data
{
    private:
    int hour;
    int minute;
    int second;
    public:
    Datagodz();
    Datagodz(int dzien,int miesiac,int rok, int sekunda, int minuta, int godzina);
    Datagodz& operator--(int);
    Datagodz& operator++(int);
    Datagodz& operator+=(const int & n);
    Datagodz& operator-=(const int & n);
    bool operator==(Datagodz const& z);
    bool operator<(Datagodz const& z);
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void setHour(int x);
    void setSecond(int x);
    void setMinute(int x);




};
