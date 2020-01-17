#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const char FD[] = "laikas_data.txt";
const char FR[] = "laikas_res.txt";

int Sekundes(int s);

void Duomenys(int &s);
void Isvedimas(int s);

int main(){

    int s;

	Duomenys(s);
	Isvedimas(s);

	return 0;
}

void Duomenys(int &s){

    ifstream fd(FD);

    fd>>s;

    fd.close();

}

int Sekundes(int s){

    if(s % 3600 < 60){
        return s % 60;
    }

    return (s % 3600) % 60;

}

void Isvedimas(int s){

    ofstream fr(FR);

    fr<<Sekundes(s);

    fr.close();

}
