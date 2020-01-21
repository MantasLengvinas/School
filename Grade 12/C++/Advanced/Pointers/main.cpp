#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const char FD[] = "pointers.data";
const char FR[] = "pointers.res";

int sum(int *a, int *b);

int main(){

	int *a, *b;
	int c = 6;
	int &p = c;

	cout<<p;

	return 0;
}

int sum(int *a, int *b){
	return *b;
}
