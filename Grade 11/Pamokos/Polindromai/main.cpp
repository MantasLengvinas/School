#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FD[] = "duom.txt";

void Duomenys(int &n, int &m);
int ArPalindromas(int n);
void Isvedimas(int n, int m);

int main(){

	int n, m;

	Duomenys(n, m);
	ArPalindromas(n);
	Isvedimas(n, m);

	return 0;
}

void Duomenys(int &n, int &m){
    ifstream fd(FD);
    fd>>n>>m;
    fd.close();
}

int ArPalindromas(int n){

    int sk=0;

    for (int i = n; i > 0; i /= 10){
        sk = sk*10 + i%10;
    }

    return (n==sk);
}

void Isvedimas(int n, int m){

    for(int i = n; i <= m; i++){
        if(ArPalindromas(i)){
            cout<<i<<endl;
        }
    }
}
