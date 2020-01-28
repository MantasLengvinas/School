#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const char FD[] = "srautai.data";
const char FR[] = "srautai.res";

const int MaxP = 100;
const int Max = 24;

void Duomenys(int P[], int &n);
void Srautai(int n, int P[], int PrH[], int PrM[], int PbH[], int PbM[], int kiekP[]);

int main(){

    int P[MaxP]; //Pirkejai
    int PrH[Max], PrM[Max], PbH[Max], PbM[Max], kiekP[Max]; //Masyvai laikams
    int n;

    Duomenys(P, n);
    Srautai(n, P, PrH, PrM, PbH, PbM, kiekP);


    return 0;
}

void Duomenys(int P[], int &n){

    ifstream fd(FD);
    int h, m, l;

    fd>>n;

    for(int i = 0; i < n; i++){
        fd>>h>>m;
        l = h * 60 + m;
        P[i] = l;
    }

    fd.close();

}

void Pusvalandziai(int PrH[], int PrM[], int PbH[], int PbM[], int kiekP[]){

    for(int i = 0; i < 24; i++){

    }

}

void Srautai(int n, int P[], int PrH[], int PrM[], int PbH[], int PbM[], int kiekP[]){
    int P0 = 480, P1 = 1200;

    for(int i = 0; i < )
}
