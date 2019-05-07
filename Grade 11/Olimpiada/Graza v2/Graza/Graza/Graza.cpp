
#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char FD[] = "duom.txt";
const char FR[] = "rez.txt";
const int Cmax = 50;

void Salinimas(int p, int P[], int id);

void Duomenys(int &n, int N[]) {
	ifstream fd(FD);
	fd >> n;
	for (int i = 0; i < n; i++) {
		fd >> N[i];
	}
	fd.close();
}
void Graza(int n, int N[], int &g, int G[], int &p, int P[]) {
	g = 0;
	p = 0;
	int did = 0, a = 0;
	int A[Cmax];
	for (int i = 0; i < n; i++) {
		if (N[i] < 0) {
			G[g] = N[i] * -1;
			g++;
		}
		if (N[i] > 0) {
			P[p] = N[i];
			p++;
		}
	}

	for (int i = 0; i < g; i++) {
		while (G[i] >= 0) {
			for (int j = 0; j < p; j++) {
				if (P[j] > did && P[j] <= G[i]) {
					did = P[j];
					P[j] = 0;
				}
			}
			G[i] -= did;
			A[a] = did;
			a++;
		}
	}

	for (int i = 0; i < a; i++) {
		cout << A[i] << endl;
	}
}

int main() {
	int n, g, p;
	int N[Cmax], G[Cmax], P[Cmax];

	Duomenys(n, N);
	Graza(n, N, g, G, p, P);

	return 0;
}

void Salinimas(int p, int P[], int id) {
	for (int i = 0; i < p; i++) {

	}
}