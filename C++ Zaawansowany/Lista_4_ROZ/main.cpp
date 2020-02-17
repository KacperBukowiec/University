#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

template <typename MMS>
auto mm(MMS& i){
    auto min = i.begin();
    auto max = i.begin();
    auto current = i.begin();

    for_each(i.begin(),i.end(),[&](auto x){
        if (x < *min){
            min = current;
        }
        if(x>*max){
            max =current;
        }
        current++;
    });
    return pair{min,max};
    }


vector<double> v = {1.3,23.2,5.0,3.5,2.6,23.65,23423.5};
list<string> l = {"a","b","c","d","e","f","g","h","ii"};
set<int> s = {1,3,5,7,9,11,34};


int main() {
    int x=1;
    int y=10;
    //string x="c";
    //string y="g";
    auto lam = [=](auto i)
    {
        if (i >x && i<y) {
            std::cout << i << endl;
        }
    };
    //for_each(v.begin(), v.end(),lam);
    //for_each(s.begin(), s.end(),lam);
    //for_each(l.begin(), l.end(),lam);

    int p = 2;
    int k=2;
    auto lam2 = [=](auto i)
    {
        static int licznik = 0;
        if (licznik >= p && (licznik % k == 0)) {
            std::cout << i << endl;
        }
        licznik++;
    };
    //for_each(v.begin(), v.end(),lam2);
    //for_each(l.begin(), l.end(),lam2);
    //for_each(s.begin(), s.end(),lam2);

    double sum =0;
    int licznik = 0;
    auto lam3 = [&](auto i)
    {
        licznik++;
        sum += i;
    };
    //for_each(v.begin(), v.end(),lam3);
    //cout << sum/licznik << endl;

    //sum =0;
    //licznik = 0;
    //for_each(s.begin(), s.end(),lam3);
    //cout << sum/licznik << endl;


    //auto lam4 = [=](auto i)
    //{
    //    return total + i;
    //};


    auto minmax = mm<vector<double>>(v);
    cout << *get<0>(minmax) << ' ' << *get<1>(minmax) << endl;
    auto minmax1 = mm<set<int>>(s);
    cout << *get<0>(minmax1) << ' ' << *get<1>(minmax1) << endl;
    auto minmax2 = mm<list<string>>(l);
    cout << *get<0>(minmax2) << ' ' << *get<1>(minmax2) << endl;
    //cout << *vmin << " " << *vmax << endl;
    //cout << *smin << " " << *smax << endl;
    //cout << lmin << " " << *lmax << endl;


    auto lam5 = [](auto total, auto i)
    {
        return total + i;
    };
    cout << accumulate(v.begin(),v.end(),0.0,lam5) << endl;

    cout << accumulate(l.begin(),l.end(),string(),lam5) << endl;
    cout << accumulate(s.begin(),s.end(),0.0,lam5) << endl;
    return 0;
}