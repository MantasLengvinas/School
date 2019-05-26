//80 psl. 1 uzd. sekos

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const char FD[] = "duomenys.txt";
const char FR[] = "rezultatai.txt";

const int Cmax = 10;

void Skaitymas(int A[], int &n, int B[], int &m);
void Paieska(int A[], int &n, int B[], int m);
void Iterpimas (int A[], int &n, int B[], int pos, int val);

int main(){
    int A[Cmax], B[Cmax], n, m;

    Skaitymas(A, n, B, m);
    Paieska(A,n,B,m);

    for (int i = 0; i < n; i++){
        cout<<A[i]<<endl;
    }

    return 0;
}

void Skaitymas(int A[], int &n, int B[], int &m){
    ifstream fd(FD);
    fd>>n;

    for(int i = 0; i < n; i++){
        fd>>A[i];
    }

    fd>>m;

    for(int j = 0; j < m; j++){
        fd>>B[j];
    }

    fd.close();
}

void Paieska(int A[], int &n, int B[], int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (B[j] % A[i] == 0){
                Iterpimas(A, n, B, i, j);
            }
        }
        break;
    }
}

void Iterpimas(int A[], int &n, int B[], int pos, int val){

    for(int i = n; i >= pos + 1; i--){
        A[i] = A[i-1];
    }

    A[pos+1] = B[val];
    n++;

}




