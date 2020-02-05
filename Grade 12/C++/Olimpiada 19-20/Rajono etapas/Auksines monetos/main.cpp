// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

struct zem{
    int x, y;
    char l;
    bool Jonas;
    bool apl; //Jau aplankytas laneglis
};

void Duomenys(vector<zem> &Z, int &n, int &m);
int Zaidimas(vector<zem> Z, int n, int m, int maxM);

int main(){

    vector<zem> Z;
    int n, m, monetos = 0;

    Duomenys(Z, n, m);
    if(n >= 1 && n <= 500 && m >= 1 && m <= 500){
        for(auto z : Z){
            if(z.l == 'o'){
                monetos++;
            }
        }
        cout<<Zaidimas(Z, n, m, monetos);
    }

    return 0;
}

void Duomenys(vector<zem> &Z, int &n, int &m){

    cin>>n>>m;
    char a;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a;
            Z.push_back({i, j, a, false, false});
        }
    }

    Z[0].Jonas = true;
    Z[0].apl = true;
}

void Judejimas(vector<zem> &Z, int i, char s, int w, int h, int &kiek){

    bool p = false; //Pakeistas
    if(Z[i+w].l == 'o' && Z[i+w].x <= h && !p && !Z[i+w].apl){
        Z[i].Jonas = false;
        Z[i+w].Jonas = true;
        kiek++;
        p = true;
        Z[i+w].apl = true;
    }
    if(Z[i+1].l == 'o' && Z[i+1].y <= w && !p && !Z[i+1].apl){
        Z[i].Jonas = false;
        Z[i+1].Jonas = true;
        kiek++;
        p = true;
        Z[i+1].apl = true;
    }
    if(Z[i+w].l != 'x' && Z[i+w].x <= h && !p && !Z[i+w].apl){
        Z[i].Jonas = false;
        Z[i+w].Jonas = true;
        p = true;
        Z[i+w].apl = true;
    }
    if(Z[i+1].l != 'x' && Z[i+1].x <= h && !p && !Z[i+1].apl){
        Z[i].Jonas = false;
        Z[i+1].Jonas = true;
        p = true;
        Z[i+1].apl = true;
    }

}

int Zaidimas(vector<zem> Z, int n, int m, int maxM){

    int kiek = 0;

    for(int i = 0; i < Z.size(); i++){
        if(Z[i].Jonas){
            Judejimas(Z, i, Z[i].l, m, n, kiek);
        }
    }

    return kiek;

}
