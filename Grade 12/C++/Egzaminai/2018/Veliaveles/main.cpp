#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct _j {
    char C;
    int n;
};

const char FD[] = "data.txt";
const char FR[] = "res.txt";

void Duomenys(vector<_j> &J);
void Veliaveles(vector<_j> &J);
void Isvedimas(int veliaveles, vector<_j> &J);

int main(){

    vector<_j> J = {
        {'G', 0},
        {'Z', 0},
        {'R', 0}
    };

    Duomenys(J);
    Veliaveles(J);

	return 0;
}

void insertToVector(_j j, vector<_j> &J){

    for(int i = 0; i < J.size(); i++){
        if(J[i].C == j.C){
            J[i].n += j.n;
        }
    }

}

void Duomenys(vector<_j> &J) {

    ifstream fd(FD);
    int n;
    _j j;
    fd >> n;

    for(int i = 0; i < n; i++){
        fd >> j.C >> j.n;
        insertToVector(j, J);
    }

    fd.close();
}

void Veliaveles(vector<_j> &J){

    int s = J[0].n, veliaveles;

    for(int i = 0; i < J.size(); i++){
        if(J[i].n < s)
            s = J[i].n;
    }

    veliaveles = s / 2;

    for(int i = 0; i < J.size(); i++){
        J[i].n -= veliaveles * 2;
    }

    Isvedimas(veliaveles, J);

}

void Isvedimas(int veliaveles, vector<_j> &J){

    ofstream fr(FR);

    fr<<veliaveles<<endl;
    for(int i = 0; i < J.size(); i++){
        fr<<J[i].C<<" = "<<J[i].n<<endl;
    }

    fr.close();
}
