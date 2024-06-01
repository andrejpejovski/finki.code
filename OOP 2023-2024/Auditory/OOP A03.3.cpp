#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;





class Datum {
private:
    int den,mesec,godina;
public:
    Datum(int den=1, int mesec=1, int godina=1900) {
        this->den=den;
        this->mesec=mesec;
        this->godina=godina;
    }

    int getDen();
    int getMesec();
    int getGodina();
    void print();
    void setDen(int den);
    void setMesec(int mesec);
    void setGodina(int godina);

    ~Datum(){}
};
class Vraboten {
private:
    char ime[20];
    int plata;
    Datum datumRaganje;
public:
    Vraboten(char *ime="", int plata=0, Datum datumRaganje=Datum()) {
        strcpy(this->ime,ime);
        this->plata=plata;
        this->datumRaganje=datumRaganje;
    }

    //Class functions
    int getPlata()const;
    Datum getDatumRaganje()const;
    void print();
    void setIme(char *ime);
    void setPlata (int plata);
    void setDatumRaganje(int den, int mesec, int godina);


    ~Vraboten(){}
};





//Global functions
Vraboten najgolemaPlata (Vraboten *vraboteni, int n);
bool ePomlad(Datum d1, Datum d2);
Vraboten najmlad (Vraboten *vraboteni, int n);





int main() {
    Datum d1(1, 1, 1980);
    Datum d2(1, 2, 1983);
    Datum d3(11, 12, 1984);

    Vraboten v[3];
    Vraboten v1("Marjan", 40000, d1);
    Vraboten v2("Stefan", 30000, d2);
    Vraboten v3("Marko", 20000, d3);
    v[0] = v1;   v[1] = v2;   v[2] = v3;
    
    cout<<"Najmlad vraboten e: "<<endl;
    najmlad(v,3).print();

    cout<<"Vraboten so najvisoka plata e: "<<endl;
    najgolemaPlata(v,3).print();


    cout<<endl;
    system("pause");
    return 0;
}





//Global Functions Implementation
Vraboten najgolemaPlata(Vraboten *vraboteni, int n) {
    Vraboten temp;
        for(int j=0;j<n-1;j++) {
            for(int i=0;i<n-1;i++) {
                if(vraboteni[i+1].getPlata()>vraboteni[i].getPlata())
                    temp=vraboteni[i];
                    vraboteni[i]=vraboteni[i+1];
                    vraboteni[i+1]=temp;
        }
    }
    return vraboteni[0];
}
bool ePomlad(Datum d1, Datum d2) {
    if(d1.getGodina()>d2.getGodina())
        return true;
    else if(d1.getGodina()<d2.getGodina())
        return false;
    else if(d1.getMesec()>d2.getMesec())
        return true;
    else if(d1.getMesec()<d2.getMesec())
        return false;
    else if(d1.getDen()>d2.getDen())
        return true;
    else if(d1.getDen()<d2.getDen())
        return false;
}
Vraboten najmlad (Vraboten *vraboteni, int n) {
    Vraboten temp;
    for(int j=0;j<n-1;j++) {
        for(int i=0;i<n-1;i++) {
            if(ePomlad(vraboteni[i+1].getDatumRaganje(),vraboteni[i].getDatumRaganje()))

                temp=vraboteni[i];
                vraboteni[i]=vraboteni[i+1];
                vraboteni[i+1]=temp;
        }
    }
    return vraboteni[0];
}



//Class Functions
    //Vraboten
    int Vraboten::getPlata()const
    {
        return plata;
    }
    void Vraboten::print() {
        cout<<"Ime: "<<ime<<" | ";
        cout<<"Plata: "<<plata<<" | ";
        cout<<"Datum na raganje: ";
        datumRaganje.print();
        cout<<endl<<endl;
    }
    void Vraboten::setIme(char *ime) {
        strcpy(this->ime,ime);
    }
    void Vraboten::setPlata (int plata) {
        this->plata=plata;
    }
    Datum Vraboten::getDatumRaganje()const {
        return datumRaganje;
    }
    void Vraboten::setDatumRaganje(int den, int mesec, int godina) {
        datumRaganje.setDen(den);
        datumRaganje.setMesec(mesec);
        datumRaganje.setGodina(godina);
    }



    //Datum
int Datum::getDen(){
return den;
}
int Datum::getMesec(){
return mesec;
}
int Datum::getGodina(){
return godina;
}
void Datum::print() {
    cout<<setfill('0')<<setw(2)<<getDen()<<".";
    cout<<setfill('0')<<setw(2)<<getMesec()<<".";
    cout<<setfill('0')<<setw(4)<<getGodina();
}
void Datum::setDen(int den){
this->den=den;
}
void Datum::setMesec(int mesec){
this->mesec=mesec;
}
void Datum::setGodina(int godina){
this->godina=godina;
}