#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const char FD[] = "sodas_data.txt";
const char FR[] = "sodas_rez.txt";

void Duomenys(double &x1, double &y1, double &x2, double &y2, double &x3, double &y3, double &dx, double &dy);
double Atstumas(double x1, double y1, double x2, double y2);
double Trikampis(double x1, double y1, double x2, double y2, double x3, double y3);
double arSode(double x1, double y1, double x2, double y2, double x3, double y3, double dx, double dy);
const char* Isvedimas(double x1, double y1, double x2, double y2, double x3, double y3, double dx, double dy);

int main(){
	double x1, y1, x2, y2, x3, y3, dx, dy;

	Duomenys(x1, y1, x2, y2, x3, y3, dx, dy);
    Isvedimas(x1, y1, x2, y2, x3, y3, dx, dy);
    cout<<arSode(x1, y1, x2, y2, x3, y3, dx, dy)<<endl;
    /*cout<<Trikampis(x1, y1, x2, y2, x3, y3)<<endl;
    cout<<Trikampis(dx, dy, x1, y1, x2, y2)<<endl;
    cout<<Trikampis(dx, dy, x3, y3, x2, y2)<<endl;
    cout<<Trikampis(dx, dy, x1, y1, x3, y3)<<endl;*/


	return 0;
}
void Duomenys(double &x1, double &y1, double &x2, double &y2, double &x3, double &y3, double &dx, double &dy){
    ifstream fd(FD);
    fd>>x1>>y1>>x2>>y2>>x3>>y3>>dx>>dy;
    fd.close();
}
double Atstumas(double x1, double y1, double x2, double y2){

    double atst = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    return atst;
}
double Trikampis(double x1, double y1, double x2, double y2, double x3, double y3){
    double p, str;

    double a = Atstumas(x1, y1, x2, y2);
    double b = Atstumas(x2, y2, x3, y3);
    double c = Atstumas(x3, y3, x1, y1);

    p = (a + b + c) / 2;

    str = sqrt(p * (p - a) * (p - b) * (p - c));

    return str;
}
double arSode(double x1, double y1, double x2, double y2, double x3, double y3, double dx, double dy){
    double s;

    double trik = Trikampis(x1, y1, x2, y2, x3, y3);
    double trik1 = Trikampis(x1, y1, dx, dy, x3, y3);
    double trik2 = Trikampis(x3, y3, dx, dy, x2, y2);
    double trik3 = Trikampis(x2, y2, dx, dy, x1, y1);

    s = trik1 + trik2 + trik3;

    return s;

}

const char* Isvedimas(double x1, double y1, double x2, double y2, double x3, double y3, double dx, double dy){
    ofstream fr(FR);
    if(arSode(x1, y1, x2, y2, x3, y3, dx, dy) == Trikampis(x1, y1, x2, y2, x3, y3)){
        fr<<"Sode";
    }else{
        fr<<"Ne sode";
    }
    fr.close();
}
