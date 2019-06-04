 #include "wydarzenie.hpp"
using namespace std;
Wydarzenie::Wydarzenie(Datagodz t, string name)
{
    czas=t;
    nazwa=name;
}
bool Wydarzenie::operator<(Wydarzenie const& z)
    {
        return czas<z.czas;

    }
