#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const char FD[] = "data.txt";
//const char FR[] = "";

struct _v{
    int c, d, k;
    bool b;
};

void Duomenys(int &C, int &D, vector<_v> &V);
void kiekKainuos(int C, int &CT, int D, int &DT, int &kiekK, vector<_v> &V);

int main(){

    vector<_v> V;
    int C, D, kiekK = 0;

    Duomenys(C, D, V);
    kiekKainuos(C, C, D, D, kiekK, V);

    cout<<kiekK;

    return 0;
}

void Duomenys(int &C, int &D, vector<_v> &V){

    ifstream fd(FD);
    int c, d, k, n;

    fd >> n >> C >> D;

    for(int i = 0; i < n; i++){
        fd >> c >> d >> k;
        V.push_back({c, d, k, false});
    }

}

int Best(int C, int D, int CT, int DT, vector<_v> &V){

    int bc = 0, j = 0, bd = 0, SCT = 0, SDT = 0;

    for(int i = 0; i < V.size(); i++){
        if(!V[i].b){
            if(V[i].c >= bc && V[i].c <= C){
                j = i;
                if(V[i].d > bd && V[i].d <= D){
                    bc = V[i].c;
                    SCT = CT - V[i].c;
                    SDT = DT - V[i].d;
                    bd = V[i].d;
                    j = i;
                }
            }
        }
    }

    V[j].b = true;

    return j;

}


void kiekKainuos(int C, int &CT, int D, int &DT, int &kiekK, vector<_v> &V){

    int i = Best(C, D, CT, DT, V);

    cout<<"Pries: "<<"i: "<<i<<endl;
    cout<<CT<<" "<<DT<<endl<<endl;

    for(auto v : V){
        cout<<v.b<<endl;
    }
    cout<<endl;

    CT -= V[i].c;
    DT -= V[i].d;
    kiekK += V[i].k;

    cout<<"Po: "<<endl;
    cout<<CT<<" "<<DT<<endl<<endl;

    for(auto v : V){
        cout<<v.b<<endl;
    }
    cout<<endl;

    if(CT > 0 || DT > 0){
        kiekKainuos(C, CT, D, DT, kiekK, V);
    }


}
