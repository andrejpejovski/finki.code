#include <iostream>
using namespace std;





class Ekipa {
private:
    string ime;
    int godina;
    string grad;
public:
    Ekipa(const int &godina=0, const string &ime="", const string &grad="") {
        this->ime=ime;
        this->godina=godina;
        this->grad=grad;
    }





    //Getters & Setters
    string getIme() {
        return ime;
    }





    ~Ekipa(){}
};
class Natprevar {
private:
    Ekipa domakin;
    Ekipa gostin;
    int goloviDomakin;
    int goloviGostin;
public:
    Natprevar (const Ekipa &domakin=Ekipa(), const Ekipa &gostin=Ekipa(),
        const int &goloviDomakin=0, const int &goloviGostin=0) {
        this->domakin=domakin;
        this->gostin=gostin;
        this->goloviDomakin=goloviDomakin;
        this->goloviGostin=goloviGostin;
    }





    //Getters & Setters
    Ekipa getDomakin() {
        return domakin;
    }
    Ekipa getGostin() {
        return gostin;
    }
    int getGoloviDomakin() const {
        return goloviDomakin;
    }
    int getGoloviGostin() const {
        return goloviGostin;
    }





    ~Natprevar(){}
};

//Global functions
bool revans(Natprevar &n1, Natprevar &n2) {
    if(n1.getGostin().getIme()==n2.getDomakin().getIme()&&n1.getDomakin().getIme()==n2.getGostin().getIme())
        return true;
    else return false;
}
Ekipa duel(Natprevar &n1, Natprevar &n2) {
    if(revans(n1,n2)) {
        int sumGoloviDomakin=0;
        int sumGoloviGostin=0;

        sumGoloviDomakin=n1.getGoloviDomakin()+n2.getGoloviGostin();
        sumGoloviGostin=n1.getGoloviGostin()+n2.getGoloviDomakin();

        if(sumGoloviDomakin!=sumGoloviGostin) {
            if(sumGoloviDomakin>sumGoloviGostin)
                return n1.getDomakin();
            else
                return n1.getGostin();

        }
        else return 0;
    }
    cout<<"Natprevarite ne se sovpagjaat"<<endl;
    return 0;
}




int main() {
    Ekipa e1(2024,"Ekipa 1", "Skopje");
    Ekipa e2(2024,"Ekipa 2", "Kavadarci");


    Natprevar n1(e1, e2, 1, 1);
    Natprevar n2(e2,e1,2,1);

    cout<<duel(n1,n2).getIme()<<endl;

    cout<<endl;
    system("pause");
    return 0;
}
