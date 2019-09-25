#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

struct skaicius{
    int nr;
    string skaicius;
};

struct kodas{
    string kodas;
    int klaidos;
};

void Duomenys(vector<skaicius> &Ko, vector<kodas> &K);
void Kodavimas(vector<kodas> &K, vector<int> &N, vector<skaicius> &Ko);
void Isvedimas(vector<kodas> K, vector<int> N);

string Klaida(string dal, int i, int kpr, int kpb);

int Atkodavimas(string dal, vector<skaicius> Ko, vector<kodas> &K, int i, int kpr, int kpb);

int main(){

    vector<kodas> K;
    vector<int> N;
    vector<skaicius> Ko;

	Duomenys(Ko, K);
	Kodavimas(K, N, Ko);
	Isvedimas(K, N);

	return 0;
}

void Duomenys(vector<skaicius> &Ko, vector<kodas> &K){

    ifstream fd(FD);
    int n;
    fd>>n;
    char a;
    string kodas;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 21; j++){
            fd>>a;
            kodas += a;
        }
        K.push_back({kodas, 0});
        kodas.clear();
    }

    fd.close();

    int nr = 2;
    string c;
    for(int i = 65; i < 90; i++){
        char a = i;
        c += a;
        if(c.length() == 3){
            Ko.push_back({nr, c});
            c.clear();
            nr++;
        }
    }

}

void Kodavimas(vector<kodas> &K, vector<int> &N, vector<skaicius> &Ko){
    string dal;
    int kpr, kpb;

    for(int k = 0; k < K.size(); k++){
        for(int i = 0; i < K[k].kodas.length(); i += 3){
            for(int j = i; j < i + 3; j++){
                dal += K[k].kodas[j];
            }
            kpr = i;
            kpb = i + 3;
            N.push_back(Atkodavimas(dal, Ko, K, k, kpr, kpb));
            dal.clear();
        }
    }
}

void Isvedimas(vector<kodas> K, vector<int> N){
    int pr = 0, pb = 7;
    for(auto k : K){
        //cout<<k.kodas<<" Klaidos: "<<k.klaidos<<" Tel. nr: ";
        for(int i = pr; i < pb; i++){
            //cout<<N[i];
        }
        pr += 7;
        pb += 7;
        //cout<<endl;
    }
}

string Klaida(vector<kodas> &K, string dal, int i, int kpr, int kpb){

    int a = dal[0], b = dal[1], c = dal[2];
    int s1, s2;

    s1 = b - a;
    s2 = c - b;

    if(s1 == 1 && s2 == 1){
        return dal;
    }

}

int Atkodavimas(string dal, vector<skaicius> Ko, vector<kodas> &K, int i, int kpr, int kpb){
    dal = Klaida(K, dal, i, kpr, kpb);
    for(auto k : Ko){
        if(dal == k.skaicius){
            return k.nr;
        }
    }
}
