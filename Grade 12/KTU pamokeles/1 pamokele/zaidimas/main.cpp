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

bool ArTeisingas(int teisingaReiksme, int dalyvioReiksme);

int Reiksme(string salyga);
int Veiksmas(char s, int sk, int ats);

void Duomenys(string &salyga, vector<dal> &D);
void Isvedimas(vector<dal> &D, int ats);

int main(){

	string salyga;
	vector<dal> D;

	Duomenys(salyga, D);
	Isvedimas(D, Reiksme(salyga));

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

int Veiksmas(char s, int sk, int ats){
    switch(s){
        case '+':
            ats += sk;
            break;
        case '-':
            ats -= sk;
            break;
        case '*':
            ats *= sk;
            break;
        case '/':
            ats /= sk;
            break;
    }

    return ats;
}

bool ArTeisingas(int teisingaReiksme, int dalyvioReiksme){

    if(teisingaReiksme == dalyvioReiksme){
        return true;
    }

    return false;

}


int Reiksme(string salyga){
    int ats = (int)salyga[0] - 48, s = 0;
    char veiksm = '0';

    for(int i = 1; i < salyga.length() - 1; i++){
        if(salyga[i] != ' ' && (int)salyga[i] > 41 && (int)salyga[i] < 48){
            veiksm = salyga[i];
        }
        if((int)salyga[i] > 47 && (int)salyga[i] < 58){
            s = (int)salyga[i] - 48;
        }

        if(s != 0 && veiksm != '0'){
            ats = Veiksmas(veiksm, s, ats);
            s = 0;
            veiksm = '0';
        }
    }

    return ats;
}

void Isvedimas(vector<dal> &D, int ats){

    ofstream fr(FR);

    for(auto d : D){
        if(ArTeisingas(ats, d.ats)){
            fr<<d.vardas<<" "<<d.ats<<endl;
            break;
        }
    }

    fr.close();

}
