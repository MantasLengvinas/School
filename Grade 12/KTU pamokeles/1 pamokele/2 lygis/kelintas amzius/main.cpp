#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const char FD[] = "amzius_data.txt";
const char FR[] = "amzius_res.txt";

int Amzius(int m);

void Duomenys(int &m);
void Isvedimas(int m);

int main(){

	int m;

	Duomenys(m);
	Isvedimas(m);

	return 0;
}

void Duomenys(int &m){

    ifstream fd(FD);

    fd>>m;

    fd.close();

}

void Isvedimas(int m){

    ofstream fr(FR);

    fr<<Amzius(m);

    fr.close();

}

int Amzius(int m){

    return m / 100 + 1;

}
