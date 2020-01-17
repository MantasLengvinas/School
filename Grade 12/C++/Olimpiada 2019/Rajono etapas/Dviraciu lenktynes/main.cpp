// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

void Duomenys(vector<int> &T, int &N, int &M, int &L);
int Lenktynes(vector<int> T, int N, int M, int L);

int main(){

    vector<int> T;
    int N, M, L;
    bool t = false;

    Duomenys(T, N, M, L);
    if(N >= 2 && N <= 10000 && M >= 2 && M <= 10000 && L >= 2 && L <= 10000){
        for(int i = 0; i < T.size(); i++){
            if(T[i] >= 2 && T[i] <= 10000){
                t = true;
            }
        }
    }

    if(t){
        cout<<Lenktynes(T, N, M, L);
    }

    return 0;
}

void Duomenys(vector<int> &T, int &N, int &M, int &L){

    cin >> N >> M >> L;
    int a;

    for(int i = 0; i < N; i++){
        cin>>a;
        T.push_back(a);
    }

}

int Lenktynes(vector<int> T, int N, int M, int L){

    int kiek = 0;
    int g = T[0]; //Greiciausias

    for(int i = 0; i < T.size(); i++){
        if(T[i] < g){
            g = T[i];
        }
    }

    for(int i = 0; i < T.size(); i++){
        if(T[i] / g < 2){
            kiek++;
        }
    }

    return kiek;
}
