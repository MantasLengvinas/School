#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int CMax = 100;

const char FD[] = "duom.txt";
const char FR[] = "rez.txt";

void Duomenys(int &n, int K[][2]);
void Ieskoti(int n, int &s, int R[], int K[][2], int S[][2]);
void Seka(int &s, int j, int S[][2], int K[][2]);

int main(){

    int R[4] = {82, 71, 77, 74};
    int K[CMax][2];
    int S[CMax][2];
    int n, s = 0;

    Duomenys(n, K);
    Ieskoti(n, s, R, K, S);

    for(int i = 0; i < s; i++){
        cout<<S[i][0]<<" "<<S[i][1]<<endl;
    }

	return 0;
}

void Duomenys(int &n, int K[][2]){

    ifstream fd(FD);
    char raide;
    int nr;

    fd>>n;
    for(int i = 0; i < n; i++){
        fd>>raide;
        nr = (int)raide;
        K[i][0] = nr;
        fd>>K[i][1];
    }

}

void Ieskoti(int n, int &s, int R[], int K[][2], int S[][2]){
    int c = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++){
            if(K[j][0] == R[i]){
                Seka(s, j, S, K);
                c++;
            }
        }
        c = 0;
        cout<<endl;
    }
}

void Seka(int &s, int j, int S[][2], int K[][2]){

    int BS[CMax][2];
    int bs = 1;

    for(int i = 0; i < bs; i++){
        BS[i][0] = K[j][0];
        BS[i][1] = K[j][1];
    }
    bs++;
    cout<<K[j][1]<<endl;

    /*for(int i = 0; i < s; i++){
        S[i][0] = K[j][0];
        S[i][1] = K[j][1];
    }*/
    //s++;

}
