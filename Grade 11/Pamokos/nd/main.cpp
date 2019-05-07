//Suo vejasi kiski

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

    int n, suoliai=0, suo=0, kiskis, liko, sunsSuolis, kiskioSuolis;

    cout<<"Uz kiek pedu nuo suns yra kiskis?"<<endl;
    cin>>n;

    cout<<"Kiek pedu nusoka suo ir kiek kiskis? (Suo turi nusokti toliau)"<<endl;
    cin>>sunsSuolis>>kiskioSuolis;

    if(sunsSuolis<kiskioSuolis){
        cout<<"Suo turi nusokti toliau!"<<endl;
    }
    else{
        kiskis = n;

        while(suo < kiskis){
            suo+=sunsSuolis;
            kiskis+=kiskioSuolis;
            liko=kiskis-suo;
            cout<<"Suo nusoko "<<sunsSuolis<<" peda/u/as"<<endl;
            cout<<"Kiskis nusoko "<<kiskioSuolis<<" peda/u/as"<<endl;
            cout<<"Atstumas tarp ju: "<<liko<<" pedos/u/a"<<endl<<endl;

            suoliai++;

            if(liko<=0){
                cout<<"Suo pavijo kiski nusokes "<<suoliai<<" suoli/iu/ius!"<<endl;
            }

        }
    }

    return 0;
}
