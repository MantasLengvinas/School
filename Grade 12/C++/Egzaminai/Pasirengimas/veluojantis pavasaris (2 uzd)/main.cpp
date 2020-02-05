#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

const int Max = 20;

void M(int VG[], int VL[], int VA[], int BG[], int BL[], int BA[], int R[]);
void Oras(int &n, int &m, int VG[], int VL[], int VA[], int BG[], int BL[], int BA[]);
void Isvedimas(int &m, int VG[], int VL[], int VA[], int BG[], int BL[], int BA[], int D[], int R[]);
void DienosOrai(int n, int m, int VG[], int VL[], int VA[], int BG[], int BL[], int BA[], int D[]);
void OruSuma(int n, int m, int VG[], int VL[], int VA[], int BG[], int BL[], int BA[], int R[]);

int DienosOras(int i, int m, int VG[], int VL[], int VA[], int BG[], int BL[], int BA[]);

int main(){

    int VG[Max], VL[Max], VA[Max], BG[Max], BL[Max], BA[Max], D[Max], R[Max];
    int n, m;

    M(VG, VL, VA, BG, BL, BA, R);
    Oras(n, m, VG, VL, VA, BG, BL, BA);
    DienosOrai(n, m, VG, VL, VA, BG, BL, BA, D);
    DienosOrai(n, m, VG, VL, VA, BG, BL, BA, R);
    OruSuma(n, m, VG, VL, VA, BG, BL, BA, R);

    for(int i = 0; i < n; i++){
        cout<<VG[i]<<" "<<VL[i]<<" "<<VA[i]<<" "<<BG[i]<<" "<<BL[i]<<" "<<BA[i]<<" "<<D[i]<<endl;
    }
    for(int i = 0; i < 7; i++){
        cout<<R[i]<<" ";
    }

    return 0;
}

int DienosOras(int i, int m, int VG[], int VL[], int VA[], int BG[], int BL[], int BA[]){

    return (VG[i] + (VL[i] * 2) + (VA[i] * 3) + (BG[i] * 4) + (BL[i] * 5) + (BA[i] * 6)) / m;

}

int Suma(int n, int A[]){

    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += A[i];
    }

    return sum;

}

void M(int VG[], int VL[], int VA[], int BG[], int BL[], int BA[], int R[]){

    for(int i = 0; i < Max; i++){
        R[i] = 0;
        VG[i] = 0;
        VL[i] = 0;
        VA[i] = 0;
        BG[i] = 0;
        BL[i] = 0;
        BA[i] = 0;
    }

}

void Oras(int &n, int &m, int VG[], int VL[], int VA[], int BG[], int BL[], int BA[]){

    ifstream fd(FD);
    int a;
    int oras = 0;
    int O[Max];

    fd >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fd>>a;
            O[j] = a;
            switch(a){
                case 1:
                    VG[i]++;
                    break;
                case 2:
                    VL[i]++;
                    break;
                case 3:
                    VA[i]++;
                    break;
                case 4:
                    BG[i]++;
                    break;
                case 5:
                    BL[i]++;
                    break;
                case 6:
                    BA[i]++;
                    break;
            }
        }
    }

}

void DienosOrai(int n, int m, int VG[], int VL[], int VA[], int BG[], int BL[], int BA[], int D[]){

    for(int i = 0; i < n; i++){
        D[i] = DienosOras(i, m, VG, VL, VA, BG, BL, BA);
    }

}

void OruSuma(int n, int m, int VG[], int VL[], int VA[], int BG[], int BL[], int BA[], int R[]){

    R[0] = Suma(n, VG);
    R[1] = Suma(n, VL);
    R[2] = Suma(n, VA);
    R[3] = Suma(n, BG);
    R[4] = Suma(n, BL);
    R[5] = Suma(n, BA);

    R[6] = (R[0] + (R[1] * 2) + (R[2] * 3) + (R[3] * 4) + (R[4] * 5) + (R[5] * 6)) / m;

}

void Isvedimas(int m, int VG[], int VL[], int VA[], int BG[], int BL[], int BA[], int D[], int R[]){

    ofstream fr(FR);



}
