#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

//Dalyvio struktura
struct dalyvis{
    vector<char> v; //Vardas
    int nr, h, m, s; //Starto numeris ir laikas
    bool vaik; //Kintamasis skirtas nustatyti ar dalyvis vaikinas ar mergina
};

//Rezultatu struktura
struct rezultatai{
    int nr, h, m, s;
    vector<int> suviai; //Dalyviu suviu rezultatai
};

struct finisaves{
    vector<char> v; //Vardas
    int nr, h, m, s; //Rezultatai ir starto numeris
    int fs; //Rezultatai sekundemis
    bool vaik; //Kintamasis skirtas nustatyti ar dalyvis vaikinas ar mergina
};

int kiekUztruko(int hs, int ms, int ss, int hf, int mf, int sf, int bm);
int iSekundes(int h, int m, int s);

bool palygintiRezultatus(finisaves a, finisaves b);

void Duomenys(vector<dalyvis> &D, vector<rezultatai> &R);
void Vertinimas(vector<dalyvis> &D, vector<rezultatai> &R, vector<finisaves> &F);
void Isvedimas(vector<finisaves> &F);

int main(){

	vector<dalyvis> D; //Dalyviu duomenys
	vector<rezultatai> R; //Rezultatai
	vector<finisaves> F;  //Finisave dalyviai

	Duomenys(D, R);
	Vertinimas(D, R, F);
	Isvedimas(F);

	return 0;
}

void Duomenys(vector<dalyvis> &D, vector<rezultatai> &R){

    int m, n, h, mi, s, nr;
    char a;
    vector<char> v;
    bool vaik;
    ifstream fd(FD);

    fd>>n;

    //Dalyviu duomenys issaugojami i strukturini vektoriu
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 20; j++){
            fd.get(a);
            v.push_back(a);
        }
        fd>>nr>>h>>mi>>s;
        if(nr/100 == 1){
            vaik = false;
        }
        else{
            vaik = true;
        }
        D.push_back({v, nr, h, mi, s, vaik});
        v.clear();
    }

    fd>>m;

    //Rezultatai issaugojami i strukturini vektoriu
    for(int i = 0; i < m; i++){
        int nr, h, mi, s, suvis;
        vector<int> suviai;
        fd>>nr>>h>>mi>>s;
        if(nr/100 == 1){
            for(int j = 0; j < 2; j++){
                fd>>suvis;
                suviai.push_back(suvis);
            }
        }else{
            for(int j = 0; j < 4; j++){
                fd>>suvis;
                suviai.push_back(suvis);
            }
        }
        R.push_back({nr, h, mi, s, suviai});
    }

}

void Vertinimas(vector<dalyvis> &D, vector<rezultatai> &R, vector<finisaves> &F){
    int dts = 0; //Dalyviu taiklus suviai saudykloje
    int bm = 0; //Baudos minutes

    for(auto r : R){
        for(auto d : D){
            if(r.nr == d.nr){
                for(auto s : r.suviai){
                    dts += s;
                }
                if(d.vaik){
                    bm = 20 - dts;
                }
                else{
                    bm = 10 - dts;
                }
                dts = 0;
                int prs = kiekUztruko(d.h, d.m, d.s, r.h, r.m, r.s, bm); //Rezultatas sekundemis
                //Uztruktas laikas
                int rh = prs / 3600;
                int rm = prs / 60 % 60;
                int rs = prs % 60;
                F.push_back({d.v, d.nr, rh, rm, rs, prs, d.vaik});
            }
        }
    }
}

void Rikiavimas(vector<finisaves> &F){

    for(int i = 0; i < F.size(); i++){
        sort(F.begin(), F.end(), palygintiRezultatus);
    }

}

void Isvedimas(vector<finisaves> &F){
    cout<<"Merginos"<<endl;
    for(auto f : F){
        if(!f.vaik){
            cout<<f.nr;
            for(auto s : f.v){
                cout<<s;
            }
            cout<<" "<<f.h<<" "<<f.m<<" "<<f.s<<endl;
        }
    }

    cout<<"Vaikinai"<<endl;
    for(auto f : F){
        if(f.vaik){
            cout<<f.nr;
            for(auto s : f.v){
                cout<<s;
            }
            cout<<" "<<f.h<<" "<<f.m<<" "<<f.s<<endl;
        }
    }
}

int kiekUztruko(int hs, int ms, int ss, int hf, int mf, int sf, int bm){
    int sl = 0, fl = 0, bms = 0; //Starto laikas, finiso laikas, baudos minutes sekundemis

    sl = hs * 3600 + ms * 60 + ss;
    fl = hf * 3600 + mf * 60 + sf;
    bms = bm * 60;

    return (fl - sl + bms);
}

bool palygintiRezultatus(finisaves a, finisaves b){
    return (a.fs > b.fs);
}
