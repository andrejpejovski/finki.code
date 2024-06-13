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
        return deposit-price();
    }

    ~HotelReservation(){}
};
class HalfBoardHotelReservation:public HotelReservation {
public:
    HalfBoardHotelReservation(const string &ime="", const string &prezime="", const int denovi=0, const int lica=0):HotelReservation(ime,prezime,denovi,lica){}

    //Functions
    int price(int deposit) const {
        return 30*lica*denovi;
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
        if(amount>hr.price()) {
            balance+=hr.price();
            return amount-hr.price();
        }
        else return -1;
    }

    ~Hotel(){}
};

int main() {
    Hotel h("Bristol");
    HotelReservation *hr1 = new HotelReservation("Petko", "Petkovski", 5, 5);
    int cena = h.pay(*hr1, 1000);
    if (cena != -1)
    cout << "Kusur : " << cena << endl;
    HalfBoardHotelReservation *hr2 =
            new HalfBoardHotelReservation("Risto", "Ristovski", 5, 5);
    cena = h.pay(*hr2, 1000);
    if (cena != -1)
        cout << "Kusur : " << cena << endl;
    //покажувач кон основна класа покажува кон објект од изведена
    HotelReservation *hr3 = new HalfBoardHotelReservation("Ana", "Anovska", 4, 2);
    cena = h.pay(*hr3, 100);
    if (cena != -1)
        cout << "Kusur : " << cena << endl;
    HalfBoardHotelReservation hr4("Tome", "Tomovski", 5, 3);
    cena = h.pay(hr4, 1000);
    if (cena != -1)
        cout << "Kusur : " << cena << endl;

    cout<<endl;
    system("pause");
    return 0;
}
