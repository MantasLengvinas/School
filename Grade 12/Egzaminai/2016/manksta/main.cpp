// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

struct m{
    vector<char> pav;
    int kiek;
};

void Duomenys(vector<m> &Mankstos);
void Veiksmai(vector<m> &Mankstos, vector<m> &S);

int main(){

    vector<m> Mankstos;
    vector<m> S;

    Duomenys(Mankstos);
    Veiksmai(Mankstos, S);

    return 0;
}

void Duomenys(vector<m> &Mankstos){
    ifstream fd(FD);
    vector<char> p;
    char a;
    int n, b;

    fd>>n;

    for(int i = 0; i < n; i++){
        for(int j  = 0; j < 20; j++){
            fd>>a;
            p.push_back(a);
        }
        fd>>b;
        Mankstos.push_back({p, b});
    }

    fd.close();
}

void Veiksmai(vector<m> &Mankstos, vector<m> &S) {

    vector<char> a;

    for(int i = 0; i < Mankstos.size(); i++){
        a = Mankstos[i].pav;
        if(find(Mankstos.begin(), Mankstos.end(), a) != Mankstos.end()){
            S.push_back({a, 0});
        }
    }

    for(auto s : S){
        cout<<s.pav<endl;
    }

}
