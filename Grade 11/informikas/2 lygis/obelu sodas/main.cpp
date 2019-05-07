#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const char FD[] = "sodas_data.txt";
const char FR[] = "sodas_rez.txt";

void Duomenys(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int &dx, int &dy);
int Trikampis(int x1, int y1, int x2, int y2, int x3, int y3);
int arSode(int x1, int y1, int x2, int y2, int x3, int y3, int dx, int dy);
const char* Isvedimas(int x1, int y1, int x2, int y2, int x3, int y3, int dx, int dy);

int main(){

	int x1, y1, x2, y2, x3, y3, dx, dy;

	Duomenys(x1, y1, x2, y2, x3, y3, dx, dy);
	Isvedimas(x1, y1, x2, y2, x3, y3, dx, dy);

	return 0;
}

void Duomenys(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int &dx, int &dy){
    ifstream fd(FD);
    fd>>x1>>y1>>x2>>y2>>x3>>y3>>dx>>dy;
    fd.close();
}
int Trikampis(int x1, int y1, int x2, int y2, int x3, int y3){
    int s;

    s = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);

    return s;
}
int arSode(int x1, int y1, int x2, int y2, int x3, int y3, int dx, int dy){
    int trik = Trikampis(x1, y1, x2, y2, x3, y3);
    int trk1 = Trikampis(dx, dy, x1, y1, x3, y3);
    int trk2 = Trikampis(dx, dy, x3, y3, x2, y2);
    int trk3 = Trikampis(dx, dy, x2, y2, x1, y1);
    return trik == trk1 + trk2 + trk3;
}
const char* Isvedimas(int x1, int y1, int x2, int y2, int x3, int y3, int dx, int dy){
    ofstream fr(FR);
    if(arSode(x1, y1, x2, y2, x3, y3, dx, dy)){
        fr<<"Sode";
    }else{
        fr<<"Ne sode";
    }
}
