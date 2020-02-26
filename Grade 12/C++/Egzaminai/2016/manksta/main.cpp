// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const char FD[] = "U2_1.txt";
const char FR[] = "res.txt";

struct m{
    string pav;
    int kiek;
};

const int CPav = 21;

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
    //Funkcija patikrinanti kuris skaicius didesnis (reikalinga rikiavimo funkcijai)
    if(a.kiek > b.kiek){
        return true;
    }

    if(a.kiek == b.kiek){
        if(a.pav[0] < b.pav[0]){
            return true;
        }
    }

    return false;

}

void Duomenys(vector<m> &Mankstos){
    ifstream fd(FD);
    string p;
    char a[CPav + 1];
    int n, b;

    fd>>n;
    fd.ignore(80, '\n');
    for(int i = 0; i < n; i++){
        fd.get(a, CPav);
        fd>>b;
        Mankstos.push_back({a, b});
        fd.ignore(80, '\n');
        //Nuskaityti duomenys irasomi i strukturini vektoriu
    }

    fd.close();
}

bool arYra(string a, vector<m> &S){

    //funkcija patikrinanti ar pratimas jau yra galutiniame masyve
    for(auto s : S){
        if(s.pav == a)
            return true;
    }

    return false;
}

void Atrinkimas(vector<m> &Mankstos, vector<m> &S) {

    //Funkcija atrenkanti pratimus, kad jie nesikartotu galutiniame masyve

    string a;

    for(int i = 0; i < Mankstos.size(); i++){
        a = Mankstos[i].pav;
        if(!arYra(a, S)){
            S.push_back({a, 0});
            //Suformuojamas struct vektorius, kuriame bus skaiciuojami visi pratimai
        }
        a.clear();
    }
}

void Pratimai(vector<m> &Mankstos, vector<m> &S){

    //Funkcija skaiciuojanti kiek kartu atlikti tam tikri pratimai

    for(int i = 0; i < S.size(); i++){
        int kiek = 0;
        for(int j = 0; j < Mankstos.size(); j++){
            if(S[i].pav == Mankstos[j].pav){
                kiek += Mankstos[j].kiek;
            }
        }
        S[i].kiek = kiek;
    }

    //Vektoriaus rykiavimas pagal pratimu skaiciu
    sort(S.begin(), S.end(), _check);
}

void Isvedimas(vector<m> &S){

    ofstream fr(FR);

    //Duomenu isvedimas i tekstini faila

    for(int i = 0; i < S.size(); i++){
        string rpav = _repair(S[i].pav);
        fr<<rpav<<" "<<S[i].kiek<<endl;
    }

    fr.close();
}
