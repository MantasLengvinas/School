// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

int Sunkiausia();
int kiekLengvesniu(int did);

void Isvedimas(int did, int kiek);

int main(){

    int sunk = Sunkiausia();
    int kiek = kiekLengvesniu(sunk);

    Isvedimas(sunk, kiek);

    return 0;
}

bool arLengvesne(int a, int b){
    if(a * 2 <= b)
        return true;

    return false;
}

int Sunkiausia(){

    ifstream fd(FD);
    int did = 0, n, a;

    fd>>n;

    for(int i = 0; i < n; i++){
        fd>>a;
        if(a > did)
            did = a;
    }
    fd.close();

    return did;

}

int kiekLengvesniu(int did){
    int kiek = 0, n, a;

    ifstream fd(FD);

    fd>>n;

    for(int i = 0; i < n; i++){
        fd>>a;
        if(arLengvesne(a, did))
            kiek++;
    }

    return kiek;
}

void Isvedimas(int did, int kiek){
    ofstream fr(FR);

    fr<<did<<" "<<kiek;

    fr.close();
}
