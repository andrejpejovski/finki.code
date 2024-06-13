/*Да се дефинира класа за репрезентација на тениски играч. За секој тениски играч треба да се чуваат името, презимето како и тоа дали игра во лига (bool).

Од класата тениски играч да се изведе класа за рангиран тениски играч, која ќе репрезентира играч кој игра на меѓународно ниво. За рангираните тениски играчи дополнително треба да се чува и рангот на тенискиот играч.*/

#include <iostream>
using namespace std;

class TennisPlayer {
protected:
    string ime;
    string prezime;
    bool liga;
public:
    TennisPlayer(string ime="", string prezime="", bool liga=false) {
        this->ime=ime;
        this->prezime=prezime;
        this->liga=liga;
    }
    TennisPlayer(const TennisPlayer &object) {
        ime=object.ime;
        prezime=object.prezime;
        liga=object.liga;
    }

    friend ostream &operator<<(ostream &output, TennisPlayer &object);

    ~TennisPlayer(){}
};
class RankedTennisPlayer:public TennisPlayer {
private:
    int rang;
public:
    RankedTennisPlayer(TennisPlayer &object, int rang=-1) :TennisPlayer(object){
        this->rang=rang;
    }
    RankedTennisPlayer(string ime="", string prezime="", bool liga=false, int rang=-1):TennisPlayer(ime,prezime,liga) {
        this->rang=rang;
    }
    RankedTennisPlayer(const RankedTennisPlayer &object) {
        this->ime=object.ime;
        this->prezime=object.prezime;
        this->liga=object.liga;
        this->rang=object.rang;
    }

    friend ostream &operator<<(ostream &output, RankedTennisPlayer &object);

    ~RankedTennisPlayer(){}
};

//TennisPlayer Functions
ostream &operator<<(ostream &output, TennisPlayer &object) {
    output<<object.ime<<" "<<object.prezime<<" ";
    if(object.liga)
        output<<"igra vo liga";
    else output<<"ne igra vo liga";
    return output;
}

//RankedTennisPlayer Functions
ostream &operator<<(ostream &output, RankedTennisPlayer &object)
{
    TennisPlayer temp(object);
    output<<temp<<", i e rang: "<<object.rang;;
    return output;
}

int main()
{
    TennisPlayer rf("Roger", "Federer");
    TennisPlayer ng("Novak", "Djokovikj");
    cout << rf<<endl;
    cout << ng<<endl;
    // // TennisPlayer t;
    RankedTennisPlayer rn("Rafael", "Nadal", true, 2750);
    cout << rn<<endl;
    TennisPlayer tp = rn;
    cout << tp<<endl;
    //RankedTennisPlayer copy(tp);
    RankedTennisPlayer copy(ng, 3320);
    cout << copy;

    cout<<endl;
    system("pause");
    return 0;
}
