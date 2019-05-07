//13psl 5uzduotis
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FD[] = "duom.txt";
const int Amax = 10;

void Skaitymas(int T[], int &n);

int main(){

    int T[Amax], n, mins=0, vid, arrCounter=0;

	Skaitymas(T, n);

	for(int i = 0; i < n; i++){
        mins += T[arrCounter];
        arrCounter++;
	}

	vid = mins / n;

	cout<<"Per "<<n<<" dienas, slibinas buvo dresuojamas "<<mins<<" minuciu"<<endl<<endl;
	cout<<"Vidutiniskai slibinas buvo dresuojamas "<<vid<<" min per diena"<<endl;

	return 0;
}

void Skaitymas(int T[], int &n){
    ifstream fd(FD);
    fd>>n;
    if((n < 0) && (n > 10)){
        cout<<"Patikrinkite duomenu faila!"<<endl;
    }

    for(int i = 0; i < n; i++){
        fd>>T[i];
    }
    fd.close();
}
