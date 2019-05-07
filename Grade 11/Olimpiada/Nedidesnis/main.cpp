#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FD[] = "ne-didesnis.in";
const char FR[] = "ne-didesnis.out";

void Duomenys(int &a, int &b);
int Nedidesnis(int a, int b);

int main(){

    int a, b;
    ofstream fr(FR);

    Duomenys(a, b);
    if(a < 1 || a > 1000 || b < 1 || b > 1000){
        fr<<"Netinkamas skaicius"<<endl;
    }else{
        fr<<Nedidesnis(a, b);
    }

    fr.close();
	return 0;
}

void Duomenys(int &a, int &b){
    ifstream fd(FD);
    fd>>a>>b;
    fd.close();
}

int Nedidesnis(int a, int b){
    int nedidesnis = 0;
    if(a < b){
        nedidesnis = a;
    }
    else{
        nedidesnis = b;
    }
    return nedidesnis;
}
