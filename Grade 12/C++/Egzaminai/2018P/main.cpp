#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct _d {
    string name;
    int sn, h, m, s, pblm, pbls;
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

bool arFinisavo(vector<_d> &D, int nr){

    for(int i = 0; i < D.size(); i++){
        if(D[i].sn == nr){
            for(auto s : D){
                cout<<s.dis<<endl;
            }
            return true;
        }
        else{
            D[i].dis = true;
        }

    }



    return false;

}

void Diskvalifikacija(int nr, int h, int m, int s, vector<_d> &D){

    int pl, pbl = (h * 60) + m;

    for(int i = 0; i < D.size(); i++){
        if(D[i].sn == nr && arFinisavo(D, nr)){
            pl = (D[i].h * 60) + D[i].m;
            D[i].pblm = pbl - pl;
            D[i].pbls = s - D[i].s;
            //cout<<D[i].name<<" "<<D[i].dis<<" "<<D[i].pblm<<" "<<D[i].pbls<<endl;
            if(pbl - pl > 30 && D[i].pbls > 0){
                //cout<<D[i].name<<endl;
                D[i].dis = true;

            }
        }
    }

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
        D.push_back({eil, sn, h, mn, s, 0, 0, false});
        fd.ignore(80, '\n');
    }

    fd >> m;

    for(int i = 0; i < m; i++){
        fd>>sn>>h>>mn>>s;
        Diskvalifikacija(sn, h, mn, s, D);
    }

}

void Isvedimas(vector<_d> D){

    for(int i = 0; i < D.size(); i++){
        //cout<<D[i].dis<<endl;
        if(!D[i].dis){
           // cout<<D[i].sn<<" "<<D[i].name<<" "<<D[i].pblm<<" "<<D[i].pbls<<endl;
        }
    }

}
