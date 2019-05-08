// https://konkursai.if.ktu.lt/index.php/pamokeliu-uzduotys-2/item/372-3-lygis-pam1-2017r-10/7282-parlamentas

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const char FD[] = "parlamentas_data.txt";
const char FR[] = "parlamentas_res.txt";

const int CMax = 100;

struct Partija{
    int kiek;
    int nariai[CMax][2];
};

void Duomenys(int &n, Partija P[]);
void Veiksmai(int n, Partija P[]);
void Keisti(int &a, int &b);
void Ieskoti(int n, Partija P[], int &nr, vector<int> &Atr);
void Rasti(int n, Partija P[], int nr, vector<int> &Atr);
void Isvalyti(Partija P[], int i);
void Isvedimas(int n, Partija P[], vector<int> Atr);

int main(){

	Partija P[CMax];
	int n, nr = 1;
	vector<int> Atr;

	Duomenys(n, P);
	Veiksmai(n, P);
	Ieskoti(n, P, nr, Atr);
    //Isvedimas(n, P, Atr);

    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < P[i].kiek; j++){
            if(P[i].nariai[j][1] == 1){
                cout<<P[i].nariai[j][0]<<endl;
            }
        }
        cout<<endl;
    }*/

    for(int i = 0; i < Atr.size(); i++){
        cout<<Atr[i]<<endl;
    }

    return 0;
}
void Duomenys(int &n, Partija P[]){
    ifstream fd(FD);

    fd>>n;

    for(int i = 0; i < n; i++){
        fd>>P[i].kiek;
        for(int j = 0; j < P[i].kiek; j++){
            fd>>P[i].nariai[j][0];
            P[i].nariai[j][1] = 0;
        }
    }

    fd.close();
}

void Veiksmai(int n, Partija P[]){

    for(int i = 0; i < n; i++){
        //Rykiavimas
        for(int j = 0; j < P[i].kiek - 1; j++){
            for(int k = 0; k < P[i].kiek - j - 1; k++){
                if (P[i].nariai[k][0] > P[i].nariai[k+1][0]) {
                    Keisti(P[i].nariai[k][0], P[i].nariai[k+1][0]);
                }
            }
        }
    }

}

void Keisti(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void Ieskoti(int n, Partija P[], int &nr, vector<int> &Atr){
    while(Atr.size() != n){
        Rasti(n, P, nr, Atr);
        nr++;
    }

    Isvedimas(n, P, Atr);

}

void Rasti(int n, Partija P[], int nr, vector<int> &Atr){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < P[i].kiek; j++){
            if(P[i].nariai[j][0] == nr){
                P[i].nariai[j][1] = 1;
                Atr.push_back(P[i].nariai[j][0]);
            }
        }
        //cout<<endl;
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < P[i].kiek; j++){
            if(P[i].nariai[j][1] != 1){
                break;
                Isvalyti(P, i);
                Rasti(n, P, nr, Atr);
            }
        }
    }

}
void Isvalyti(Partija P[], int i){
    for(int j = 0; j < P[i].kiek; j++){
        P[i].nariai[j][1] = 0;
    }
}

void Isvedimas(int n, Partija P[], vector<int> Atr){
    ofstream fr(FR);
    fr<<"Pradiniai surikiuoti duomenys:"<<endl<<endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < P[i].kiek; j++){
            fr<<P[i].nariai[j][0]<<" ";
        }
        fr<<endl<<endl;
    }
    fr<<"Parlamenta sudaro:"<<endl<<endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < P[i].kiek; j++){
            if(P[i].nariai[j][1] == 1){
                //cout<<P[i].nariai[j][0]<<endl;
            }
        }
    }

    fr.close();
}
