#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

bool arAtsiskaites(int P[], int m);
double Vidurkis(int P[], int m);
void Rasti(int P[], int m);

int main(){

    int n, m;

	ifstream fd(FD);
	ofstream fr(FR);

	fd>>n;

	for(int i = 0; i < n; i++){
        fd>>m;
        int P[m];
        for(int j = 0; j < m; j++){
            fd>>P[j];
        }
        if(!arAtsiskaites(P, m)){
            fr<<"Pakeitimai nebuvo atlikti";
        }else{
            Rasti(P, m);
            for(int j = 0; j < m; j++){
                fr<<P[j]<<" ";
            }
        }
        fr<<endl;
	}

	return 0;
}

bool arAtsiskaites(int P[], int m){
    for(int i = 0; i < m; i++){
        if(P[i] == 0){
            return false;
            break;
        }
    }
    return true;
}

double Vidurkis(int P[], int m){

    double sum = 0;

    for(int i = 0; i < m; i++){
        sum += P[i];
    }

    return sum / m;

}

void Rasti(int P[], int m){
    int maz = P[0], j;

    for(int i = 0; i < m; i++){
        if(P[i] < maz){
            maz = P[i];
            j = i;
        }
    }

    P[j] = Vidurkis(P, m);
}
