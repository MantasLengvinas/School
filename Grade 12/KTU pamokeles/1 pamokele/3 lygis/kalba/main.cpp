#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

const char FD[] = "slapta_kalba_data.txt";
const char FR[] = "slapta_kalba_res.txt";

void Duomenys(string &skiemuo, string &slapta);
void Isvedimas(string slapta, string skiemuo);

string Issifravimas(string skiemuo, string slapta);

int main(){

    string skiemuo, slapta;

    Duomenys(skiemuo, slapta);
    Isvedimas(slapta, skiemuo);

	return 0;
}

void Duomenys(string &skiemuo, string &slapta){

    ifstream fd(FD);

    fd>>skiemuo;
    fd.ignore(80, '\n');
    getline(fd, slapta);

    fd.close();

}

void Isvedimas(string slapta, string skiemuo){
    ofstream fr(FR);

    fr<<Issifravimas(skiemuo, slapta);

    fr.close();
}

string Issifravimas(string skiemuo, string slapta){

    size_t vieta;

    while((vieta = slapta.find(skiemuo)) != string::npos){
		slapta.erase(vieta, skiemuo.length());
	}

    return slapta;

}
