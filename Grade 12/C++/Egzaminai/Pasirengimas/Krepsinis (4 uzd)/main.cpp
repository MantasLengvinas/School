// 4 uzduotis 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

struct _team { //Komandos struktura
	string name;
	int n;
	vector<_player> P;
};

struct _player { //Zaidejo struktura

	string name;
	int age, points;
	bool isY, isA;

};

void getData(vector<_team> &T);

int main(){

	vector<_team> T, NT;
	ofstream fr(FR);

	return 0;
}

void getData(vector<_team> &T){

	ifstream fd(FD);
	string tname, pname; //Komandos pav. ir zaidejo vardas
	int n, age, points; //Zaideju kiekis, amzius, taskai

	vector<_player> P; //Zaidejo struct vektorius

	fd >> tname >> n;

	for(int i = 0; i < n; i++){
		fd >> pname >> age >> points;
		P.push_back({pname, age, points, false, false});
	}

	T.push_back({tname, n, P}); 
	P.clear();

	fd >> tname >> n;

	for(int i = 0; i < n; i++){
		fd >> pname >> age >> points;
		P.push_back({pname, age, points, false, false});
	}

	T.push_back({tname, n, P});  //Duomenys issaugojami struct masyve
	P.clear();

	fd.close();

}

void yPlayer(vector<_team> T, vector<string> &YP){ 

	//Jauniausiu zaideju paieska

	int ya = T[0].P[0].age; //Jauniausio zaidejo amziaus lyginimui reikalingas kintamasis
	string yp; //Jauniausio zaidejo vardas

	for(int j = 0; j < T[0].P.size(); j++){
		if(T[0].P[j].age <= ya && !T[0].P[j].isY){
			ya = T[0].P[j].age;
			yp = T[0].P[j].name;
			T[0].P[j].isY = true;
		}
	}

}


