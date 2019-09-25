#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

void Duomenys(vector<char> &T);
void Sukeitimas(vector<char> &T);
void Isvedimas(vector<char> T);

int main(){

    vector<char> T;

    Duomenys(T);
    Sukeitimas(T);
    Isvedimas(T);

	return 0;
}

void Duomenys(vector<char> &T){
    ifstream fd(FD);
    char a;

    while(!fd.eof()){
        fd.get(a);
        T.push_back(a);
    }
    T.pop_back();

    fd.close();
}

void Sukeitimas(vector<char> &T){
    char temp;
    for(int i = 0; i < T.size(); i += 2){
        temp = T[i];
        T[i] = T[i+1];
        T[i+1] = temp;
    }
}

void Isvedimas(vector<char> T){
    ofstream fr(FR);

    for(auto t : T){
        fr<<t;
    }
}
