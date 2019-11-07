#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

struct dal{
    string vardas;
    int ats;
};

int Reiksme(string salyga);

void Duomenys(string &salyga, vector<dal> &D);

int main(){

	string salyga;
	vector<dal> D;

	Duomenys(salyga, D);
	Reiksme(salyga);

	return 0;
}

void Duomenys(string &salyga, vector<dal> &D){
    ifstream fd(FD);
    int n, ats;
    string v;

    getline(fd, salyga);
    fd>>n;

    for(int i = 0; i < n; i++){
        fd>>v>>ats;
        D.push_back({v, ats});
    }

    fd.close();
}



int Reiksme(string salyga){
    ofstream fr(FR);
    int ats;

    int i = 0;
    while(salyga[i] != '='){
        if((int)salyga[i] > 47 && (int)salyga[i] < 58){
            cout<<(int)salyga[i] - 48<<endl;
        }
        i++;
    }
}
