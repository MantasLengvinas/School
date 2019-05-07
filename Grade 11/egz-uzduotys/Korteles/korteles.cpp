#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "rez.txt";

void Duomenys(int D[][2], int &n);

int main(){

    int D[100][2];
    int n;

    Duomenys(D, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 1; j++){
           //cout<<D[i][0]<<" ";
        }
        //cout<<endl;
    }

	return 0;
}

void Duomenys(int D[][2], int &n){
    ifstream fd(FD);
    fd>>n;
    int a;

    for(int i = 0; i < n; i++){
        fd>>a;
        cout<<a<<endl;
    }

    fd.close();
}
