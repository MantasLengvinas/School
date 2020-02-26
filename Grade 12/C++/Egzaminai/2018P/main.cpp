#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct _d {
    string name;
    int sn, h, m, s;
    bool dis;
};

const char FD[] = "data.txt";
const char FR[] = "res.txt";

void Duomenys(vector<_d> &D);
void Isvedimas(vector<_d> D);

int main(){

	vector<_d> D;

	Duomenys(D);
	Isvedimas(D);


    return 0;
}

/*bool _check(_d a, _d b){
    if(a.kiek > b.kiek){
        return true;
    }

    if(a.kiek == b.kiek){
        if(a.pav[0] < b.pav[0]){
            return true;
        }
    }

    return false;
}*/

bool arDiskvalifikuotas(int nr, int h, int m, int s, vector<_d> &D){

    int pl, pbl = (h * 60) + m + (s / 60);

    for(int i = 0; i < D.size(); i++){
        if(D[i].sn == nr){
            pl = (D[i].h * 60) + D[i].m + (D[i].s / 60);
            if(pbl - pl > 30){
                cout<<pbl - pl<<endl;
                D[i].dis = true;
                return true;
            }
        }
    }

    return false;

}

void Duomenys(vector<_d> &D) {

    ifstream fd(FD);
    int n, m, h, mn, s, sn;
    char eil[22];

    fd>>n;
    fd.ignore(80, '\n');

    for(int i = 0; i < n; i++){
        fd.get(eil, 21);
        fd>>sn>>h>>mn>>s;
        D.push_back({eil, sn, h, mn, s, false});
        fd.ignore(80, '\n');
    }

    fd >> m;

    for(int i = 0; i < m; i++){
        fd>>sn>>h>>mn>>s;
        arDiskvalifikuotas(sn, h, mn, s, D);
    }

}

void Isvedimas(vector<_d> D){

    for(int i = 0; i < D.size(); i++){
        cout<<D[i].name<<endl;
        if(!D[i].dis){

        }
    }

}
