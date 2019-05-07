#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const char FD[] = "duom.txt";

void Duomenys(int &a, int &b);
void ArPitagoroTrejetas(int x, int y);

int main(){

	int x, y;

	Duomenys(x, y);
	ArPitagoroTrejetas(x, y);

	return 0;
}

void Duomenys(int &a, int &b){
    ifstream fd(FD);
    fd>>a>>b;
    fd.close();
}

void ArPitagoroTrejetas(int x, int y){

    double a, b, c;

    for(int i = x; i <= y; i++){
        a = i;
        b = i + 1;
        c = i + 2;
        while(c <= y){
            while(pow(a, 2) + pow(b, 2) <= pow(c, 2)){
                if(pow(a, 2) + pow(b, 2) == pow(c, 2) && a < b){
                    cout<<a<<setw(3)<<b<<setw(3)<<c<<endl;
                }
                b++;
            }
            c++;
        }
    }

}
