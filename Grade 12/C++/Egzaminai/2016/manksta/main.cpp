// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

struct m{
    string pav;
    int kiek;
};

void Duomenys(vector<m> &Mankstos);
void Atrinkimas(vector<m> &Mankstos, vector<m> &S);
void Pratimai(vector<m> &Mankstos, vector<m> &S);
void Isvedimas(vector<m> &S);

int main(){

    vector<m> Mankstos;
    vector<m> S;


    Duomenys(Mankstos);
    Atrinkimas(Mankstos, S);
    Pratimai(Mankstos, S);
    Isvedimas(S);

    return 0;
}

bool _check(m a, m b){
    return a.kiek > b.kiek;
}

string _repair(string a){

    while(a.size() <= 20){
        a.insert(a.end(), ' ');
    }

    return a;
}

void Duomenys(vector<m> &Mankstos){
    ifstream fd(FD);
    string p;
    char a;
    int n, b;

    fd>>n;

    for(int i = 0; i < n; i++){
        fd>>p>>b;
        Mankstos.push_back({p, b});
    }

    fd.close();
}

bool arYra(string a, vector<m> &S){
    for(auto s : S){
        if(s.pav == a)
            return true;
    }

    return false;
}

void Atrinkimas(vector<m> &Mankstos, vector<m> &S) {

    string a;

    for(int i = 0; i < Mankstos.size(); i++){
        a = Mankstos[i].pav;
        if(!arYra(a, S)){
            S.push_back({a, 0});
        }
        a.clear();
    }
}

void Pratimai(vector<m> &Mankstos, vector<m> &S){
    for(int i = 0; i < S.size(); i++){
        int kiek = 0;
        for(int j = 0; j < Mankstos.size(); j++){
            if(S[i].pav == Mankstos[j].pav){
                kiek += Mankstos[j].kiek;
            }
        }
        S[i].kiek = kiek;
    }

    sort(S.begin(), S.end(), _check);
}

void Isvedimas(vector<m> &S){

    ofstream fr(FR);

    for(int i = 0; i < S.size(); i++){
        string rpav = _repair(S[i].pav);
        fr<<rpav<<" "<<S[i].kiek<<endl;
    }

    fr.close();
}
