// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const char FD[] = "U2.txt";
const char FR[] = "U2rez.txt";


struct Miestas{
    string pav, apskr;
    int gyventojai;
};

struct Apskr{
    string apsrk;
    int maz, viso;
};

void Duomenys(int &k, Miestas M[]);
void Apskirtys(int &k, Miestas M[], int &a, Apskr A[]);

int main(){

    Miestas M[100];
    Apskr A[100];
    int k, a;

    Duomenys(k, M);

    return 0;
}

void Duomenys(int &k, Miestas M[]){

    ifstream fd(FD);
    char a;
    string pav, apskr;

    fd>>k;

    for(int i = 0; i < k; i++){
        for(int j = 0; j < 20; j++){
            fd.get(a);
            pav += a;
        }
        M[i].pav = pav;
        for(int j = 0; j < 13; j++){
            fd.get(a);
            apskr += a;
        }
        M[i].apskr = apskr;
        fd>>M[i].gyventojai;

        pav.clear();
        apskr.clear();
    }

    fd.close();

}

void Apskirtys(int &k, Miestas M[], int &a, Apskr A[]){

    for(int i = 0; i < k; i++){
        //if(find(begin(A.apskr), end(A.apsrk), M[i].apskr) != end(A.apskr)){
            A[a].apskr = M[i].apskr;
            cout<<M[i].apskr<<endl;
        //}
    }

}

void Skaiciavimai(int &k, Miestas M[], Apskr A[]){

}
