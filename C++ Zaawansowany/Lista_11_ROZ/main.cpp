#include <iostream>



template<long long n>
struct lucas
{
    static constexpr long long value = lucas<n - 1>::value + lucas<n - 2>::value;

    constexpr long long operator()(){
        return lucas<n>::value;
    }
};
template<>
struct lucas<0>
{
    static constexpr long long value = 2;
};
template<>
struct lucas<1>
{
    static constexpr long long value = 1;
};


template<int n, int k>
struct Binomial
{
    static constexpr int value =  Binomial<n-1,k-1>::value * n/k;

    constexpr int operator()(){
        return Binomial<n,k>::value;
    }
};

template<>
struct Binomial<0,0>
{
    static constexpr int value = 1;
};

template<int n>
struct Binomial<n,0>
{
    static constexpr int value = 1;
};

template<int n>
struct Binomial<n,n>
{
    const static int value = 1;
};


template<long long a, int b> struct gcd
{
    static constexpr long long value = gcd<b, a % b>::value;

    constexpr int operator()(){
        return gcd<b,a>::value;
    }
};

template<long long a>
struct gcd<a, 0>
{
    static constexpr long long value = a;
};


int main()
{
    std::cout << lucas<70>()() << std::endl;
    std::cout << Binomial<31,12>()() << std::endl;
    std::cout << gcd<63359,70813>()() << std::endl;

    return 0;
}



//#int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}
