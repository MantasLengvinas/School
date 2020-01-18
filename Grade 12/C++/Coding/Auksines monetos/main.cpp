#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const char FD[] = "monetos.data";
const char FR[] = "monetos.res";
const int MAX_SIZE = 500;

void getData(int &w, int &h, char Map[][MAX_SIZE]);
int getPath(char Map[][MAX_SIZE], int Path[][MAX_SIZE], int w, int h);

int main() {

	int w, h;
	char Map[MAX_SIZE][MAX_SIZE];
    int Path[MAX_SIZE][MAX_SIZE];

	getData(w, h, Map);
	cout<<getPath(Map, Path, w, h);

	return 0;
}

void getData(int &w, int &h, char Map[][MAX_SIZE]) {

	ifstream fd(FD);
	char s;

	fd >> h >> w;

	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) {
			fd >> Map[i][j];
		}
	}

    fd.close();

}

int getPath(char Map[][MAX_SIZE], int Path[][MAX_SIZE], int w, int h) {

    for(int i = 0; i <= h; i++){
        Path[i][0] = -1;
    }
    for(int i = 0; i <= w; i++){
        Path[0][i] = -1;
    }

    Path[1][1] = 0;

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(i == 1 && j == 1)
                continue;
            if(Map[i][j] == 'x'){
                Path[i][j] = -1;
                continue;
            }
            Path[i][j] = max(Path[i-1][j], Path[i][j-1]);
            if(Map[i][j] == 'o'){
                Path[i][j]++;
            }
        }
    }

    int coins = 0;

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            coins = max(coins, Path[i][j]);
            cout<<Path[i][j];
        }
        cout<<endl;
    }
    
    return coins;

}
