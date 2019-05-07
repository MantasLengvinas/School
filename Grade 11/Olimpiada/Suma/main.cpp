#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FD[] = "suma.in";
const char FR[] = "suma.out";

void Duomenys(int &a, int &b);
int Suma(int a, int b);

int main(){

	int a, b;
	ofstream fr(FR);

	Duomenys(a, b);
	if(a < -1000 || a > 1000 || b < -1000 || b > 1000){
        fr<<"Netinkamas skaicius"<<endl;
    }else{
        fr<<Suma(a, b);
    }

	fr.close();
	return 0;
}
void Duomenys(int &a, int &b){
    ifstream fd(FD);
    fd>>a>>b;
    fd.close();
}
int Suma(int a, int b){
    int suma = 0;
    for(int i = a; i <= b; i++){
        suma += i;
    }
    return suma;
}
