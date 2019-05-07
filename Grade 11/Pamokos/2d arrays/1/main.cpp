#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const int Amax = 100;

void Print(int a[][Amax]);

int main(){

	//int A[Amax][Amax] = {{2, 5, 9}, {5, 8, 9}};

	//Print(A);

	vector<vector<int> > V;
	vector<int> col;

	col.push_back(1);

	V.push_back(col);

	cout<<V[0][0]<<endl;

	return 0;
}

void Print(int a[][Amax]){

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cout << "A[" << i << "][" << j << "]: ";
            cout<<a[i][j]<<endl;
        }

    }
}
