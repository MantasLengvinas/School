#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

struct kodas{
    char nr;
    string kodas;
};

void Duomenys(vector<char> &K, vector<kodas> &Ko);
void Kodavimas(vector<char> &K, vector<int> &N, vector<kodas> &Ko);

int main(){

    vector<char> K;
    vector<int> N;
    vector<kodas> Ko;

	Duomenys(K, Ko);
	Kodavimas(K, N, Ko);

	for(auto k : Ko){
        cout<<k.nr<<" "<<k.kodas<<endl;
	}

	return 0;
}

void Duomenys(vector<char> &K, vector<kodas> &Ko){

    ifstream fd(FD);
    int n;
    fd>>n;
    char a;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 21; j++){
            fd>>a;
            K.push_back(a);
        }
    }

    fd.close();

    int nr = 2;
    string c;
    for(int i = 65; i < 90; i++){
        char a = i;
        c += a;
        if(c.length() == 3){
            Ko.push_back({nr, c});
            c.clear();
            nr++;
        }
    }

}

void Kodavimas(vector<char> &K, vector<int> &N, vector<kodas> &Ko){
    string kodas;
    string nr;
    for(int i = 0; i < K.size(); i += 3){
        for(int j = i; j < i+3; j++){
            kodas += K[j];
        }

        kodas.clear();
    }
}
