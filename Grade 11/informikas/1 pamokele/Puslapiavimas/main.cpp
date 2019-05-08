// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdio.h>

using namespace std;

const char FD[] = "puslapiavimas_data.txt";
const char FR[] = "puslapiavimas_res.txt";
const int Cmax = 50;

void Duomenys(int &n, int &k, string P[]);
void Puslapiai(int n, int k, string P[]);
void Salinimas(int &n, int k, string P[]);
void Lyginimas(int k, int n, string P[]);
void Psl(int n, int k, int &kiek);

int main(){
    int n, k;
    string P[Cmax];

    Duomenys(n, k, P);
    Puslapiai(n, k, P);

    return 0;
}

void Duomenys(int &n, int &k, string P[]){
    ifstream fd(FD);
    fd>>n>>k;
    for(int i = 0; i < n; i++){
        fd>>P[i];
    }
    fd.close();
}
void Puslapiai(int n, int k, string P[]){
    int p = n, index = 0, kiek;
    string *Psl;
    string *Pirma = new string[n];
    string Vardas;
    int kiekPsl = n / k;
    if(n % k > 0){
        kiekPsl++;
    }

    for(int i = 0; i < kiekPsl; i++){
        for(int j = 0; j < k; j++){
            index = 0;
            Psl = new string[k];
            Psl[j] = P[j];
            while(index != 1){
                Vardas = Psl[j];
                Pirma[j] = Vardas[0];
                //cout<<Pirma[j]<<endl;
                index++;
            }
        }
        Lyginimas(k, n, Pirma);
        cout<<endl;
        delete []Psl;
        for(int j = 0; j < k; j++){
            Salinimas(n, k, P);
        }
    }

}
void Salinimas(int &n, int k, string P[]){
    int a = 0;
    for(int l = 0; l < n; l++){
        a++;
        P[l] = P[l+1];
        if(a == k-1) n--;
    }
}
void Lyginimas(int k, int n, string P[]){
    int kiek = 0, l = 0;

    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            if(P[i] == P[j]){
                cout<<P[i]<<" "<<P[j]<<endl;
            }
        }
    }
}
void Psl(int n, int k, int &kiek){
        if(n > k){
            kiek = k;
        }
        else{
            kiek = n;
        }
        n -= k;

}
