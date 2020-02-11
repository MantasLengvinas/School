// 4 uzduotis

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

ofstream fr(FR);

struct _player { //Zaidejo struktura

	string name;
	int age, points;
	bool ft; //Ar zaidejas yra pirmoje komandoje ar ne

};

struct _team { //Komandos struktura
	string name;
	int n;
	vector<_player> P;
};

void getData(vector<_team> &T);
void yPlayer(vector<_team> T, vector<_player> &YP);
void aPlayer(vector<_team> T, vector<_player> &AP);
void PrintYPlayer(vector<_team> T, vector<_player> &YP);
void PrintAPlayer(vector<_team> T, vector<_player> &AP);
void NewTeam(vector<_player> &YP, vector<_player> &AP, vector<string> &NT);
void PrintNewTeam(vector<string> NT);

int main(){

	vector<_team> T;
	vector<_player> YP, AP;
	vector<string> NT;

	getData(T);
	yPlayer(T, YP);
	aPlayer(T, AP);
	PrintYPlayer(T, YP);
	PrintAPlayer(T, AP);
	NewTeam(YP, AP, NT);
	PrintNewTeam(NT);

	fr.close();

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
		P.push_back({pname, age, points, true});
	}

	T.push_back({tname, n, P});
	P.clear();

	fd >> tname >> n;

	for(int i = 0; i < n; i++){
		fd >> pname >> age >> points;
		P.push_back({pname, age, points, false});
	}

	T.push_back({tname, n, P});  //Duomenys issaugojami struct masyve
	P.clear();

	fd.close();

}

void yPlayer(vector<_team> T, vector<_player> &YP){

	//Jauniausiu zaideju paieska

	int ya = INT_MAX; //Jauniausiu zaideju amziaus lyginimui reikalingas kintamasis
	string yp1, yp2; //Jauniausio zaidejo vardas

	//Pirmosios komandos jauniausi zaidejai
	for(int j = 0; j < T[0].n; j++){
		if(T[0].P[j].age < ya){
			ya = T[0].P[j].age;
			yp1 = T[0].P[j].name;

		}
	}
	YP.push_back({yp1, 0, 0, true});

	for(int j = 0; j < T[0].n; j++){
		if(T[0].P[j].age <= ya && T[0].P[j].name != yp1){
			ya = T[0].P[j].age;
			yp2 = T[0].P[j].name;

		}
	}
	YP.push_back({yp2, 0, 0, true});


	//Antrosios komandos jauniausi zaidejai
	ya = INT_MAX;

	for(int j = 0; j < T[1].n; j++){
		if(T[1].P[j].age < ya){
			ya = T[1].P[j].age;
			yp1 = T[1].P[j].name;

		}
	}
	YP.push_back({yp1, 0, 0, false});

	for(int j = 0; j < T[1].n; j++){
		if(T[1].P[j].age <= ya && T[1].P[j].name != yp1){
			ya = T[1].P[j].age;
			yp2 = T[1].P[j].name;

		}
	}
	YP.push_back({yp2, 0, 0, false});

}

void aPlayer(vector<_team> T, vector<_player> &AP){

	//Taikliausiu zaideju paieska

	int ap = 0; //Zaideju taskams lyginimui reikalingas kintamasis
	string ap1, ap2; //Taikliausio zaidejo vardas

	//Antrosios komandos taikliausi zaidejai
	for(int j = 0; j < T[1].n; j++){
		if(T[1].P[j].points > ap){
			ap = T[1].P[j].points;
			ap1 = T[1].P[j].name;

		}
	}

	AP.insert(AP.begin(), {ap1, 0, 0, false});

	for(int j = 0; j < T[1].n; j++){
		if(T[1].P[j].points >= ap && T[1].P[j].name != ap1){
			ap = T[1].P[j].points;
			ap2 = T[1].P[j].name;

		}
	}

	AP.insert(AP.begin(), {ap2, 0, 0, false});


	//Pirmosios komandos taikliausi zaidejai
	ap = 0;

	for(int j = 0; j < T[0].n; j++){
		if(T[0].P[j].points > ap){
			ap = T[0].P[j].points;
			ap1 = T[0].P[j].name;

		}
	}

	AP.insert(AP.begin(), {ap1, 0, 0, true});

	for(int j = 0; j < T[0].n; j++){
		if(T[0].P[j].points >= ap && T[0].P[j].name != ap1){
			ap = T[0].P[j].points;
			ap2 = T[0].P[j].name;

		}
	}

	AP.insert(AP.begin(), {ap2, 0, 0, true});

}

void PrintYPlayer(vector<_team> T, vector<_player> &YP){

	fr << "JAUNIAUSI" << endl << T[0].name << endl; 

	for(int i = 0; i < 2; i++){
		fr << YP[i].name << endl;
	}

	fr << T[1].name << endl; 

	for(int i = 2; i < 4; i++){
		fr << YP[i].name << endl;
	}

}

void PrintAPlayer(vector<_team> T, vector<_player> &AP){

	fr << "TAIKLIAUSI" << endl << T[0].name << endl; 

	for(int i = 0; i < 2; i++){
		fr << AP[i].name << endl;
	}

	fr << T[1].name << endl; 

	for(int i = 2; i < 4; i++){
		fr << AP[i].name << endl;
	}

}

void NewTeam(vector<_player> &YP, vector<_player> &AP, vector<string> &NT){

	for(int i = 0; i < YP.size(); i++){
		if(YP[i].ft){
			NT.push_back(YP[i].name);
		}
	}

	for(int i = AP.size() - 1; i >= 0; i--){
		if(!AP[i].ft){
			NT.push_back(AP[i].name);
		}
	}

}

void PrintNewTeam(vector<string> NT){

	fr << "NAUJA KOMANDA" << endl; 

	for(int i = 0; i < NT.size(); i++){
		fr << NT[i] << endl;
	}

}

