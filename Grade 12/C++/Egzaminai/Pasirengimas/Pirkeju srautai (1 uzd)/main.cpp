#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const char FD[] = "srautai.data";
const char FR[] = "srautai.out";

const int MaxP = 100;
const int Max = 24;

void Duomenys(int P[], int &n);
void Srautai(int n, int P[], int PrH[], int PrM[], int PbH[], int PbM[], int kiekP[]);
void Pusvalandziai(int PrH[], int PrM[], int PbH[], int PbM[], int kiekP[]);
void Isvedimas(int PrH[], int PrM[], int PbH[], int PbM[], int kiekP[]);

int main(){

    int P[MaxP]; //Pirkejai
    int PrH[Max], PrM[Max], PbH[Max], PbM[Max], kiekP[Max]; //Masyvai laikams
    int n;

    Duomenys(P, n);
    Pusvalandziai(PrH, PrM, PbH, PbM, kiekP);
    Srautai(n, P, PrH, PrM, PbH, PbM, kiekP);
    Isvedimas(PrH, PrM, PbH, PbM, kiekP);

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
        kiekP[i] = 0;
    }
    for(int i = 0; i < 24; i += 2){
        PrM[i] = 0;
        PbM[i] = 30;
        PrM[i + 1] = 30;
        PbM[i + 1] = 0;
    }
    int val = 8;
    for(int i = 0; i < 24; i += 2){
        PrH[i] = val;
        PbH[i] = val;
        PrH[i + 1] = val;
        PbH[i + 1] = val + 1;
        val++;
    }
}

void Srautai(int n, int P[], int PrH[], int PrM[], int PbH[], int PbM[], int kiekP[]){

    int pr, pb;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 24; j++){
            pr = PrH[j] * 60 + PrM[j];
            pb = PbH[j] * 60 + PbM[j];
            if(P[i] > pr && P[i] < pb){
                kiekP[j]++;
            }
        }
    }

}

void Isvedimas(int PrH[], int PrM[], int PbH[], int PbM[], int kiekP[]){

    ofstream fr(FR);

    for(int i = 0; i < 24; i++){
        fr<<PrH[i]<<" "<<PrM[i]<<" "<<PbH[i]<<" "<<PbM[i]<<" "<<kiekP[i]<<endl;
    }

    fr.close();

}
