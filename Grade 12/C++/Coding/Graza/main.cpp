#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";
ofstream fr(FR);

void getData(vector<int> &T);
void Transactions(vector<int> T, vector<int> &R);

int main(){

	vector<int> T, R;
	getData(T);
	Transactions(T, R);
	fr.close();
	
	return 0;
}

void getData(vector<int> &T){

	int t, n;
	ifstream fd(FD);
	fd >> n;

	for(int i = 0; i < n; i++){
		fd>>t;
		T.push_back(t);
	}

	fd.close();
}

int HighestBitIndex(int change, vector<int> R){

	int h = 0;
	int index;

	for(int i = 0; i < R.size(); i++){
		if(R[i] > h && R[i] <= change){
			h = R[i];
			index = i;
		}
	}

	return index;
}

void ReturnChange(int change, vector<int> &R){

	vector<int> B; //Bits
	int HBI, HB; //Highest bit index and its value

	while(change < 0){
		HBI = HighestBitIndex(change * -1, R);
		HB = R[HBI];
		change += HB;
		B.push_back(HB);
		R.erase(R.begin() + HBI);
	}

	for(int i = 0; i < B.size(); i++){
		fr<<B[i]<<" ";
	}
	fr<<endl;

}

void Transactions(vector<int> T, vector<int> &R){

	for(int i = 0; i < T.size(); i++){
		if(T[i] > 0){
			R.push_back(T[i]);
		}
		if(T[i] < 0){
			ReturnChange(T[i], R);
		}
	}

}
