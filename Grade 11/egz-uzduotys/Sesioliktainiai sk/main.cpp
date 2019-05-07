#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

const char FD[] = "duom.txt";
const char FR[] = "rez.txt";

void Duomenys(int &a, int &b, int RGB[][3]);
void Vertimas(int n, int RGB[][3], vector<string> &Kodai);
void Isvedimas(vector<string> Kodai);

int Keitimas(int s);

int main(){

    int RGB [100][3];
    int a, b, n;

    vector<string> Kodai;

    Duomenys(a, b, RGB);

    n = a*b;

    Vertimas(n, RGB, Kodai);
    Isvedimas(Kodai);

	return 0;
}

void Duomenys(int &a, int &b, int RGB[][3]){
    ifstream fd(FD);

    fd>>a>>b;

    for(int i = 0; i < a*b; i++){
        for(int j = 0; j < 3; j++){
            fd>>RGB[i][j];
        }
    }

    fd.close();
}

int Keitimas(int s){
    switch(s){
        case 10:
            return 65;
        break;
        case 11:
            return 66;
        break;
        case 12:
            return 67;
        break;
        case 13:
            return 68;
        break;
        case 14:
            return 69;
        break;
        case 15:
            return 70;
        break;
    }

    return s;
}

void Vertimas(int n, int RGB[][3], vector<string> &Kodai){

    int s1, s2;
    vector<int> K;

    for(int i = 0; i < n; i++){

        string kodas;
        char a;

        for(int j = 0; j < 3; j++){
            s1 = RGB[i][j] / 16;
            s1 = Keitimas(s1);
            s2 = RGB[i][j] % 16;
            s2 = Keitimas(s2);
            K.insert(K.end(), {s1, s2});
        }

        for(int j = 0; j < K.size(); j++){
            if(K[j] >= 65){
                a = K[j];
                kodas += a;
            }
            else{
                ostringstream convert;
                convert<<K[j];
                string sa = convert.str();
                kodas += sa;
            }
        }

        Kodai.push_back(kodas);
        K.clear();
    }
}

void Isvedimas(vector<string> Kodai){
    ofstream fr(FR);

    for(int i = 0; i < Kodai.size(); i++){
        cout<<Kodai[i]<<";";
    }

    fr.close();
}
