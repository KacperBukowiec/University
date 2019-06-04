#include <iostream>
#include <windows.h>
#include "wydarzenie.hpp"
#include <vector>
#include <algorithm>
using namespace std;
int64_t operator-(Datagodz& left,Datagodz& right)
{
    int64_t out=0;
    out+=left.getSecond()-right.getSecond();
    out+=(left.getMinute()-right.getMinute())*60;
    out+=(left.getHour()-right.getHour())*3600;
    out+=(left.getDay()-right.getDay())*3600*24;
    out+=(left.getMonth()-right.getMonth())*2629800;
    out+=(left.getYear()-right.getYear())*31557600;
    return out;
}

int main()
{
    Datagodz s(3,3,2018,11,11,12);
    Datagodz z(2,2,2017,11,11,11);
    Wydarzenie a(s,"1");
    Wydarzenie b(z,"2");

    vector<Wydarzenie> lista;
    lista.push_back(a);
    lista.push_back(b);
    sort(lista.begin(),lista.end());


    cout << "rajk"+"as" << endl;
    return 0;

}
