/*### Средба

Да се дефинира класа Momche која содржи информации за име, презиме и години. За класата да се дефинираат конструктори, деструктор и метод за печатење на објектот на екран во формат:

Momche: Ime Prezime Godini.

Да се дефинира класа Devojche со истите атрибути и методи со разлика во форматот на печатење:

Devojche: Ime prezime godini.

Креирајте класа Sredba која содржи податоци за едно момче и едно девојче.

Креирајте функција print() која ги печати податоците за момчето и девојчето во следниот формат:

Sredba: Momche: Ime Prezime Godini Devojche: Ime Prezime Godini.

Напишете функција daliSiOdgovaraat() која печати “Si odgovaraat” доколку разликата на нивните години е помала или еднаква на 5 или “Ne si odgovaraat” во спротивно
*/

#include <iostream>
#include <cmath>
using namespace std;





class Momche {
private:
    string name;
    string surname;
    int age;
public:
    Momche(string name="",string surname="",int age=0) {
        this->name=name;
        this->surname=surname;
        this->age=age;
    }
    ~Momche(){}

    void print();
    string getName();
    string getSurname();
    int getAge();
};
class Devojche {
private:
    string name;
    string surname;
    int age;
public:
    Devojche(string name="",string surname="",int age=0) {
        this->name=name;
        this->surname=surname;
        this->age=age;
    }
    ~Devojche(){}

    void print();
    string getName();
    string getSurname();
    int getAge();
};
class Sredba {
private:
    Momche m;
    Devojche d;
public:
    Sredba(Momche m, Devojche d) {
        this->m=m;
        this->d=d;
    }
    ~Sredba(){}

    void print();
    bool daliSiOdgovaraat();
};




int main()
{
    Momche m("Andrej", "Pejovski", 21);
    Devojche d("Name", "Surname", 27);

    Sredba s(m,d);
    s.print();

    if(s.daliSiOdgovaraat()==true)
        cout<<"Si odgovaraat"<<endl;
    else cout<<"Ne si odgovaraat"<<endl;

    cout<<endl;
    system("pause");
    return 0;
}





//FUNCTIONS BODIES
void Momche::print() {
    cout<<"Momche: "<<name<<surname<<age<<endl;
}
void Devojche::print() {
    cout<<"Devojche: "<<name<<surname<<age<<endl;
}
int Momche::getAge()
{
    return age;
}
string Momche::getName() {
    return name;
}
string Momche::getSurname() {
    return surname;
}
string Devojche::getName() {
    return name;
}
string Devojche::getSurname() {
    return surname;
}
int Devojche::getAge()
{
    return age;
}
void Sredba::print() {
    cout<<"Sredba: Momche: "<<m.getName()<<" "<<m.getSurname()<<" "<<m.getAge()<<" Devojche: "<<d.getName()<<" "<<d.getSurname()<<" "<<d.getAge()<<endl;
}
bool Sredba::daliSiOdgovaraat() {
    if(abs(m.getAge()-d.getAge())<=5)
        return true;
    else return false;
}