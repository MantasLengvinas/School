#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const char FD[] = "data.txt";
const char FR[] = "res.txt";

class Drawing{
    int w, h;

private:

    struct cell{
        int x;
        int y;
        int r;
        int g;
        int b;
    };

    struct rect{
        int x;
        int y;
        int w;
        int h;
        int r;
        int g;
        int b;
    };

    vector<cell> Cells;
    vector<rect> Rects;

public:

    void getRectData(); //Duomenu nuskaitymas i strukturini vektoriu
    void getSize(); //Piesinio dydzio nustatymas pagal ploti, auksti ir koordinates
    void Blank(); //Sukuriamas tuscias piesinys(nustatomos langeliu koordinates ir nustatoma balta spalva)
    void changeColor(int, int); //Spalvos pakeitimo funkcija
    void Draw(); //Staciakampiu piesimas naudojant changeColor funkcija
    void Display(); //Duomenu isvedimas
};

void Drawing::getRectData(){
    ifstream fd(FD);
    int n, x, y, w, h, r, g, b;

    fd>>n;

    for(int i = 0; i < n; i++){
        fd>>x>>y>>w>>h>>r>>g>>b;
        Rects.push_back({x, y, w, h, r, g, b});
    }

    fd.close();
}

void Drawing::getSize(){
    int gw = Rects[0].w, gh = Rects[0].h;

    for(int i = 0; i < Rects.size(); i++){
        if(Rects[i].w + Rects[i].x > gw){
            gw = Rects[i].w + Rects[i].x;
        }
        if(Rects[i].h + Rects[i].y > gh){
            gh = Rects[i].h + Rects[i].y;
        }
    }

    w = gw;
    h = gh;
}

void Drawing::Blank(){
    cell c;

    for(int y = 0; y < h; y++){
        for(int x = 0; x < w; x++){
            c.x = x;
            c.y = y;
            c.r = 255;
            c.g = 255;
            c.b = 255;

            Cells.push_back(c);
        }
    }
}

void Drawing::changeColor(int i, int j){
    Cells[j].r = Rects[i].r;
    Cells[j].g = Rects[i].g;
    Cells[j].b = Rects[i].b;
}

void Drawing::Draw(){
    for(int i = 0; i < Rects.size(); i++){
        for(int j = 0; j < Cells.size(); j++){
            if(Rects[i].x == Cells[j].x && Rects[i].y == Cells[j].y){
                changeColor(i, j);
                if(Rects[i].w > 1){
                    Rects[i].x++;
                    Rects[i].w--;
                }
                if(Rects[i].h > 1){
                    Rects[i].y++;
                    Rects[i].h--;
                }
            }
        }
    }
}

void Drawing::Display(){

    ofstream fr(FR);

    fr<<h<<" "<<w<<endl<<endl;

    for(int i = 0; i < Cells.size(); i++){
        fr<<Cells[i].r<<" "<<Cells[i].g<<" "<<Cells[i].b<<endl;
    }

    fr.close();
}

int main(){

    Drawing D;

    D.getRectData();
    D.getSize();
    D.Blank();
    D.Draw();
    D.Display();

	return 0;
}
