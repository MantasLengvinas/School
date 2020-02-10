// 4 uzduotis

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

struct _player { //Zaidejo struktura

	string name;
	int age, points;

};

struct _team { //Komandos struktura
	string name;
	int n;
	vector<_player> P;
};

void getData(vector<_team> &T);
void yPlayer(vector<_team> T, vector<string> &YP);

int main(){

	vector<_team> T, NT;
	vector<string> YP;
	ofstream fr(FR);

	getData(T);
	yPlayer(T, YP);

	for(auto p : YP){
		cout<<p<<endl;
	}

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
		P.push_back({pname, age, points});
	}

	T.push_back({tname, n, P});
	P.clear();

	fd >> tname >> n;

	for(int i = 0; i < n; i++){
		fd >> pname >> age >> points;
		P.push_back({pname, age, points});
	}

	T.push_back({tname, n, P});  //Duomenys issaugojami struct masyve
	P.clear();

	fd.close();

}

void yPlayer(vector<_team> T, vector<string> &YP){

	//Jauniausiu zaideju paieska

	int ya = INT_MAX; //Jauniausiu zaideju amziaus lyginimui reikalingas kintamasis
	string yp1, yp2; //Jauniausio zaidejo vardas

	for(int j = 0; j < T[0].n; j++){
		if(T[0].P[j].age <= ya){
			ya = T[0].P[j].age;
			yp1 = T[0].P[j].name;

		}
	}
	YP.insert(YP.begin(), yp1);

	for(int j = 0; j < T[0].n; j++){
		if(T[0].P[j].age <= ya && T[0].P[j].name != yp1){
			ya = T[0].P[j].age;
			yp2 = T[0].P[j].name;

		}
	}
	YP.insert(YP.begin(), yp2);

	ya = INT_MAX;

	for(int j = 0; j < T[1].n; j++){
		if(T[1].P[j].age <= ya){
			ya = T[1].P[j].age;
			yp1 = T[1].P[j].name;

		}
	}
	YP.insert(YP.begin(), yp1);

	for(int j = 0; j < T[1].n; j++){
		if(T[1].P[j].age <= ya && T[1].P[j].name != yp1){
			ya = T[1].P[j].age;
			yp2 = T[1].P[j].name;

		}
	}
	YP.insert(YP.begin(), yp2);

}


