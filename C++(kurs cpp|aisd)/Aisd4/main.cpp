#include <iostream>
#include <math.h>
#include <float.h>
#include <stdlib.h>
using namespace std;

//http://www.cplusplus.com/reference/cstdlib/qsort/
//funkcje do quicksorta


struct Punkt
{
    long long int x, y;
};

struct Wynik{
    Punkt p1,p2;
    double min;
};

int compareX(const void* a, const void* b)
{
    Punkt *p1 = (Punkt *)a,  *p2 = (Punkt *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
    Punkt *p1 = (Punkt *)a,   *p2 = (Punkt *)b;
    return (p1->y - p2->y);
}

double odl(Punkt p1, Punkt p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
    );
}

Wynik mini4(Punkt P[],long long int n)
{
    Wynik w;
    double min = DBL_MAX;
    for (long long int i = 0; i < n; ++i)
        for (long long int j = i+1; j < n; ++j)
            if (odl(P[i], P[j]) < min){
                min = odl(P[i], P[j]);
                w.min = min;
                w.p1 = P[i];
                w.p2 = P[j];

            }

    return w;
}

Wynik stripClosest(Punkt part[],long long int size, double d)
{
    Wynik w;
    w.min = DBL_MAX;
    double min = d;
    for (long long int i = 0; i < size; i++)
        for (long long int j = i+1; (j < size) && ((part[j].y - part[i].y) < min); j++)
            if (odl(part[i], part[j]) < min){
                min = odl(part[i], part[j]);
                w.p1.x = part[i].x;
                w.p2.x = part[j].x;
                w.p1.y = part[i].y;
                w.p2.y = part[j].y;
                w.min = min;


            }


    return w;
}


Wynik mainLoop(Punkt *Px, Punkt *Py, long long int n) {

    Wynik w;
    if (n <= 3)
        return mini4(Px, n);


    long long int srodek = n / 2;
    Punkt srP = Px[srodek];

    Punkt Pyl[srodek + 100];
    Punkt Pyr[n - srodek + 100];
    int long long li = 0, ri = 0;
    for (long long int i = 0; i < n; i++) {
        if (Py[i].x <= srP.x){
            Pyl[li] = Py[i];
            li++;
        }

        else{
            Pyr[ri] = Py[i];
            ri++;
        }
    }

    Wynik dl = mainLoop(Px, Pyl, srodek);
    Wynik dr = mainLoop(Px + srodek, Pyr, n - srodek);

    double d = min(dl.min, dr.min);
    w.min = d;

    if (dl.min == w.min) {
        w.p1 = dl.p1;
        w.p2 = dl.p2;
    } else {
        w.p1 = dr.p1;
        w.p2 = dr.p2;
    }


    Punkt strip[n];
    long long int j = 0;
    for (long long int i = 0; i < n; i++) {
        if (abs(Py[i].x - srP.x) < d) {
            strip[j] = Py[i];
            j++;

        }
    }

    Wynik w2;
    w2 = stripClosest(strip, j, d);

    if (w.min < w2.min){
        return  w;
    }
    else{
        return w2;
    }

}
int main() {

    long long int n,x,y;

    scanf("%lld", &n);
    getchar();
    Punkt P[n];
    for (long long int i=0;i<n;i++){
        scanf("%lld %lld", &x, &y);
        P[i].x=x;
        P[i].y=y;
    }

    Punkt Px[n];
    Punkt Py[n];
    for (long long int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }

    n = sizeof(P) / sizeof(P[0]);

    qsort(Px, n, sizeof(Punkt), compareX);
    qsort(Py, n, sizeof(Punkt), compareY);

    //for (int i=0;i<n;i++){
    //    cout << Px[i].x << " q" << Px[i].y << endl;
    //}
    //for (int i=0;i<n;i++){
    //    cout << Py[i].x << " q2" << Py[i].y << endl;
    //}
    Wynik w = mainLoop(Px, Py, n);
    cout << w.p1.x << " " << w.p1.y << endl;
    cout << w.p2.x << " " << w.p2.y << endl;
    //cout << w.min << "dist" <<  endl;

    return 0;
}