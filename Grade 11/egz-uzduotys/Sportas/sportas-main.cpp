#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

struct d {
    string vardas;
    int id, h, m, s;
};

void Duomenys(int &n, d D[]);

int main(){

    d D[100];
    int n;

    Duomenys(n, D);

    for(int i = 0; i < n; i++){
        cout<<D[i].vardas<<endl;
    }

	return 0;
}

void Duomenys(int &n, d D[]){

    ifstream fd(FD);

    int id, h, m, s;
    string v;

    fd.seekg( )

    fd.close();

}
