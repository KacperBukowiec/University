#include <iostream>
#include <array>
#include <algorithm>
#include <random>
#include <fstream>

template <typename T, int N>
void shuff(std::array<T,N>& arr) {
    static std::mt19937 gen {std::random_device{}()};
    std::shuffle(arr.begin(), arr.end(), gen);
}


int main() {
    std::array<int , 10> arr{};
    for (int i=0;i<10;i++){
        arr[i]=i;
    }

    shuff<int, 10>(arr);

    for(int i=0;i<10;i++){
        std::cout << arr[i] << std::endl;
    }


    auto u_d = std::uniform_real_distribution<double >{0, 200};
    auto b_d = std::binomial_distribution<int>{60, 0.6};
    auto n_d = std::normal_distribution<double>{50, 5};
    std::mt19937 gen {std::random_device{}()};

    std::ofstream unifo("u.txt");
    std::ofstream binomial("b.txt");
    std::ofstream normal("n.txt");

    for (int i = 0; i < 1000; i++) {
        unifo << u_d(gen) << std::endl;
        binomial << b_d(gen) << std::endl;
        normal << n_d(gen) << std::endl;
    }



    return 0;
}