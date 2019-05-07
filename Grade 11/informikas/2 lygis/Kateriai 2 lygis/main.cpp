#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FD[] = "kateriai_data.txt";
const char FR[] = "kateriai_res.txt";

const int CMax = 100;

void Duomenys(int &pr, int &pb, int &m1, int &m2);
void Veiksmai(int pr, int pb, int m1, int m2, int &h, int &minut);

int main(){

	int pr, pb, m1, m2, h, minut;

	Duomenys(pr, pb, m1, m2);
	Veiksmai(pr, pb, m1, m2, h, minut);

	return 0;
}

void Duomenys(int &pr, int &pb, int &m1, int &m2){
    ifstream fd(FD);

    fd>>pr>>pb>>m1>>m2;
    fd.close();
}

void Veiksmai(int pr, int pb, int m1, int m2, int &h, int &minut){
    ofstream fr(FR);
    int prm = pr * 60, pbm = pb * 60, a = 0, b = 0;

    int k1[CMax], k2[CMax];

    //Pirmo katerio laikas
    for(int i = prm; i < pbm; i += m1){
        k1[a] = i;
        a++;
    }
    //Antro katerio laikas
    for(int i = prm; i < pbm; i += m2){
        k2[b] = i;
        b++;
    }
    //Lyginimas
	bool d = false;
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(k1[i] == k2[j] && !d && k1[i] != 0){
                h = k1[i] / 60;
                minut = k1[i] % 60;
                fr<<h<<" "<<minut;
                d = true;
            }
        }
    }
    if(!d){
        fr<<"Ne";
    }

    fr.close();
}


