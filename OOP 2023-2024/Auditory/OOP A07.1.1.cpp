/*
Хотелска резервација

Да се дефинира класа `HotelReservation` за хотелска резервација. За хотелската резервација се чува бројот на денови, бројот на лица, име и презиме на лицето за контакт. Да се земе дека цената на резервацијата за едно лице за еден ден е 25 евра.

Во класата да се дефинира функција `price()` која враќа колкава е цената на резервацијата. Во класата да се дефинира функција `price(int amount)` која враќа колкава износ (кусур) треба да се врати од касата ако корисникот на резервацијата ја доставува дадената уплата.

Да се изведе класа `HalfBoardHotelReservation` за полупансионска хотелска резервација за резервирање на хотелска соба со појадок. Цената на појадокот за едно лице за еден ден е 5 евра. Да се препокрие соодветно функцијата `price(int amount)`.

Да се дефинира класа `Hotel` со информации за името на хотелот и салдо на хотелот. Во класата да се дефинира функција `int pay(HotelReservation &hr, int amount)`; Со оваа функција треба да се направи уплата за дадена хотелска резервација. Ако уплатата ја надминува бараната сума функцијататреба да врати колку пари треба да му се врати на корисникот кој ја прави уплатата. Уплатата треба да се додаде во салдото на хотелот.*/

#include <iostream>
using namespace std;

class HotelReservation {
protected:
    string ime;
    string prezime;
    int denovi;
    int lica;
public:
    HotelReservation(const string &ime="", const string &prezime="",const int denovi=0, const int lica=0) {
        this->denovi=denovi;
        this->lica=lica;
        this->ime=ime;
        this->prezime=prezime;
    }

    //Functions
    int price() const {
        return 25*denovi*lica;
    }
    virtual int price(int deposit) const {
        int vkupno=25*denovi*lica;
        if(deposit>=vkupno)
            return deposit-vkupno;
        else return -1;
    }

    ~HotelReservation(){}
};
class HalfBoardHotelReservation:public HotelReservation {
public:
    HalfBoardHotelReservation(const string &ime="", const string &prezime="", const int denovi=0, const int lica=0):HotelReservation(ime,prezime,denovi,lica){}

    //Functions
    int price(int deposit) const {
        int vkupno=30*denovi*lica;
        if(deposit>=vkupno) {
            return deposit-vkupno;
        }
        else {
            return -1;
        }

    }

    ~HalfBoardHotelReservation(){}
};
class Hotel {
private:
    string imeHotel;
    int balance;
public:
    Hotel(string imeHotel="", int balance=0) {
        this->imeHotel=imeHotel;
        this->balance=balance;
    }

    //Functions
    int pay(HotelReservation &hr, int amount) {
        int kusur=hr.price(amount);
        if(kusur!=-1) {
            balance+=(amount-kusur);
            return kusur;
        }
        else return -1;
    }
    void printHotelBalance() {
        cout<<"Hotel Balance: $"<<balance<<endl<<endl;
    }

    ~Hotel(){}
};

int main() {
    Hotel h("Finki nova zgrada");

    int numberGuests;
    cout<<"Number of guests: ";
    cin>>numberGuests;

    HotelReservation **reservations=new HotelReservation*[numberGuests];

    for(int i=0;i<numberGuests;i++) {
        int choise=-1;
        cout<<endl<<endl<<"[0] - HotelReservation"<<endl<<"[1] - HalfBoardHotelReservation"<<endl<<endl;
        cin>>choise;
        if(choise==0) {
            string ime,prezime;
            int denovi,lica,suma;
            cout<<"Name: ";
            cin>>ime;
            cout<<"Surname: ";
            cin>>prezime;
            cout<<"Days: ";
            cin>>denovi;
            cout<<"People: ";
            cin>>lica;
            cout<<"Ammount: ";
            cin>>suma;
            reservations[i] = new HotelReservation(ime,prezime,denovi,lica);
            int kusur=h.pay(*reservations[i],suma);
            if(kusur!=-1)
                cout<<"Kusur: "<<kusur;
        }
        else if(choise==1) {
            string ime,prezime;
            int denovi,lica,suma;
            cout<<"Name: ";
            cin>>ime;
            cout<<"Surname: ";
            cin>>prezime;
            cout<<"Days: ";
            cin>>denovi;
            cout<<"People: ";
            cin>>lica;
            cout<<"Ammount: ";
            cin>>suma;
            reservations[i] = new HalfBoardHotelReservation(ime,prezime,denovi,lica);
            int kusur=h.pay(*reservations[i],suma);
            if(kusur!=-1)
                cout<<"Kusur: "<<kusur;

        }
    }

    for(int i=0;i<numberGuests;i++) {
        delete reservations[i];
    }
    delete [] reservations;

    cout<<endl;
    system("pause");
    return 0;
}
