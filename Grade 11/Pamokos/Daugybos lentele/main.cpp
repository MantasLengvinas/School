#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;
const char FD[] = "duom.txt";

void Skaitymas(int &a, int &b);
void Lentele(int m, int n);

int main(){

    int m, n;

   Skaitymas(m,n);

	Lentele(m, n);

	return 0;
}

void Skaitymas(int &a, int &b){
    ifstream fd(FD);
    fd>>a>>b;
    fd.close();
}

void Lentele(int m, int n){

    cout<<setw(4);

    system("Color 2");

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cout<<i*j<<setw(4);
        }
        cout<<endl<<endl;
    }

}
