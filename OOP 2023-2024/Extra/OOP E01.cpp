/*Во програмскиот јазик С++ да се креира структура `Vozenje` за опишување на адреналински возења во забавен парк. Структурата треба да содржи: **(5 поени)**

- Име на возењето ( низа од 100 знаци)
- Времетраење во минути (цел број)
- Цена (децимален број)
- Дали има студентски попуст (1-да, 0-не)

Да се креира структура `ZabavenPark`, што содржи: **(10 поени)**

- Име на забавниот парк (низа од 100 знаци)
- Локација (низа од 100 знаци)
- Низа од адреналински возења во паркот (низа од максимум 100 елементи од структурата Vozenje)
- Број на елементи во низата (цел број)

Да се креира функција print за печатење на информациите за сите возења во забавниот парк во формат: **(10 поени)
[Ime na parkot] [Lokacija]
[Ime1] [Vremetraenje1] [Cena1]
[Ime2] [Vremetraenje2] [Cena2]
[Ime3] [Vremetraenje3] [Cena3]
...
Да се креира функција najdobar_park, што прима низа од променливи од типот `ZabavenPark` и го печати името и локацијата на паркот кој е најефтин за посета од страна на студенти. Најефтин парк е оној што содржи најголем број возења со студентски попуст. Ако повеќе паркови ги делат овие карактеристики, да се испечати паркот со најголемото времетраење од сите возења.** (20 поени)**

Да се дополни функцијата main **(5 поени)**.
*/

#include <iostream>
#include <iomanip>
using namespace std;

typedef struct Vozenje {
    char imeVozenje[100];
    int vremetraenjeVozeje;
    double cenaVozenje;
    bool imaPopustVozenje;
}Vozenje;

typedef struct ZabavenPark {
    char imePark[100];
    char lokacijaPark[100];
    Vozenje vozenja[100];
    int brojVozenja;

    void print() {
        cout<<imePark<<" "<<lokacijaPark<<endl;
        for(int i=0;i<brojVozenja;i++) {
            cout<<vozenja[i].imeVozenje<<" "<<vozenja[i].vremetraenjeVozeje<<" "<<fixed<<setprecision(2)<<vozenja[i].cenaVozenje<<endl;
        }
    }

}ZabavenPark;

void najdobar_park(ZabavenPark *parkovi, int brojParkovi) {
    int vkupnoPopustVozenja[100]={0};
    int popustVoznji=0;

    //sekoj zabaven park;
    for(int i=0;i<brojParkovi;i++) {
        //sekoe vozenje
        for(int j=0;j<parkovi[i].brojVozenja;j++) {
            if(parkovi[i].vozenja[j].imaPopustVozenje) {
                popustVoznji++;
            }
        }
        vkupnoPopustVozenja[i]=popustVoznji;
        popustVoznji=0;
    }

    int max=0;
    //Finding max popust voznji
    for(int i=0;i<brojParkovi;i++) {
        if(vkupnoPopustVozenja[i]>max) {
            max=vkupnoPopustVozenja[i];
        }
    }

    int istiParkovi=0;
    //Finding duplicates
    for(int i=0;i<brojParkovi && istiParkovi<=1;i++) {
        if(vkupnoPopustVozenja[i]==max)
            istiParkovi++;
    }

    //Ako e samo eden takov park
    if(istiParkovi==1) {
        for(int i=0;i<brojParkovi;i++) {
            if(vkupnoPopustVozenja[i]==max)
                cout<<"Najdobar park: "<<parkovi[i].imePark<<" "<<parkovi[i].lokacijaPark<<endl;
        }
    }else {
        //else ima povekje parkovi so ist broj popustVozenja
        //vo ovj slucaj treba da najdeme koj park ima najgolemo vremetraenje na site vozenja
        int vremetraenjeVozenja[100]={0};
        int vremetraenjeVoznjaTemp=0;

        //sekoj zabaven park
        for(int i=0;i<brojParkovi;i++) {
            //presmetaj vkupno vozenje samo na tocnite parkovi
            if(vkupnoPopustVozenja[i]==max) {
                //presmetka na vremtraenje za sekoe vozenje;
                for(int j=0;j<parkovi[i].brojVozenja;j++) {
                    vremetraenjeVoznjaTemp+=parkovi[i].vozenja[j].vremetraenjeVozeje;
                }
                vremetraenjeVozenja[i]=vremetraenjeVoznjaTemp;
                vremetraenjeVoznjaTemp=0;
            }

        }

        //sega samo treba da go najdeme maksimumot na parkot od parkovite cii voznji traat najmnogu
        int finalMax=0;
        for(int i=0;i<brojParkovi;i++) {
            if(vremetraenjeVozenja[i]>finalMax)
                finalMax=vremetraenjeVozenja[i];
        }

        //baranje i pecatenje
        for(int i=0;i<brojParkovi;i++) {
            if(vremetraenjeVozenja[i]==finalMax)
                cout<<"Najdobar park: "<<parkovi[i].imePark<<" "<<parkovi[i].lokacijaPark<<endl;
        }
    }
}

int main() {
    int brojParkovi, brojVozenja;
    cin>>brojParkovi;
    ZabavenPark parks[100];

    for(int i=0;i<brojParkovi;i++) {
        cin>>parks[i].imePark;
        cin>>parks[i].lokacijaPark;
        cin>>parks[i].brojVozenja;
        for(int j=0;j<parks[i].brojVozenja;j++) {
            cin>>parks[i].vozenja[j].imeVozenje;
            cin>>parks[i].vozenja[j].vremetraenjeVozeje;
            cin>>parks[i].vozenja[j].cenaVozenje;
            cin>>parks[i].vozenja[j].imaPopustVozenje;
        }
    }

    for (int i = 0; i < brojParkovi; i++) {
        parks[i].print();
    }
    najdobar_park(parks,brojParkovi);
    //
    // cout<<endl;
    // system("pause");
    return 0;
}
