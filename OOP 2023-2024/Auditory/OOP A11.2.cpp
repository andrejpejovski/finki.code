/*# Class

Да се напише класа за опис ученици. За секој ученик се чува името, просекот (децимален број) и школска година (цел број). За оваа класа да се имплементираат:

Конструктори и деструктор Оператор ++ за зголемување на запишаната школска година за еден Оператор << за печатење на ученик со сите негови податоци Оператор > за споредување на два ученика според просекот

Потоа треба да се креира класа за опишување на паралелка што содржи вектор од ученици. За оваа класа да се имплементираат:

Конструктори и деструктор Оператор += за додавање на нов студент во паралелката Оператор ++ за зголемување на запишаната школска година за еден за сите студенти во низата Оператор << за печатење на сите ученици во паралелката Метод award што ги печати само оние ученици кои имаат просек 10.0. Метод highestGPA што го печати највисокиот просек во паралелката*/

#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    double GPA;
    int year;
public:
    /*to do
     - konstruktori
     - destruktor
     - op++ year+1
     - op<<
     - op> GPA

     */
    Student(string name="Unknown", double GPA=-1, int year=-1)
    {
        this->name=name;
        this->GPA=GPA;
        this->year=year;
    }
    Student(const Student &other) {
        this->name=other.name;
        this->GPA=other.GPA;
        this->year=other.year;
    }
    Student &operator=(Student other) {
        if(this!=&other) {
            this->name=other.name;
            this->GPA=other.GPA;
            this->year=other.year;
        }
        return *this;
    }
    Student &operator++(int) {
        ++year;
        return *this;
    }

    friend ostream &operator<<(ostream &out, Student &object);

    bool operator>(Student &other) {
        return year>other.year;
    }
    int getGPA() {
        return GPA;
    }

    ~Student(){}
};
class Class {
private:
    vector<Student> students;
public:
    Class(vector<Student> vec=vector<Student>()) {
        this->students=vec;
    }
    Class(const Class &other) {
        this->students=other.students;
    }
    Class &operator=(Class &other) {
        if(this!=&other) {
            this->students=other.students;
        }
        return *this;
    }
    Class &operator+=(Student newStudent)
    {
        students.push_back(newStudent);
        return *this;
    }
    Class operator++(int) {
        for(auto i= 0;i<students.size();i++) {
            students[i]++;
        }
        return *this;
    }
    int getSize() {
        return students.size();
    }
    friend ostream &operator<<(ostream &out, Class cl);
    void award() {
        cout<<"Award (GPA: 10.0): "<<endl;
        for(int i=0;i<students.size();i++) {
            if(students[i].getGPA()==10)
                cout<<students[i];
        }
    }
    void highestGPA() {
        double max=0;
        for(int i=0;i<students.size();i++) {
            if(students[i].getGPA()>max)
                max=students[i].getGPA();
        }
        cout<<"Highest GPA in the class is: "<<max<<endl;
    }
    ~Class(){}
};

ostream &operator<<(ostream &out, Student &object) {
    out<<"Name: "<<object.name<<"\tGPA: "<<object.GPA<<"\tYear: "<<object.year<<endl;
    return out;
}
ostream &operator<<(ostream &out, Class cl) {
    for(int i=0;i<cl.getSize();i++) {
        out<<cl.students[i];
    }
    return out;
}

int main() {
    Student s1("Martina Martinovska", 9.5, 3);
    Student s2("Darko Darkoski", 7.3, 2);
    Student s3("Angela Angelovska", 10, 3);
    Class c;
    c += s1;
    c += s2;
    c += s3;
    cout << c;
    cout << "Awarded:" << endl;
    c.award();
    cout << endl;
    c.highestGPA();
    cout << endl;
    s2++;
    cout << c;
    cout << endl;
    c++;
    cout << c;

    cout<<endl;
    system("pause");
    return 0;
}
