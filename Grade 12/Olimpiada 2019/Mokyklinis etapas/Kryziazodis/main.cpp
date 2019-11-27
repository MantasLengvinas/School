// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct susikirte{
    string a, b;
};

struct kryziazodis{
    string zodis1, zodis2;
    int i1, i2;
    vector<susikirte> S;
};

void Duomenys(vector<string> &Z);
void Kryziazodis(vector<string> &Z, vector<kryziazodis> &K);
void Iterpimas(string z1, string z2, int i1, int i2, vector<kryziazodis> &K);

int main(){

    vector<string> Z;
    vector<kryziazodis> K;

    Duomenys(Z);
    Kryziazodis(Z, K);

    for(int i = 0; i < K.size(); i++){
        cout<<K[i].zodis1<<" "<<K[i].i1<<" "<<K[i].zodis2<<" "<<K[i].i2<<endl;
    }

    return 0;
}

bool Tikrinti(string z1, string z2, int i1, int i2, vector<kryziazodis> &K){
    for(auto k : K){
        if(k.zodis1 == z1 && k.zodis2 == z2 && k.i1 == i1 && k.i2 == i2){
            return true;
        }
    }

    return false;
}

void Duomenys(vector<string> &Z){
    string zodis;

    for(int i = 0; i < 3; i++){
        cin>>zodis;
        Z.push_back(zodis);
    }
}

void Iterpimas(string z1, string z2, int i1, int i2, vector<kryziazodis> &K){
    vector<susikirte> S;

    if(!Tikrinti(z1, z2, i1, i2, K)){
        S.push_back({z1, z2});
        K.push_back({z1, z2, i1, i2, S});
    }
}

void Kryziazodis(vector<string> &Z, vector<kryziazodis> &K){

    for(int k = 0; k < Z.size(); k++){
        for(int i = 0; i < Z[k].size(); i++){
            for(int j = 0; j < Z[k+1].size(); j++){
                for(int l = 0; l < Z[k+2].size(); l++){
                    if(Z[k].at(i) == Z[k+1].at(j) && Z[k] != Z[k+1]){
                        Iterpimas(Z[k], Z[k+1], i + 1, j + 1, K);
                    }
                    if(Z[k].at(i) == Z[k+2].at(l) && Z[k] != Z[k+2]){
                        Iterpimas(Z[k], Z[k+2], i + 1, l + 1, K);
                    }
                }
            }
        }
    }

}
