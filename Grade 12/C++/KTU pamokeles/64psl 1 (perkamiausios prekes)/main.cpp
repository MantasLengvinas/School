#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

struct preke{
    string pav;
    float kaina;
    int kiek;
};

struct pirkejas{
    int kiek;
    vector<int> prekes;
};

void Duomenys(vector<preke> &Pr, vector<pirkejas> &P);
void Isvedimas(vector<preke> &Pr, vector<pirkejas> &P);
void kiekNupirkta(vector<preke> &Pr, vector<pirkejas> &P);

float Suma(vector<preke> &Pr, vector<pirkejas> &P);

int main(){

    vector<preke> Prekes;
    vector<pirkejas> Pirkejas;

    Duomenys(Prekes, Pirkejas);
    Isvedimas(Prekes, Pirkejas);

	return 0;
}

void Duomenys(vector<preke> &Pr, vector<pirkejas> &P){
    ifstream fd(FD);
    int n, m, k, a;
    string pav;
    float kaina;
    vector<int> prekes;

    fd>>n>>m;

    for(int i = 0; i < n; i++){
        fd>>pav>>kaina;
        Pr.push_back({pav, kaina, 0});
    }

    for(int i = 0; i < m; i++){
        fd>>k;
        for(int j = 0; j < k; j++){
            fd>>a;
            prekes.push_back(a);
        }
        P.push_back({k, prekes});
        prekes.clear();
    }

}

void Isvedimas(vector<preke> &Pr, vector<pirkejas> &P){
    cout<<Suma(Pr, P);
}

float Suma(vector<preke> &Pr, vector<pirkejas> &P){

    float suma = 0;

    for(auto p : P){
        for(auto prekes : p.prekes){
            suma += Pr[prekes].kaina;
        }
    }

    return suma;

}

void kiekNupirkta(vector<preke> &Pr, vector<pirkejas> &P){
    for(auto p : P){
        for(auto prekes : p.prekes){
            for(int i = 0; i < Pr.size(); i++){
                if(prekes == i){
                    Pr[i].kiek++;
                }
            }
        }
    }
}
