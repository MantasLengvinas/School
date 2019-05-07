#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FD[] = "duom1.txt";
//const char FD[] = "duom2.txt";
//const char FD[] = "duom3.txt";
const char FR[] = "rez.txt";

void Duomenys(int &a, int &b, int &op);
int Calc(int a, int b, int op);

int main(){
    int a, b, op;

	Duomenys(a, b, op);
	Calc(a, b, op);

	return 0;
}

void Duomenys(int &a, int &b, int &op){
    ifstream fd(FD);
    fd>>a>>b>>op;
    fd.close();
}

int Calc(int a, int b, int op){
    ofstream fr(FR);

    switch(op){
        case 1:
            fr<<"Buvo atlikta skaitmenu "<<a<<" ir "<<b<<" sudetis, suma lygi: "<<a+b;
        break;
        case 2:
            fr<<"Buvo atlikta skaitmenu "<<a<<" ir "<<b<<" atimtis, skirtumas lygus: "<<a-b;
        break;
        case 3:
            fr<<"Buvo atlikta skaitmenu "<<a<<" ir "<<b<<" daugyba, sandauga lygi: "<<a*b;
        break;
        case 4:
            fr<<"Buvo atlikta skaitmenu "<<a<<" ir "<<b<<" dalyba, dalmuo lygus: "<<a/b;
        break;
        case 5:
            fr<<"Padalinus skaicius "<<a<<" ir "<<b<<", liekana lygi: "<<a%b;
        break;
    }
    fr.close();
}
