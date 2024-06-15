#include <iostream>
using namespace std;

class Telo {
protected:
    double visina;
public:
    Telo(double visina=-1) {
        this->visina=visina;
    }
    virtual void pecati()=0;
    virtual double volumen()=0;
    double getVisina()const {
        return visina;
    }
    ~Telo(){};
};
class Cilinder :public Telo {
private:
    double radius;
public:
    Cilinder (double visina=-1, double radius=-1):Telo(visina) {
        this->radius=radius;
    }

    double volumen() {
        return 3.14 * (radius*radius)*visina;
    }
    void pecati() {
        cout<<"Volumen - cilindar: "<<volumen()<<endl;
    }
    double getRadius() {
        return radius;
    }

    ~Cilinder(){}

};

class Konus :public Telo {
private:
    double radius;
public:
    Konus (double visina=-1, double radius=-1):Telo(visina) {
        this->radius=radius;
    };

    double volumen() {
        return 1/3*3.14*(radius*radius)*visina;
    }
    void pecati() {
        cout<<"Volumen - konus: "<<volumen()<<endl;
    }
    double getRadius() {
        return radius;
    }

    ~Konus(){}
};

class Kvadar :public Telo {
private:
    double stranaA, stranaB;
public:
    Kvadar(double visina=-1, double stranaA=-1, double stranaB=-1):Telo(visina) {
        this->stranaA=stranaA;
        this->stranaB=stranaB;
    }

    double volumen() {
        return visina*stranaA*stranaB;
    }
    void pecati() {
        cout<<"Volumen - kvadar: "<<volumen()<<endl;
    }

    ~Kvadar(){}
};

void teloSoNajgolemVolumen(Telo **tela, int n) {
    Telo *najgolem=tela[0];
    for(int i=0;i<n;i++) {
        if(tela[i]->volumen()>najgolem->volumen())
            najgolem=tela[i];
    }
    cout<<"Telo so najgolem volumen: ";
    najgolem->pecati();
}
double getRadius(Telo *g) {
    Konus *k=dynamic_cast<Konus*>(g);
    Cilinder *c=dynamic_cast<Cilinder*>(g);
    int counter=0;
    if(k!=nullptr)
        return k->getRadius();
    else if(c!=nullptr)
        return c->getRadius();
    else return -1;
}

int main() {

    int n; //broj tela
    cout<<"Broj na tela: ";
    cin>>n;

    Telo **tela=new Telo*[n];

    for(int i=0;i<n;i++) {
        int choise;
        cout<<"Kakvo telo sakate? [1-Cilinder, 2-Konus, 3-Kvadar]: ";
        cin>>choise;
        if(choise==1) {
            double visina, radius;
            cout<<"Visina: ";
            cin>>visina;

            cout<<"Radius: ";
            cin>>radius;
            tela[i]=new Cilinder(visina,radius);
        }
        else if(choise==2) {
            double visina, radius;
            cout<<"Visina: ";
            cin>>visina;

            cout<<"Radius: ";
            cin>>radius;
            tela[i]=new Konus(visina,radius);
        }else if(choise==3) {
            double visina, stranaA, stranaB;
            cout<<"Visina: ";
            cin>>visina;

            cout<<"Strana A: ";
            cin>>stranaA;

            cout<<"Strana B: ";
            cin>>stranaB;

            tela[i]=new Kvadar(visina,stranaA,stranaB);
        }
    }

    teloSoNajgolemVolumen(tela,n);

    int counter=0;
    for(int i=0;i<n;i++) {
        if(getRadius(tela[i])!=-1) {
            counter++;
        }
    }
    cout<<"Broj na tela so osnova krug: "<<counter<<endl;

    cout<<endl;
    system("pause");
    return 0;
}
