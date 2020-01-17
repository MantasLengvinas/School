#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const char FD[] = "sifras_data.txt";
const char FR[] = "sifras_res.txt";

void Duomenys(string &T);
void Sifravimas(string &T);
void Isvedimas(string T);

int main(){

    string T;

    Duomenys(T);
    Sifravimas(T);
    Isvedimas(T);

    return 0;
}

void Duomenys(string &T){
    ifstream fd(FD);

    getline(fd, T);

    fd.close();
}

void Sukeisti(char &a, char &b){
    char temp = a;

    a = b;
    b = temp;
}

void Sifravimas(string &T){
    for(int i = 0; i < T.size(); i += 2){
        if(T[i] != ' ' || T[i+1] != ' '){
            Sukeisti(T[i], T[i+1]);
        }
    }
}

void Isvedimas(string T){
    ofstream fr(FR);

    fr<<T;

    fr.close();
}
