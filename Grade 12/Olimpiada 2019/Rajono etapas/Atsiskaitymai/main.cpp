// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

struct ats{
    int pr, pb;
};

void Duomenys(int &n, vector<ats> &A);
int Atsiskaitymai(int n, vector<ats> A);

int main(){

    vector<ats> A;
    int n;
    bool t = false;

    Duomenys(n, A);
    if(n >= 1 && n <= 100000){
        for(auto a : A){
            if(a.pr >= 1 && a.pr <= 1000000000 && a.pb >= 1 && a.pb <= 1000000000){
                t = true;
            }
        }
    }
    if(t){
        cout<<Atsiskaitymai(n, A);
    }

    return 0;
}

void Duomenys(int &n, vector<ats> &A){

    cin>>n;
    int a, b;

    for(int i = 0; i < n; i++){
        cin>>a>>b;
        A.push_back({a, b});
    }

}

int Atsiskaitymai(int n, vector<ats> A){



}
