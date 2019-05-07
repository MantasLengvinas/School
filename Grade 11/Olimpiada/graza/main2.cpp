#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FD[] = "duom.txt";
const char FR[] = "rez.txt";
const int Cmax = 50;

void Duomenys(int &n, int N[]){
    ifstream fd(FD);
    fd>>n;
    for(int i = 0; i < n; i++){
        fd>>N[i];
    }
    fd.close();
}
void Graza(int n, int N[], int &g, int G[], int &p, int P[]){
    g = 0;
    p = 0;
    int did = 0;
    for(int i = 0; i < n; i++){
        if(N[i] < 0){
            G[g] = N[i] * -1;
            g++;
        }
        if(N[i] > 0){
            P[p] = N[i];
            p++;
        }
    }

    for(int i = 0; i < g; i++){
        while(G[i] >= 0){
            for(int j = 0; j < p; j++){
                if(P[j] > did && P[j] <= G[i]){
                    did = P[j];
                }
            }
            G[i] -= did;
        }
    }
}


int main(){
    int n, g, p;
    int N[Cmax], G[Cmax], P[Cmax];

	Duomenys(n, N);
	Graza(n, N, g, G, p, P);

	return 0;
}
