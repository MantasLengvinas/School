#include <iostream>

using namespace std;

int main(){

	int psk, min, n;

	for(int i=1; i<=5; i++){
		cout<<"Kiek tau pamoku?"<<endl;
		cin>>n;
		n+=n;
		psk=n;
	}

	cout<<n<<endl;
	return 0;
}