#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

struct _m {
	char name[16];
	vector<int> S;
};

void getData(int &n, int &k, vector<_m> &M);
void CalculateCards(vector<_m> &M, vector<_m> &K);
void OutputResults(vector<_m> K);

int main(){

	int n, k;
	vector<_m> M;
	vector<_m> K;

	getData(n, k, M);
	CalculateCards(M, K);
	OutputResults(K);

	return 0;
}

void getData(int &n, int &k, vector<_m> &M){

	ifstream fd(FD);
	fd >> n >> k;
	int s;
	char a;
	char name[16];
	vector<int> S;

	fd.ignore(80, '\n');

	for(int i = 0; i < n; i++){

        fd.get(name, 15);

		for(int j = 0; j < k; j++){
			fd >> s;
			S.push_back(s);
		}
		M.push_back({name, S});
        S.clear();
	}

	fd.close();

}

void CalculateCards(vector<_m> &M, vector<_m> &K){

	vector<int> S;
	S.assign(10, 0); //Vektoriaus uzpildymas 0

	for(int i = 0; i < M.size(); i++){
		for(int j = 0; j < M[i].S.size(); j++){
			int k = (M[i].S[j]) - 1;
			S[k]++;
		}
		K.push_back({M[i].name, S});
		S.assign(10, 0);
	}

}

void OutputResults(vector<_m> K){
	ofstream fr(FR);

	for(int i = 0; i < K.size(); i++){
		fr << K[i].name << " ";
		for(int j = 0; j < K[i].S.size(); j++){
			fr << K[i].S[j] << " ";
		}
	}

	fr.close();
}
