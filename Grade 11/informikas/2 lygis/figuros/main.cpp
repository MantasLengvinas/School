#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const char FD[] = "duom.txt";
const char FR[] = "rez.txt";

void Duomenys(int &n);
void Trikampiai(int n, int &a, int &b, int &c);

int main(){

    int n, ilgis, a, b , c;

    Duomenys(n);
    ilgis = n * 10;


	return 0;
}
void Duomenys(int &n){
    ifstream fd(FD);
    fd>>n;
    fd.close();
}
int Krastine(int min, int max)
{
   return rand() % max + min;
}
void Trikampiai(int n, int &a, int &b, int &c){
    int kiek = 0, t = n;

    srand(time(0));

    a = Krastine(1, t);
    t -= a;
    b = Krastine(1, t);
    t -= a;
    c = t;
    t = n;

}
int Kvadratas(int n){
    int kiek = 0, ln = n / 10;

    for(int i = 1; i <= ln; i++){
        if(i )
    }
}
