// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const char FD[] = "sodinukai_data.txt";
const char FR[] = "sodinukai_res.txt";

void Duomenys(int n, int &a1, int &a2, vector<float> &aukst);
void Atrinkti(int &atr, int a1, int a2, float &vida, vector<float> &aukst);
float Vidurkis(vector<float> &aukst);
void Isvedimas(int atr, float vida, float vidb, vector<float> aukst);

int main(){

	int n, a1, a2, atr;
	vector<float> aukst;
	float vidb, vida;

	Duomenys(n, a1, a2, aukst);
	vidb = Vidurkis(aukst);
	Atrinkti(atr, a1, a2, vida, aukst);
	Isvedimas(atr, vida, vidb, aukst);

    return 0;
}

void Duomenys(int n, int &a1, int &a2, vector<float> &aukst){
    ifstream fd(FD);
    float a;
    fd>>n;

    for(int i = 0; i < n; i++){
        fd>>a;
        aukst.push_back(a);
    }
    fd>>a1>>a2;
    fd.close();
}

float Vidurkis(vector<float> &aukst){
    float sum;

    for(int i = 0; i < aukst.size(); i++){
        sum += aukst[i];
    }

    float vid = sum /aukst.size();

    return vid;
}

void Atrinkti(int &atr, int a1, int a2, float &vida, vector<float> &aukst){

    for(int i = 0; i < aukst.size(); i++){
            cout<<i<<endl;
        if(aukst[i] < a1 || aukst[i] > a2){
            aukst.erase(aukst.begin() + i);
        }
    }
    atr = aukst.size();

    vida = Vidurkis(aukst);
}

void Isvedimas(int atr, float vida, float vidb, vector<float> aukst){
    ofstream fr(FR);

    fr<<fixed<<setprecision(1)<<vidb<<endl<<atr<<endl<<fixed<<setprecision(1)<<vida<<endl;

    if(atr != 0){
        for(int i = 0; i < aukst.size(); i++){
            fr<<fixed<<setprecision(0)<<aukst[i]<<" ";
        }
    }else{
        fr<<"NE"<<endl;
    }
    fr.close();
}
