#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// const char FD[] = "monetos.data";
// const char FR[] = "monetos.res";

// struct _node {

// 	int x, y;
// 	char s;
// 	bool inUse;

// };

// struct _path {

// 	vector<_node> Map;
// 	int coins;

// };

// void getData(int &w, int &h, vector<_node> &Map);
// void beginGame(vector<_node> &Map, int w, int h, vector<_path> &usedPaths);

// int main() {

// 	int w, h;
// 	vector<_node> Map;
// 	vector<_path> usedPaths;

// 	getData(w, h, Map);
// 	beginGame(Map, w, h, usedPaths);

// 	return 0;
// }

// void getData(int &w, int &h, vector<_node> &Map) {

// 	ifstream fd(FD);
// 	char s;

// 	fd >> h >> w;

// 	for(int i = 1; i <= h; i++) {
// 		for(int j = 1; j <= w; j++) {
// 			fd >> s;
// 			Map.push_back({i, j, s, false});
// 		}
// 	}

// 	Map[0].inUse = true;

// }

// int mostCoins(vector<_path> usedPaths) {

// 	int most = 0;

// 	for(int i = 0; i < usedPaths.size(); i++) {
// 		if(usedPaths[i].coins > most){
// 			most = usedPaths[i].coins;
// 		}
// 	}

// 	return most;

// }

// void getPath(vector<_node> &Map, int i, int w, int h, int &hmc, vector<_node> &Path) {

	

// }

// void beginGame(vector<_node> &Map, int w, int h, vector<_path> &usedPaths) {

// 	int coins = 0, collectedCoins = 0;

// 	if(usedPaths.size() > 0){
// 		coins = mostCoins(usedPaths);
// 	}

// }

const int MAX_N = 505;
char miestas[MAX_N][MAX_N]; //miesto žemėlapis
const int inf = 1e9;
int DP[MAX_N][MAX_N]; //DP[i][j] žymi, kiek daugiausiai monetų galima surinkti baigiant laukelyje (i, j)

int main() {

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> miestas[i][j];
        }
    }

    for (int i = 0; i <= N; ++i) {
        DP[i][0] = -inf;
    }
    for(int j = 0; j <= M; ++j) {
    	DP[0][j] = -inf;
    }
    DP[1][1] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
        	if(i == 1 && j == 1)
        		continue;
            if(miestas[i][j] == 'x') {
                DP[i][j] = -inf;
                continue;
            }
            int is_siaures = DP[i-1][j];
            int is_rytu = DP[i][j-1];
            DP[i][j] = max(is_siaures, is_rytu);
            if(miestas[i][j] == 'o')
                DP[i][j] += 1;
        }
    }
    int daugiausiai = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            daugiausiai = max(daugiausiai, DP[i][j]);
        }
    }
    cout << daugiausiai << endl;


    return 0;
}

