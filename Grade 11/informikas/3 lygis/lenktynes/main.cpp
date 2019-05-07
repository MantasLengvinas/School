#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

const char FD[] = "lenktynes_data.txt";
const char FR[] = "lenktynes_rez.txt";

const int CMax = 50;

struct Dalyvis{
    string vardas;
    int nr;
    int km;
};

void Duomenys(Dalyvis D[], int &n);
void Veiksmai(string vardas, Dalyvis D[], int j);
void Tikrinimas(Dalyvis D[], int n);
void Isvedimas(Dalyvis D[], int n);

int main(){
    int n;
    Dalyvis D[CMax];

	Duomenys(D, n);
	Tikrinimas(D, n);
	Isvedimas(D, n);

	return 0;
}
void Duomenys(Dalyvis D[], int &n){
    ifstream fd(FD);
    fd>>n;

    for(int i = 0; i < n; i++){
        fd>>D[i].vardas;
        fd>>D[i].nr;
    }
    fd.close();
}

void Veiksmai(string vardas, Dalyvis D[], int j){
    int km = 5;

    for(int i = 'A'; i <= 'Z'; i++){
        if(vardas[0] == i){
            D[j].km = km;
        }
        km += 5;
    }
}

void Tikrinimas(Dalyvis D[], int n){

    for(int i = 0; i < n; i++){
        if(D[i].nr >= 10){
            Veiksmai(D[i].vardas, D, i);
        }
        else{
            D[i].km = D[i].nr * 9;
        }
    }

}

void Isvedimas(Dalyvis D[], int n){
    ofstream fr(FR);
    int did = 1;
    int j;

    for(int i = 0; i < n; i++){
        if(D[i].km >= did){
            did = D[i].km;
            j = i;
        }
    }

    fr<<D[j].vardas<<" "<<D[j].km<<endl;
    fr.close();
}
