// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const char FD[] = "komandos.txt";
const char FR[] = "komandosres.txt";

struct komanda{

    string pav, ln, fn; //Komandos pavadinimas, trenerio pavarde ir vardas
    vector<int> v; //Varzybos

};

int kiekLaimejo(vector<int> T);

void Duomenys(vector<komanda> &K);
void Atrinkimas(vector<komanda> &K);
void Salinti(vector<komanda> &K, int i);
void Isvedimas(vector<komanda> &K);

int main(){

    vector<komanda> K;

    Duomenys(K);
    Atrinkimas(K);
    Isvedimas(K);

    return 0;
}

void Duomenys(vector<komanda> &K){

    int n, a;
    string p, ln, fn;
    ifstream fd(FD);
    fd>>n;

    for(int i = 0; i < n; i++){
        fd>>p>>ln>>fn;
        K.push_back({p, ln, fn});
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fd>>a;
            K[i].v.push_back(a);
        }
    }

    fd.close();
}

int kiekLaimejo(vector<int> T){

    int k = 0;

    for(int i = 0; i < T.size(); i++){
        if(T[i] == 1){
            k++;
        }
    }

    return k;

}

void Atrinkimas(vector<komanda> &K){

    for(int i = 0; i < K.size(); i++){
        if(kiekLaimejo(K[i].v) < K.size() / 2){
            Salinti(K, i);
        }
    }

}

void Salinti(vector<komanda> &K, int i){

    K.erase(K.begin() + i);

}

void Isvedimas(vector<komanda> &K){

    ofstream fr(FR);

    for(int i = 0; i < K.size(); i++){
        fr<<K[i].pav<<" "<<K[i].ln<<" "<<K[i].fn<<endl;
    }

    fr.close();

}
