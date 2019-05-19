#include <iostream>

int main() {
    long long n,temp ;
    long long sum=0;
    long long sP,sL,naj,max=0;
    max=0;

    std::cin >> n;
    int tab[n];

    for (int i=0;i<n;i++){
        std::cin >> temp;
        sum+=temp;
        tab[i] = temp;
    }
    naj = sum/2;


    long long mP=0, mL = 0;     //miejsca
    sP=0;
    for(int i=0;i<n;i++){
        sP += tab[i];
        if (sP>naj){
            sP-=tab[i];
            mP = i-1;
            break;
        };
    }
    sL=0;

    for(int i=0;i<n;i++){
        sL += tab[n-1-i];
        if (n-i-2==mP){
            //sL-=tab[n-1-i];
            mL=n-i-1;
            break;
        };
    }
    if (sL>sP){
        if(sP>max){
            max=sP;
        }
    }
    else{
        if(sL>max){
            max=sL;
        }
    }


    int przesP=0;
    for (int i=0;i<n;i++){
        przesP=0;
        sP-=tab[i];
        sL+=tab[i];
        while (sP<=naj){
            mP++;
            przesP++;
            if (mP==n){
                mP=0;
            }
            sP+=tab[mP];

        }
        sP-=tab[mP];
        mP--;
        przesP--;
        if (mP==-1){
            mP=n-1;
        }
        if (sP==0){
            przesP++;
            mP++;
            sP+=tab[mP];
        }


        for (int j=0;j<przesP;j++){
            sL-=tab[mL];
            mL++;
            if (mL==n){
                mL=0;
            }

        }


        if (sL>sP){
            if(sP>max){
                max=sP;
            }
        }
        else{
            if(sL>max){
                max=sL;
            }
        }

    }
    std::cout << max << std::endl;


    return 0;
}