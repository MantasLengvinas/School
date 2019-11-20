// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

void Duomenys(int &a, int &b, int &c, int &d);

int Dazymas(int &N, int &V, int &Z, int &T);

int main(){

    int N, V, Z, T;

    Duomenys(N, V, Z, T);
    cout<<Dazymas(N, V, Z, T);

    return 0;
}

void Duomenys(int &a, int &b, int &c, int &d){
    cin>>a>>b>>c>>d;
}

int Dazymas(int &N, int &V, int &Z, int &T){

    int kiek = 0;

    if(N <= 1000 && N >= 1 && V >= 1 && V <= 100 && Z >= 1 && Z <= 100 && T >= 0 && T <= 100000){
        if(T != 0 && V != Z){
            kiek = V - T;
            for(int i = 0; i < N-1; i++){
                kiek += Z - V;
            }
        }
        else{
            kiek = V;
        }
    }

    return kiek;

}
