// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const char FD[] = "U2.txt";
const char FR[] = "U2rez.txt";

struct seka {
    int k;
    vector<int> kom;
};

struct tikslas {
    int k;
    vector<int> kom;
    bool pasiektas;
};

void Duomenys(int &x0, int &y0, int &x1, int &y1, vector<seka> &S);
void Kelione(int &x0, int &y0, int &x1, int &y1, vector<seka> &S, vector<tikslas> &K);
void Isvedimas(vector<tikslas> &K);

int main(){

    vector<seka> S;
    vector<tikslas> K;
    int x0, y0, x1, y1;

    Duomenys(x0, y0, x1, y1, S);
    Kelione(x0, y0, x1, y1, S, K);
    Isvedimas(K);

    return 0;
}

void Duomenys(int &x0, int &y0, int &x1, int &y1, vector<seka> &S){

    int n, k, a;
    vector<int> kom;
    ifstream fd(FD);

    fd>>x0>>y0>>x1>>y1>>n;

    for(int i = 0; i < n; i++){
        fd>>k;
        for(int j = 0; j < k; j++){
            fd>>a;
            kom.push_back(a);
        }
        S.push_back({k, kom});
        kom.clear();
    }

    fd.close();

}

void Judejimas(int &x0, int &y0, int komanda){

    switch(komanda){
        case 1:
            y0++;
            break;
        case 2:
            x0++;
            break;
        case 3:
            y0--;
            break;
        case 4:
            x0--;
            break;
    }

}

void Kelione(int &x0, int &y0, int &x1, int &y1, vector<seka> &S, vector<tikslas> &K){
    int x0t = x0, y0t = y0;
    vector<int> kom;

    for(auto s : S){
        for(int i = 0; i < s.kom.size(); i++){
            Judejimas(x0t, y0t, s.kom[i]);
            kom.push_back(s.kom[i]);
            if(x0t == x1 && y0t == y1){
                K.push_back({kom.size(), kom, true});
                x0t = x0;
                y0t = y0;
                kom.clear();
                break;
            }
            if(i == s.kom.size()-1 && x0t != x1 && y0t != y1){
                K.push_back({kom.size(), kom, false});
                x0t = x0;
                y0t = y0;
                kom.clear();
            }
        }
    }
}

void Isvedimas(vector<tikslas> &K){
    ofstream fr(FR);

    for(auto k : K){
        if(k.pasiektas){
            fr<<"pasiektas tikslas   ";
            for(auto s : k.kom){
                fr<<s<<" ";
            }
            fr<<k.kom.size()<<endl;
        }
        else{
            fr<<"sekos pabaiga       ";
            for(auto s : k.kom){
                fr<<s<<" ";
            }
            fr<<k.kom.size()<<endl;
        }
    }

    fr.close();
}
