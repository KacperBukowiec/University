#include <iostream>
#include <iomanip>
#include <complex>
#include <fstream>
//#include <cmath>
#include <bits/stdc++.h>
//using namespace std::complex_literals;
//using  namespace std;


int main()
{

    //std::cout << std::fixed << std::setprecision(1);

    std::complex<double> z = 1 + 1i;
    std::complex<double> out = 1;
    int a=10;
    for (double n=1.0;n<100000;n++){
        out *= std::pow(1.0 + 1.0/n,z)/(1.0+z/n);
    }
    out = 1.0/z * out;
    std::cout << "1 =" << out << '\n';

    out=1;
    double y =0.5772156649;
    const double e = 2.71828182845904523536;
    for (double n=1.0;n<100000;n++){
        out *= (1.0+z/n)*std::pow(e,-z/n);
    }
    out = z*std::pow(e,y*z)*out;
    std::cout << "2 = " << out << '\n';

    /*
    std::complex<double> out2 = 0;
    std::complex<double> z2 = 0.5 + 1i;

    std::ofstream offff("d.csv");
    for (double a=-20.0;a<20;a+=0.2) {
        out2=0;
        std::complex<double> h = 1i;
        h = h*a;
        std::complex<double> z2 = 0.5 + h;
        //std::cout << "z2:  " << z2 << '\n';
        for (double n = 1.0; n < 100000; n++) {
            out2 += std::pow(-1.0,n+1) / std::pow(n,z2);
        }
        out2 = out2/(1.0-(2.0/std::pow(2,z2)));
        offff << a << ";" << out2.real() << ";" << out2.imag() << '\n';
    }


    */
    // imaginary unit squared
    //std::cout << "i * i = " << z1 << '\n';

    //std::complex<double> z2 = std::pow(z1, 2); // imaginary unit squared
    //std::cout << "pow(i, 2) = " << z2 << '\n';

    //double PI = std::acos(-1);
    //std::complex<double> z3 = std::exp(1i * PI); // Euler's formula
    //std::cout << "exp(i * pi) = " << z3 << '\n';

    //std::complex<double> z4 = 1. + 2i, z5 = 1. - 2i; // conjugates
    //std::cout << "(1+2i)*(1-2i) = " << z4*z5 << '\n';
    return 0;
}