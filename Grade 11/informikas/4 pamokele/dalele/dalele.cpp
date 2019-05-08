// https://konkursai.if.ktu.lt/index.php/pamokeliu-uzduotys-2/item/371-2-lygis-pam1-2017r-11/7283-dalele

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const char FD[] = "dalele_data.txt";
const char FR[] = "dalele_res.txt";

struct koord{
    float x, y;
};

void Duomenys(int &t, vector<koord> &K);
void Veiksmai(int t, vector<koord> &K, vector<float> &G);
void Greitis(int t, float x1, float x2, float y1, float y2, , vector<float> &G);

int main(){

    vector<koord> K;
    int t;
    vector<float> G;

    Duomenys(t, K);
    Veiksmai(t, K, G);

    return 0;
}

void Duomenys(int &t, vector<koord> &K){

    ifstream fd(FD);
    float x, y;
    int n;

    fd>>n>>t;

    for(int i = 0; i < n; i++){
        fd>>x>>y;
        K.push_back({x, y});
    }

}

void Veiksmai(int t, vector<koord> &K, vector<float> &G){

    for(int i = 0; i < K.size(); i++){
        if(i != K.size() - 1){
            Greitis(t, K[i].x, K[i+1].x, K[i].y, K[i+1].y, G)
            cout<<K[i].x<<" "<<K[i].y<<" "<<K[i+1].x<<" "<<K[i+1].y<<endl;
        }
    }
}

void Greitis(int t, float x1, float x2, float y1, float y2, , vector<float> &G){

}
