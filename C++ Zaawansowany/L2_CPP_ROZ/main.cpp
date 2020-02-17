#include <iostream>
#include <random>
#include <memory>
#include <cstdlib>

using  namespace std;


class Licznik{

    //Licznik()= default;

public:
    auto operator*= (uint64_t n) -> Licznik& {
        this->counter *= n;
        return *this;
    }

    uint64_t counter = 1;
};


int random(int n){
    return rand() % n;
}

vector<uint64_t> construct_primes(int n){
    vector<uint64_t> primes = {2};
    bool is_prime;
    uint64_t prime_candidate = 2;
    while (primes.size()<n){
        //std::cout << primes[1] << std::endl;
        prime_candidate++ ;
        //std::cout << prime_candidate << std::endl;
        is_prime = true;
        for (auto p : primes){
            if (prime_candidate % p == 0){
                is_prime = false;
                break;
            }
        }
        if (is_prime){
            primes.push_back(prime_candidate);
        }

    }

    return primes;
    //for (auto p : primes){
    //    int rand = random(n);
    //}
}


void recursion(vector<uint64_t > vec_primes,unique_ptr<Licznik[]>& array, int i, int m){
    if (i==m){
        return;
    }
    array[random(vec_primes.size())] *= vec_primes[i];
    return recursion(vec_primes,array,i+1,m);
}

int main() {

    int n = 5;
    int m = 5;

    unique_ptr<Licznik[]>   tab{new Licznik[n]};

    recursion(construct_primes(5),tab,0,m);


    for (int i=0;i<n;i++){
        cout << tab[i].counter << endl;
    }
    //for (int i=0;i<10;i++){
    //    tab[i] = *new Licznik();
    //}
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}