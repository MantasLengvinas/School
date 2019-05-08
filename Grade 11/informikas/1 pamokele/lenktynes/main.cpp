//Salyga: https://konkursai.if.ktu.lt/index.php/pamokeliu-uzduotys-2/item/359-1-lygis-pam1-2017r-9/7194-nelegalios-marso-rasytoju-lenktynes

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

    int i, k;
    float n, c;
    ofstream fr(FR);

	cin>>i>>n>>k;

    while(k >= i){
        c++;
        k -= i;
    }
    cout<<fixed<<setprecision(2)<<n * c<<endl;

	return 0;
}
