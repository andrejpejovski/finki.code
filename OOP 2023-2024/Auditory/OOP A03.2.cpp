/*Екипа

Да се дефинира класа Ekipa што содржи информации за име на екипата, година на формирање и градот од каде потекнува.

Да се дефинира класа Natprevar што содржи информации за домаќин, гостин (објекти од класата Ekipa), голови кои ги постигнал домаќинот и голови кои ги постигнал гостинот.

Да се дефинира посебна функција revans што како аргументи прима два константни (const) објекта од класата Natprevar и проверува дали едниот натпревар е реванш на другиот. Еден натпревар е реваш на друг ако гостинот и домаќинот од првиот натпревар се истите екипи со домаќинот и гостинот од вториот натпревар, соодветно.

Да се дефинира функцијата duel која што како аргументи прима два константни (const) објекта од класата Natprevar. Ако едниот натпревар е реванш на другиот функцијата треба да ја врати екипата која е подобра во меѓусебниот дуел. Во спротивно, треба да испечати порака дека натпреварите не се совпаѓаат. Во случајот кога е нерешено функцијата враќа 0.
*/





#include <iostream>
using namespace std;


class Ekipa {
private:
    string name;
    int yearFounded;
    string cityOrigin;
public:
    Ekipa(int yearFounded=0, string name="",  string cityOrigin="") {
        this->name=name;
        this->yearFounded=yearFounded;
        this->cityOrigin=cityOrigin;
    }

    string getName()const;

    ~Ekipa(){}
};
class Natprevar {
private:
    Ekipa domakin;
    Ekipa gostin;
    int goloviDomakin;
    int goloviGostin;
public:
    Natprevar(const Ekipa &domakin, const Ekipa &gostin, int goloviDomakin=0, int goloviGostin=0) {
        this->domakin=domakin;
        this->gostin=gostin;
        this->goloviDomakin=goloviDomakin;
        this->goloviGostin=goloviGostin;
    }

    int getGoloviDomakin()const;
    int getGoloviGostin()const;
    Ekipa getDomakin()const;
    Ekipa getGostin()const;

    ~Natprevar(){}
};

bool revans(const Natprevar n1, const Natprevar n2);
Ekipa duel (const Natprevar n1, const Natprevar n2);





int main() {
    Ekipa ekipa1(2000, "Ekipa1",  "City1");
    Ekipa ekipa2(2010,"Ekipa2",  "City2");

    Natprevar n1(ekipa1, ekipa2, 2, 2);
    Natprevar n2(ekipa2, ekipa1, 1, 2);

    if(revans(n1,n2)) {
        cout<<"Revans"<<endl<<endl;
            cout<<duel(n1,n2).getName()<<endl;
    }
    else cout<<"Ne e revans"<<endl;


    cout<<endl;
    system("pause");
    return 0;
}





//FUNCTIONS BODIES
string Ekipa::getName()const {
    return name;
}
Ekipa Natprevar::getDomakin() const {
    return domakin;
}
Ekipa Natprevar::getGostin() const{
    return gostin;
}
int Natprevar::getGoloviGostin()const{
    return goloviGostin;
}
int Natprevar::getGoloviDomakin()const {
    return goloviDomakin;
}
bool revans(const Natprevar n1, const Natprevar n2) {
    if(n1.getDomakin().getName()==n2.getGostin().getName()&&n1.getGostin().getName()==n2.getDomakin().getName())
        return true;
    else return false;
}
Ekipa duel (const Natprevar n1, const Natprevar n2) {
    if (revans(n1,n2)==true) {
        int sumGoalsDomakin=n1.getGoloviDomakin()+n2.getGoloviGostin();
        int sumGolasGostin=n1.getGoloviGostin()+n2.getGoloviDomakin();
        if(sumGoalsDomakin>sumGolasGostin)
            return n1.getDomakin();
        else if(sumGolasGostin>sumGoalsDomakin)
            return n1.getGostin();
        else {
            cout<<"Rezultatot e ednakov. Nema pobednil"<<endl;
            return 0;
        }
    }
    else {
            return 0;
    }
}
