// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

const char FD[] = "telefonai_data.txt";
const char FR[] = "telefonai_res.txt";

struct Klientas{
    string vardas;
    string pavarde;
    int val;
    int minut;
    int skirtumas;
    bool nuolaida = false;

    Klientas(const string vardas, const string pavarde, const int val, const int minut, const int skirtumas)
        :vardas(vardas), pavarde(pavarde), val(val), minut(minut), skirtumas(skirtumas) {};
};

void Duomenys(vector<Klientas> &K, int &maxMin);
int Skirtumas(vector<Klientas> &K, int maxMin);
int Vidurkis(vector<Klientas> &K);
void Nuolaida(vector<Klientas> &K, int &j);
void Isvedimas(vector<Klientas> &K, double vid);

int main(){

    vector<Klientas> K{};
    int maxMin;
    double vid;

    Duomenys(K, maxMin);
    Skirtumas(K, maxMin);
    vid = Vidurkis(K);
    Isvedimas(K, vid);


    for(int i = 0; i < K.size(); i++){
        //cout<<K.at(i).nuolaida<<endl;
    }

    return 0;
}

void Duomenys(vector<Klientas> &K, int &maxMin){
    int n;
    ifstream fd(FD);
    fd>>n>>maxMin;
    string vardas{}, pavarde{};
    int val{}, minut{}, skirtumas{};

    for(int i = 0; i < n; i++){
        fd>>vardas>>pavarde>>val>>minut;
        skirtumas = 0;
        K.emplace_back(vardas, pavarde, val, minut, skirtumas);
    }
    fd.close();
}

int Skirtumas(vector<Klientas> &K, int maxMin){
    int m, skirtumas{};

    for(int i = 0; i < K.size(); i++){
        m = K.at(i).val * 60 + K.at(i).minut;
        skirtumas = abs(maxMin - m);
        K.at(i).skirtumas = skirtumas;
    }
}

int Vidurkis(vector<Klientas> &K){
    int suma = 0;

    for(int i = 0; i < K.size(); i++){
        suma += K.at(i).val * 60 + K.at(i).minut;
    }

    return suma / K.size();
}

void Nuolaida(vector<Klientas> &K, int &j){
    int maz = K[0].skirtumas;

    for(int i = 0; i < K.size(); i++){
        if(K.at(i).skirtumas < maz){
            maz = K.at(i).skirtumas;
            j = i;
        }
    }
    K[j].nuolaida = true;
    cout<<K[j].pavarde<<endl;
}

void Isvedimas(vector<Klientas> &K, double vid){
    ofstream fr(FR);
    int n, m = 0, j = 0;

    for(int i = 0; i < K.size(); i++){
        fr<<K.at(i).vardas<<" "<<K.at(i).pavarde<<" "<<K.at(i).skirtumas<<endl<<endl;
    }

    while(m < 2){
        Nuolaida(K, j);
        for(int i = 0; i < K.size(); i++){
            if(K[i].nuolaida){
                fr<<K[i].vardas<<" "<<K[i].pavarde<<endl;
                K.erase(K.begin() + j);
            }
        }
        m++;
    }


    fr<<vid;
}
