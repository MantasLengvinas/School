#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <stack>

using namespace std;

struct koord{

    float x, y;

};

int main(){

    vector<koord> K;
    float x, y;

    for(int i = 0; i < 2; i++){
        cin>>x>>y;
        K.push_back({x, y});
    }

    for(auto k : K){
        cout<<k.x<<" "<<k.y<<endl;
    }




	return 0;
}
