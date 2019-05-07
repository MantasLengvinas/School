//13psl 4uzduotis
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    int n, kiek=0, kelintas;
    float aukstis, did, sum=0,vid;

        cout<<"Iveskite fejerverku skaiciu: "<<endl;
        cin>>n;
        cout<<"Iveskite fejerverku auksti: "<<endl;

    for(int i = 0; i < n; i++){
        cin>>aukstis;
        cout<<endl;
        kiek++;
        if(aukstis>did){
            did=aukstis;
            kelintas=kiek;
        }
        sum+=aukstis;
    }

    vid=sum/n;

    cout<<"Auksciausiai issautas fejerverkas buvo: "<<kelintas<<endl;
    cout<<"Jis pakilo i "<<did<<" m auksti"<<endl;
    cout<<"Vienas fejerverkas vidutiniskai pakilo: "<<vid<<" m"<<endl;


	return 0;
}
