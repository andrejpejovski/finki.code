#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char *studentName;
    float studentGPA;
    int yearOfStudy;
public:
    Student(const char *studentName="", float studentGPA=5, int yearOfStudy=1900) {
        this->studentName=new char[strlen(studentName)+1];
        strcpy(this->studentName,studentName);
        this->studentGPA=studentGPA;
        this->yearOfStudy=yearOfStudy;
    }
    Student(const Student &object) {
        this->studentName=new char[strlen(object.studentName)+1];
        strcpy(this->studentName,object.studentName);
        this->studentGPA=object.studentGPA;
        this->yearOfStudy=object.yearOfStudy;
    }

    //year of study +1
    Student operator++(int) {
        Student temp(*this);
        yearOfStudy++;
        return temp;
    }
    //printing student
    friend ostream &operator<<(ostream &output, const Student &object);
    //gpa1 > gpa2
    bool operator>(const Student &object) {
        if(this->studentGPA>object.studentGPA)
            return true;
        else return false;
    }
    Student &operator=(Student &object) {
        if(this==&object)
            return *this;
        else {
            delete [] studentName;
            studentName = new char[strlen(object.studentName)+1];
            strcpy(studentName,object.studentName);
            studentGPA=object.studentGPA;
            yearOfStudy=object.yearOfStudy;
            return *this;
        }
    }

    int getYearOfStudy() {
        return yearOfStudy;
    }
    void setYearOfStudy(int value) {
        yearOfStudy=value;
    }
    float getGPA() {
        return studentGPA;
    }
    char *getName() {
        return studentName;
    }

    ~Student() {
        delete [] studentName;
    }
};
ostream &operator<<(ostream &output, const Student &object) {
    output<<"Name: "<<object.studentName<<"\tGPA: "<<object.studentGPA<<"\tYear: "<<object.yearOfStudy<<endl;
    return output;
}

class Class {
private:
    Student *studentsList;
    int numberOfStudents;
public:
    Class(int numberOfStudents=0)
    {
        this->numberOfStudents=numberOfStudents;
        this->studentsList=new Student[numberOfStudents];
    }
    Class(const Class &object) {
        this->numberOfStudents=object.numberOfStudents;
        this->studentsList=new Student[numberOfStudents];
        for(int i=0;i<numberOfStudents;i++) {
            studentsList[i]=object.studentsList[i];
        }
    }

    Class &operator+=(Student &object) {
        Student *temp=new Student[numberOfStudents+1];
        for(int i=0;i<numberOfStudents;i++) {
        temp[i]=studentsList[i];
        }
        temp[numberOfStudents++]=object;
        delete [] studentsList;
        studentsList=temp;
        return *this;
    }
    Class &operator++(int) {
        for(int i=0;i<numberOfStudents;i++) {
            studentsList[i].setYearOfStudy(studentsList[i].getYearOfStudy()+1);
        }
        return *this;
    }
    friend ostream &operator<<(ostream &output, const Class &object);
    void nagrada() {
        cout<<"Nagrada: "<<endl;
        for(int i=0;i<numberOfStudents;i++) {
            if(studentsList[i].getGPA()==10) {
                cout<<studentsList[i];
            }
        }
    }
    void najvisokProsek() {
        float maksimum=0;
        int studentID;
        for(int i=0;i<numberOfStudents;i++) {
            if(studentsList[i].getGPA()>maksimum) {
                maksimum=studentsList[i].getGPA();
                studentID=i;
            }
        }
        cout<<"Highest GPA in the class is: "<<studentsList[studentID].getGPA()<<endl;
    }

    ~Class() {
        delete [] studentsList;
    }
};
ostream &operator<<(ostream &output, const Class &object)
{
    for(int i=0;i<object.numberOfStudents;i++) {
        output<<object.studentsList[i];
    }
    return output;
}

int main() {
    Student s1("MartinaMartinovska", 9.5, 3);
    Student s2("Darko Darkoski", 7.3, 2);
    Student s3("Angela Angelovska", 10, 3);


    Class c;
    c+=s1;
    c+=s2;
    c+=s3;

    cout<<c;
    // cout << "Nagradeni:" << endl;
    cout<<endl;

    c.nagrada();
    cout<<endl;

    c.najvisokProsek();
    cout<<endl;

    s2++;
    cout<<c<<endl;

    c++;
    cout<<c;

    cout<<endl;
    system("pause");
    return 0;
}
