#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

void Duomenys(string &kodas);
void Isvedimas(string kodas);

bool Patikrinti(string kodas);
string Kodavimas(string kodas);

int main(){

    string kodas;

	Duomenys(kodas);
	Isvedimas(kodas);

	return 0;
}

string Kodavimas(string kodas){

    string dal, nk;

    if(!Patikrinti(kodas)){
        for(int i = 0; i < kodas.length(); i += 4){
            int kiekv = 0, kiekn = 0;
            for(int j = i; j < i + 4; j++){
                if(kodas[j] == '0'){
                    kiekn++;
                }
                else{
                    kiekv++;
                }
                dal += kodas[j];
            }
            if(kiekn > kiekv){
                dal.replace(dal.begin(), dal.end(), 4, '0');
            }
            else{
                dal.replace(dal.begin(), dal.end(), 4, '1');
            }

            nk += dal;

            dal.clear();

        }
        return nk;
    }

    return kodas;

}

bool Patikrinti(string kodas){
    int kiek = 0;

    for(int i = 0; i < kodas.length(); i += 4){
        int kiekv = 0, kiekn = 0;
        for(int j = i; j < i + 4; j++){
            if(kodas[j] == '0'){
                kiekn++;
            }
            else{
                kiekv++;
            }
        }
        if(kiekn == 4 || kiekv == 4){
            kiek++;
        }
    }

    if(kodas.length() / 4 == kiek){
        return true;
    }
    return false;
}

void Duomenys(string &kodas){
    ifstream fd(FD);
    fd>>kodas;
    fd.close();
}

void Isvedimas(string kodas){
    ofstream fr(FR);
    fr<<Kodavimas(kodas);
    fr.close();
}
