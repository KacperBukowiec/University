#include <iostream>
#include <random>
#include <limits>
#include <cmath>
#include <chrono>
#include <ratio>
//using namespace std;
double mat_1[10][10];
double mat_2[100][100];
double mat_3[1000][1000];
double mat_4[10000][10000];
std::random_device r;

std::default_random_engine &global_urng( )
{
    static std::default_random_engine  u{r()};
    return u;
}

double pick_a_number( double from, double upto ){
static std::uniform_real_distribution<>  d{};
using  parm_t  = decltype(d)::param_type;
return d( global_urng(), parm_t{from, upto} );
}

void fill() {
    for (auto & i : mat_1) {
        for (double & j : i) {
            j = pick_a_number(0.5, 2.0);
        }
    }

    for (int i=0;i<100;i++) {
        for (int j = 0; j < 100; j++) {
            mat_2[i][j] = pick_a_number(0.5, 2.0);
        }
    }

    for (int i=0;i<1000;i++) {
        for (int j = 0; j < 1000; j++) {
            mat_3[i][j] = pick_a_number(0.5, 2.0);
        }
    }

    for (int i=0;i<10000;i++) {
        for (int j = 0; j < 10000; j++) {
            mat_4[i][j] = pick_a_number(0.5, 2.0);
        }
    }

}

void kwadrat10(){
    int n=10;
    double out[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            //mnozenie
            double sum =0;
            for (int k=0;k < n;k++){
                sum += mat_1[i][k]*mat_1[k][j];
            }
            out[i][j] = sum;
            sum =0;
        }
    }
}

void kwadrat100(){
    int n=100;
    double out[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            //mnozenie
            double sum =0;
            for (int k=0;k < n;k++){
                sum += mat_2[i][k]*mat_2[k][j];
            }
            out[i][j] = sum;
            sum =0;
        }
    }
}

void kwadrat1000(){
    int n=1000;
    double out[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            //mnozenie
            double sum =0;
            for (int k=0;k < n;k++){
                sum += mat_3[i][k]*mat_3[k][j];
            }
            out[i][j] = sum;
            sum =0;
        }
    }
}

void kwadrat10000(){
    int n=10000;
    double out[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            //mnozenie
            double sum =0;
            for (int k=0;k < n;k++){
                sum += mat_4[i][k]*mat_4[k][j];
            }
            out[i][j] = sum;
            sum =0;
        }
    }
}

template <int n>
struct harmoniczne : public std::ratio_add<std::ratio<1, n>, harmoniczne<n-1>> {};

template <>
struct harmoniczne<1> : public std::ratio<1, 1> {};


int main() {

    long long int maximum = std::numeric_limits<long long int>::max();
    long long int minimum = std::numeric_limits<long long int>::min();

    std::cout << minimum << std::endl;
    std::cout << maximum << std::endl;
    std::cout << sizeof(long long int) * 8 << std::endl;
    std::cout <<  std::ceil(std::log10(maximum)) << std::endl;

    std::cout << std::numeric_limits<float>::denorm_min() << std::endl;
    std::cout << std::numeric_limits<float>::max() << std::endl;
    std::cout << 1.0f-std::numeric_limits<float>::denorm_min() << std::endl;
    std::cout << std::numeric_limits<double>::denorm_min() << std::endl;
    std::cout << std::numeric_limits<double>::max() << std::endl;
    std::cout << 1.0-std::numeric_limits<double>::denorm_min() << std::endl;


    fill();

    auto t0 = std::chrono::high_resolution_clock::now();
    for (int i=0;i<1000;i++){
        kwadrat10();
    }
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time = std::chrono::duration_cast<std::chrono::duration<double>>(t1 - t0);
    std::cout << time.count()/1000  << std::endl;

    t0 = std::chrono::high_resolution_clock::now();
    kwadrat100();
    t1 = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::duration<double>>(t1 - t0);
    std::cout << time.count()  << std::endl;

    t0 = std::chrono::high_resolution_clock::now();
    kwadrat1000();
    t1 = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::duration<double>>(t1 - t0);
    std::cout << time.count()  << std::endl;

    //std::cout << harmoniczne<46>::num << "/" << harmoniczne<46>::den  << std::endl;
    return 0;
}