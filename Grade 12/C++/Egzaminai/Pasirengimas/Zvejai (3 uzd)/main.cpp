#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

struct _f{
    string name;
    int hm;
    int k1, k2, k3; //zuvys
};

void Data(vector<_f> &Z);
void Best(vector<_f> &Z, _f &best);
void Output(vector<_f> Z, _f best);

int main(){

    vector<_f> Z;
    _f best;

    Data(Z);
    Best(Z, best);
    Output(Z, best);


    return 0;
}

void Data(vector<_f> &Z){

    ifstream fd(FD);
    int n, hm, k1z = 0, k2z = 0, k3z = 0, k1, k2, k3;
    string name;

    fd >> n;

    for(int i = 0; i < n; i++){
        fd >> name >> hm;
        for(int j = 0; j < hm; j++){
            fd >> k1 >> k2 >> k3;
            k1z += k1;
            k2z += k2;
            k3z += k3;
        }

        Z.push_back({name, hm, k1z, k2z, k3z});
        k1z = 0;
        k2z = 0;
        k3z = 0;
    }

    fd.close();

}

int sumFish(int k1, int k2, int k3) {

    return k1 + k2 + k3;

}

void Best(vector<_f> &Z, _f &best){

    int b = 0, f;

    for(int i = 0; i < Z.size(); i++){
        f = sumFish(Z[i].k1, Z[i].k2, Z[i].k3);
        if(f > b){
            b = f;
            best = {Z[i].name, f};
        }
    }
}

void Output(vector<_f> Z, _f best){

    ofstream fr(FR);

    for(int i = 0; i < Z.size(); i++){
        fr << Z[i].name << " " << Z[i].k1 << " " << Z[i].k2 << " " << Z[i].k3<<endl;
    }

    fr << best.name << " " << best.hm;

    fr.close();
}
