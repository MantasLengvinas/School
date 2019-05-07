#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const char FD[] = "duom.txt";
const char FR[] = "rez.txt";

void Duomenys(int &sk, int &N);
int DigN(int sk, int N);

int main(){
    int sk, N;

    Duomenys(sk, N);
    DigN(sk, N);

    return 0;
}

void Duomenys(int &sk, int &N){
    ifstream fd(FD);
    fd>>sk>>N;
    fd.close();
}

int DigN(int sk, int N){
    ofstream fr(FR);
    int kelintas=0, a;
    while(sk > 0){
        kelintas++;
        a = sk % 10;
        if(kelintas == N){
            fr<<a;
            break;
        }
        sk = sk / 10;
    }
    if(kelintas <= N){
        fr<<-1;
    }
    fr.close();
}
