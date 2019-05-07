#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FD[] = "pomidorai.in";
const char FR[] = "pomidorai.out";

void Duomenys(int n, int m, int d);
int Pomidorai(int n, int m, int d);

int main(){

	int n, m, d;

	Duomenys(n, m, d);

	return 0;
}
void Duomenys(int n, int m, int d){
    ifstream fd(FD);
    fd>>n>>m>>d;
    fd.close();
}
int Pomidorai(int n, int m, int d){
    for(int i = 0; i < n; i++){

    }
}
