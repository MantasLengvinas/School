// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const char FD[] = "U1.txt";
const char FR[] = "U1rez.txt";

struct logo{
    int pb, ab, tb;
    int tp, ta, tt;
};

void Duomenys(vector<logo> &S, int &dp, int &da, int &dt);
void Skyrius(vector<logo> &S);

int main(){

    int dp, da, dt;
    vector<logo> S;

    Duomenys(S, dp, da, dt);
    Skyrius(S);

    for(auto s : S){
        cout<<s.tp<<" "<<s.ta<<" "<<s.tt<<endl;
    }

    return 0;
}

void Duomenys(vector<logo> &S, int &dp, int &da, int &dt){

    int p, a, t, k;
    ifstream fd(FD);

    fd>>k;

    for(int i = 0; i < k; i++){
        fd>>p>>a>>t;
        S.push_back({p, a, t, 0, 0, 0});
    }

    fd>>dp>>da>>dt;

    fd.close();

}

void Skyrius(vector<logo> &S){
    int did = 0;

    for(auto s : S){
        if(s.pb != s.ab && s.ab != s.tb && s.tb != s.pb){
            if(s.pb > did){
                did = s.pb;
                s.tp += 4;
            }
            if(s.ab > did){
                did = s.ab;
                s.ta += 4;
            }
            if(s.tb > did){
                did = s.tb;
                s.tt += 4;
            }
        }

        if(s.pb == s.ab && did == s.pb){
            s.tp += 2;
            s.ta += 2;
        }
        if(s.pb == s.tb && did == s.pb){
            s.tp += 2;
            s.tt += 2;
        }
        if(s.ab == s.tb && did == s.ab){
            s.ta += 2;
            s.tt += 2;
        }
    }

}
