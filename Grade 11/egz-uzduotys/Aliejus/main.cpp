#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

int Pelnas(int a, int b, int c, int isl, int n1, int n2, int n3);

void Papildomi(int va, int &p1, int &p3, int &p5);
void Duomenys(int &n1, int &n3, int &n5, int &va, int &isl, int &n1k, int &n3k, int &n5k);
void Skaiciavimai(int n1, int n3, int n5, int &va, int isl, int n1k, int n3k, int n5k);
void Isvedimas(int k1, int k3, int k5, int kla, int kl1, int kl3, int kl5, int p1, int p3, int p5, int pl);

int main(){

    int n1, n3, n5, va, isl, n1k, n3k, n5k;

    Duomenys(n1, n3, n5, va, isl, n1k, n3k, n5k);
    Skaiciavimai(n1, n3, n5, va, isl, n1k, n3k, n5k);

	return 0;
}

void Duomenys(int &n1, int &n3, int &n5, int &va, int &isl, int &n1k, int &n3k, int &n5k){

    ifstream fd(FD);

    fd>>n1>>n3>>n5>>va>>isl>>n1k>>n3k>>n5k;

    fd.close();
}

void Skaiciavimai(int n1, int n3, int n5, int &va, int isl, int n1k, int n3k, int n5k){
    int k5 = 0, k3 = 0, k1 = 0, na1 = n1, na3 = n3, na5 = n5;

    while(va > 0){
        if(n5 > 0){
            va -= 5;
            n5--;
            k5++;
        }
        if(n5 <= 0 && n3 > 0){
            va -= 3;
            n3--;
            k3++;
        }
        if(n5 <= 0 && n3 <= 0 && n1 > 0){
            va -= 1;
            n1--;
            k1++;
        }
        if(n5 <= 0 && n3 <= 0 && n1 <= 0){
            break;
        }
    }
    int kl1 = na1 - k1;
    int kl3 = na3 - k3;
    int kl5 = na5 - k5;

    int p1 = 0, p3 = 0, p5 = 0;

    Papildomi(va, p1, p3, p5);

    int v1 = p1 + na1;
    int v3 = p3 + na3;
    int v5 = p5 + na5;

    int pl = Pelnas(v1, v3, v5, isl, n1k, n3k, n5k);

    Isvedimas(k1, k3, k5, va, kl1, kl3, kl5, p1, p3, p5, pl);
}

void Papildomi(int va, int &p1, int &p3, int &p5){

    p5 = va / 5;

    int l = va % 5;

    p3 = l / 3;

    p1 = l % 3;


}

int Pelnas(int a, int b, int c, int isl, int n1, int n2, int n3){

    return (a * n1 + b * n2 + c * n3) - isl;

}

void Isvedimas(int k1, int k3, int k5, int kla, int kl1, int kl3, int kl5, int p1, int p3, int p5, int pl){
    ofstream fr(FR);

    fr<<k1<<" "<<k3<<" "<<k5<<" "<<kla<<endl;
    fr<<kl1<<" "<<kl3<<" "<<kl5<<endl;
    fr<<p1<<" "<<p3<<" "<<p5<<endl;
    fr<<pl<<endl;

    fr.close();
}
