#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FD[] = "duom.txt";
const char FR[] = "rez.txt";
const int Cmax = 50;

void Duomenys(int &n, int N[]);
void Isvedimas(int n, int N[], int g, int G[]);
void Graza(int n, int &k, int K[], int g, int G[]);
void Idejimas(int n, int &g, int G[]);

int main(){

    int n, g = 0;
    int N[Cmax];
    int G[Cmax];

    Duomenys(n, N);
    Isvedimas(n, N, g, G);


	return 0;
}
void Duomenys(int &n, int N[]){
    ifstream fd(FD);
    fd>>n;

    for(int i = 0; i < n; i++){
        fd>>N[i];
    }
    fd.close();
}
void Isvedimas(int n, int N[], int g, int G[]){
    ofstream fr(FR);
    int K[Cmax];
    int k;

    for(int i = 0; i < n; i++){
        if(N[i] > 0){
            Idejimas(N[i], g, G);
        }else if(N[i] < 0){
            Graza(N[i]*-1, k, K, g, G);
            for(int j = 0; j < k; j++){
                fr<<K[j]<< " ";
            }
            fr<<endl;
        }
    }
    fr.close();
}
void Graza(int n, int &k, int K[], int g, int G[]){
    k = 0;
    int did = 0;
    int d = 0;
    while(d < n){
        int id;
        for(int i = 0; i < g; i++){
            if(G[i] > did && G[i] + d <=n){
                did=G[i];
                id = i;
            }
        }
        K[k] = did;
        k++;
        G[id] = 0;
        d += did;
    }
}
void Idejimas(int n, int &g, int G[]){
    G[g] = n;
    g++;
}
