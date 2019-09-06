#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

struct dalyvis{
    vector<char> v;
    int nr, h, m, s;
};

struct rezultatai{
    int nr, h, m, s;
    vector<int> suviai;
};

void Duomenys(vector<dalyvis> &D, vector<rezultatai> &R);

int main(){

	vector<dalyvis> D;
	vector<rezultatai> R;
	Duomenys(D, R);

	for(int i = 0; i < D.size(); i++){
        for(int j = 0; j < 20; j++){
            cout<<D[i].v[j];
        }
        cout<<" "<<D[i].nr<<" "<<D[i].h<<" "<<D[i].m<<" "<<D[i].s<<endl;
	}
	cout<<endl;
	for(auto r : R){
        cout<<r.nr<<" "<<r.h<<" "<<r.m<<" "<<r.s<<" ";
        for(auto s : r.suviai){
            cout<<s<<" ";
        }
        cout<<endl<<endl;
	}

	return 0;
}

void Duomenys(vector<dalyvis> &D, vector<rezultatai> &R){

    int m, n, h, mi, s, nr;
    char a;
    vector<char> v;
    ifstream fd(FD);

    fd>>n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 20; j++){
            fd.get(a);
            v.push_back(a);
        }
        fd>>nr>>h>>mi>>s;
        D.push_back({v, nr, h, mi, s});
        v.clear();
    }

    fd>>m;

    for(int i = 0; i < m; i++){
        int nr, h, mi, s, suvis;
        vector<int> suviai;
        fd>>nr>>h>>mi>>s;
        if(nr/100 == 1){
            for(int j = 0; j < 2; j++){
                fd>>suvis;
                suviai.push_back(suvis);
            }
        }else{
            for(int j = 0; j < 4; j++){
                fd>>suvis;
                suviai.push_back(suvis);
            }
        }
        R.push_back({nr, h, mi, s, suviai});
    }

}
