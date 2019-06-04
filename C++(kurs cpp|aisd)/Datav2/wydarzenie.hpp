#include "datagodz.hpp"



class Wydarzenie
{
    public:
    Datagodz czas;
    std::string nazwa;

    Wydarzenie(Datagodz t, std::string name);
    bool operator<(Wydarzenie const& z);






};
