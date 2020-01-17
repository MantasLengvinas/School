// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <numeric>

using namespace std;

const char FD[] = "U1.txt";
const char FR[] = "U1rez.txt";

void Duomenys(vector<int> &M);
void Dalybos(vector<int> &M);

int main(){

    vector<int> M;

	Duomenys(M);
    Dalybos(M);

    for(auto m : M){
        cout<<m<<" ";
    }

    return 0;
}

void Duomenys(vector<int> &M){

    ifstream fd(FD);
    int a;

    for(int i = 0; i < 10; i++){
        fd>>a;
        M.push_back(a);
    }

    for(int i = 10; i < 20; i++){
        M.push_back(0);
    }

    fd.close();

}

void Dalybos(vector<int> &M){

    int sd = 100 - accumulate(M.begin(), M.end(), 0); //Slyvos skirtos dalinimui

    for(int i = 1; i <= M.size(); i++){
        if(sd > 0){
           M[i]++;
            sd--;
        }
        if(i == M.size() && sd > 0){
            i = 1;
        }
    }
}
