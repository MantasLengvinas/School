// Vieta komentarui

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FD[] = "laimingi_data.txt";
const char FR[] = "rez.txt";
const int Cmax = 100;

void Duomenys(int &a, int &b);
int kiekSk(int n);
void Suma(int n, int &suma1, int &suma2);
void arLaimingas(int m, int n, int Laimingas[], int &j);

int main(){
	int m, n, j = 0;
	int Laimingas[Cmax];

	Duomenys(m, n);
	arLaimingas(m, n, Laimingas, j);
	for(int i = 0; i < j; i++){
        cout<<Laimingas[i]<<endl;
	}
    //cout<<kiekSk(m);

    return 0;
}
void Duomenys(int &a, int &b){
    ifstream fd(FD);
    fd>>a>>b;
    fd.close();
}
int kiekSk(int n){
    int kiek = 0;

    while(n > 0){
        n /= 10;
        kiek++;
    }
    return kiek;
}

void Suma(int n, int &suma1, int &suma2){

    int kiek = kiekSk(n);
    int k = kiek / 2;

    if(kiek % 2 == 0){
        while(kiek > k){
            suma1 += n % 10;
            n /= 10;
            kiek--;
        }
        while(kiek >= 0){
            suma2 += n % 10;
            n /= 10;
            kiek--;
        }
    }

}
void arLaimingas(int m, int n, int Laimingas[], int &j){
    int suma1 = 0, suma2 = 0;

    for(int i = m; i <= n; i++){
        Suma(i, suma1, suma2);
        //cout<<suma1<<" "<<suma2<<endl;
        if(suma1 == suma2){
            Laimingas[j] = i;
            j++;
        }
    }
}
