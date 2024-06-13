/*Да се дефинира класа DebitAccount за работа со дебитна банкарска сметка. За секоја банкарска сметка треба да се чува име и презиме на корисникот (низа од макс. 100 знаци), број на сметка (long број) и моментално салдо (double). Да се овозможат методи за преглед на сметката, депонирање и подигнување на пари од сметката.

Потоа да се дефинира класа CreditAccount што ќе овозможува корисникот на сметката да зема заем од банката. Треба да се овозможи механизам за пресметување на камата доколку корисникот должи пари на банката.*/

#include <iostream>
#include <string.h>
using namespace std;

class DebitAccount {
protected:
    char ime_prezime[100];
    long smetka;
    double sostojba;
public:
    DebitAccount(char *ime_prezime="", long smetka=-1, double sostojba=-1) {
        strcpy(this->ime_prezime,ime_prezime);
        this->smetka=smetka;
        this->sostojba=sostojba;
    }

    //Functions
    void showInfo() {
        cout<<"----------------------------------------"<<endl;
        cout<<"D E B I T   A C C O U N T"<<endl;
        cout<<"Ime i Prezime: "<<ime_prezime<<endl<<"Smetka: "<<smetka<<endl<<"Sostojba: "<<sostojba<<endl;
        cout<<"----------------------------------------"<<endl;
    }
    void deposit(double iznos) {
        cout<<endl<<"*"<<ime_prezime<<" deposited: "<<iznos<<endl;
        sostojba+=iznos;
        cout<<"new balance: "<<sostojba<<endl<<endl;
    }
    void withdraw(double iznos) {
        if(iznos<=sostojba) {
            sostojba-=iznos;
            cout<<endl<<"*"<<ime_prezime<<" withdrawed: "<<iznos<<endl<<"new balance: "<<sostojba<<endl<<endl;
        }
        else {
            cout<<endl<<"*"<<ime_prezime<<" trying to withdraw "<<iznos<<endl<<"Error: No sufficient funds, your balance: "<<sostojba<<endl<<endl;
        }
    }

    ~DebitAccount(){}
};
class CreditAccount:public DebitAccount {
private:
    static double fee;
    double limit;
    double dolg;
public:
    CreditAccount(char *ime_prezime="", long smetka=-1, double sostojba=-1,double limit=0):DebitAccount(ime_prezime,smetka,sostojba) {
        this->limit=limit;
    }

    //Functions
    void showInfo() {
        cout<<"----------------------------------------"<<endl;
        cout<<"C R E D I T   A C C O U N T"<<endl;
        cout<<"Ime i Prezime: "<<ime_prezime<<endl<<"Smetka: "<<smetka<<endl<<"Sostojba: "<<sostojba<<endl<<"Dolg: "<<dolg<<endl<<"Limit: "<<limit<<endl;
        cout<<"----------------------------------------"<<endl;
    }
    void deposit(double iznos) {
        cout<<endl<<"*"<<ime_prezime<<" deposited: "<<iznos<<endl;
        if(dolg>0) {
            if(iznos>dolg) {
                sostojba+=(iznos-dolg);
                dolg=0;
            }
            else {
                dolg-=iznos;
            }
        }
        else sostojba+=iznos;
        cout<<"new balance: "<<sostojba<<endl<<endl;
    }
    void withdraw(double iznos) {
    //dali ima pari
    if((iznos*fee)<=sostojba+(limit-dolg)) {

        //ne e vo minus ima pari na smetka
        if((iznos*fee)<=sostojba && dolg==0) {
            // cout<<"= = = = = = = = = = DEBUG = = = = = = = = = ="<<endl;
            sostojba-=(iznos*fee);
            cout<<endl<<"*"<<ime_prezime<<" withdrawed: "<<iznos<<" + "<<(fee-1)*100<<"% fee -> Total of: "<<iznos*fee<<endl<<"New balance: "<<sostojba<<", your debt: "<<dolg<<endl<<endl;
        }
        //ne e vo minus nema dovolno pari na smetka
        else if((iznos*fee)>sostojba && dolg==0) {
            dolg=(iznos*fee)-sostojba;
            sostojba=0;
            cout<<endl<<"*"<<ime_prezime<<" withdrawed: "<<iznos<<" + "<<(fee-1)*100<<"% fee -> Total of: "<<iznos*fee<<endl<<"New balance: "<<sostojba<<", your debt: "<<dolg<<endl<<endl;
        }
        //vo minus e
        else if(sostojba==0 && dolg>=0) {
            dolg+=(iznos*fee);
            cout<<endl<<"*"<<ime_prezime<<" withdrawed: "<<iznos<<" + "<<(fee-1)*100<<"% fee -> Total of: "<<iznos*fee<<endl<<"New balance: "<<sostojba<<", your debt: "<<dolg<<endl<<endl;
        }
    }else cout<<endl<<"*"<<ime_prezime<<" trying to withdraw "<<iznos<<endl<<"Error: No sufficient funds, you exceed your limit of "<<limit<<endl<<"Your balance: "<<sostojba<<", your debt: "<<dolg<<endl<<endl;
    }

    ~CreditAccount(){}
};

//CreditAccount Functions
double CreditAccount::fee=1.035;

int main() {
    DebitAccount d("Pero Perovski", 6, 100000);
    CreditAccount ca("Mitko Mitkovski", 10, 0, 1000);
    d.showInfo();
    d.deposit(50000);
    d.withdraw(600000);
    d.showInfo();
    ca.showInfo();
    // ca.deposit(500);
    ca.showInfo();
    ca.withdraw(6200);
    ca.withdraw(300);
    ca.showInfo();

    cout<<endl;
    system("pause");
    return 0;
}
