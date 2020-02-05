#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "";

struct _p {
    int a, b;
    bool a1, b1;
};

void Duomenys(int &N, int &M, vector<int> &D, vector<_p> &P);
int Atvirutes(vector<int> D, vector<_p> P);

int main(){

    int N, M;
    vector<int> D;
    vector<_p> P;

    Duomenys(N, M, D, P);
    cout<<Atvirutes(D, P);

    return 0;
}

void Duomenys(int &N, int &M, vector<int> &D, vector<_p> &P){

    ifstream fd(FD);
    int k, a, b, d;
    fd>>N>>M>>k;

    for(int i = 0; i < M; i++){
        fd>>d;
        D.push_back(d);
    }

    for(int i = 0; i < k; i++){
        fd>>a>>b;
        P.push_back({a, b, false, false});
    }

}

bool arArtimas(int a, vector<int> D){

    for(int i = 0; i < D.size(); i++){
        if(a == D[i])
            return true;
    }

    return false;

}

int Atvirutes(vector<int> D, vector<_p> P){

    int kiek = D.size();

    for(int i = 0; i < P.size(); i++){
        if(arArtimas(P[i].a, D) && arArtimas(P[i].b, D)){
            P[i].a1 = true;
            P[i].b1 = true;
        }
        if(arArtimas(P[i].a, D) && !P[i].b1){
            kiek++;
            P[i].b1 = true;
        }
        if(arArtimas(P[i].b, D) && !P[i].a1){
            kiek++;
            P[i].a1 = true;
        }
        if(P[i].b1 && !P[i].a1){
            kiek++;
            P[i].a1 = true;
        }
        if(P[i].a1 && !P[i].b1){
            kiek++;
            P[i].b1 = true;
        }

    }

    return kiek;

}
