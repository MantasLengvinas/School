// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const char FD[] = "U1.txt";
const char FR[] = "U1rez.txt";

struct imone{
    string pav;
    int x, y;
};

void Duomenys(vector<imone> &I, int &m);
void Veziojimas(vector<imone> I, int m, int &kiek, int &lkm);
void Isvedimas(string imone, int kiekkm, int kieki);

int main(){

    vector<imone> I;
    int m, lkm, kiek = 0;

    Duomenys(I, m);
    lkm = m;
    Veziojimas(I, m, kiek, lkm);
    Isvedimas(I[kiek - 1].pav, m - lkm, kiek);

    return 0;
}

void Duomenys(vector<imone> &I, int &m){

    ifstream fd(FD);
    int n, x, y;
    string pav;
    char a;

    fd>>n>>m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            fd.get(a);
            pav += a;
        }

        fd>>x>>y;

        I.push_back({pav, x, y});
        pav.clear();
    }

    fd.close();

}

void Veziojimas(vector<imone> I, int m, int &kiek, int &lkm){

    for(auto i : I){
        if(lkm - abs(i.x) * 2 - abs(i.y) * 2 >= 0){
            int d = (abs(i.x) * 2) + (abs(i.y) * 2);
            lkm -= d;
            kiek++;
        }
    }

}
void Isvedimas(string imone, int kiekkm, int kieki){

    ofstream fr(FR);

    fr<<kieki<<" "<<kiekkm<<" "<<imone<<endl;

    fr.close();
}
