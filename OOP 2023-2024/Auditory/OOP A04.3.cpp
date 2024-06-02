#include <iostream>
#include <iomanip>
using namespace std;


class Student;


class Student {
private:
    string ime;
    int brojIndex;
    float prosek;

    static int brojStudenti;
    static float vkupenProsek;
public:
    Student(const string &ime="", const int &brojIndex=0, const float &prosek=0) {
        this->ime=ime;
        this->brojIndex=brojIndex;
        this->prosek=prosek;
    }


    static float getBrojStudenti() {
        return brojStudenti;
    }
    static float getVkupenProsek() {
        return vkupenProsek;
    }
    static void refreshBrojStudenti() {
        brojStudenti++;
    }
    static void calculateNewVkupenProsek(Student &student) {
        vkupenProsek+=student.prosek;
    }
    void print() {
        cout<<"Ime: "<<ime<<" | Broj index: "<<brojIndex<<" | Prosek: "<<230000+brojIndex<<endl;
    }


    ~Student(){}
};

int Student::brojStudenti = 0;
float Student::vkupenProsek = 0;

int main() {
    cout<<"Kolku studenti ke vnesuvate: ";
    int n;
    cin>>n;

    Student studentiLista[n];

    //Entering all students
    for(int i=0;i<n;i++) {
        string inputIme;
        int inputIndex;
        float inputProsek;

        cin>>inputIme>>inputIndex>>inputProsek;
        Student inputStudent(inputIme,inputIndex,inputProsek);

        studentiLista[i]=inputStudent;
        Student::refreshBrojStudenti();
        Student::calculateNewVkupenProsek(studentiLista[i]);
    }

    //Printing all students
    cout<<endl<<"Vkupno studenti: "<<Student::getBrojStudenti()<<endl;
    cout<<"Prosek za site studenti: "<<Student::getVkupenProsek()/Student::getBrojStudenti()<<endl<<endl;
    for(int i=0;i<n;i++) {
        studentiLista[i].print();
    }

    cout<<endl;
    system("pause");
    return 0;
}
