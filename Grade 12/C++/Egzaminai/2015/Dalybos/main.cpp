// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <numeric>

using namespace std;

const char FD[] = "U1.txt";
const char FR[] = "U1rez.txt";

void Duomenys(vector<int> &M, vector<int> &KS);
void Dalybos(vector<int> &M, vector<int> &KS);
void Isvedimas(vector<int> &KS);

int main(){

    vector<int> M, KS;

	Duomenys(M, KS);
    Dalybos(M, KS);
    Isvedimas(KS);

    return 0;
}

void Duomenys(vector<int> &M, vector<int> &KS){

    ifstream fd(FD);
    int a;

    for(int i = 0; i < 10; i++){
        fd>>a;
        M.push_back(a);
        KS.push_back(a);
    }

    for(int i = 10; i < 20; i++){
        M.push_back(0);
        KS.push_back(0);
    }

    fd.close();

}

void Dalybos(vector<int> &M, vector<int> &KS){

    int kiekS, j = 1;

    for(int i = 0; i < 10; i++){
        kiekS = 10 - M[i];
        while(kiekS > 0){
            KS[j]++;
            kiekS--;
            j++;
        }
        j = i + 2;
    }

}

void Isvedimas(vector<int> &KS){

    ofstream fr(FR);

    for(int i = 0; i < KS.size(); i++){
        fr<<KS[i]<<" ";
    }

    fr.close();

}
