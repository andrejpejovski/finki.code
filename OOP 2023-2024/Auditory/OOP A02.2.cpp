/*Вработен

Да се напише класа во која ќе се чуваат основни податоци за вработен:

- име
- плата
- работна позиција (работната позиција може да биде вработен, директор или шеф).

Напишете главна програма во која се читаат од стандарден влез податоци за N вработени, а потоа се пачати листа на вработените сортирани според висината на платата во опаѓачки редослед.
*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <set>
using namespace std;

enum position {worker, director, chief};


//Classes
class Employee {
private:
    char name[50];
    float salary;
    position pos;
public:
    Employee(char *name="", float salary=0, position pos=worker) {
        strcpy(this->name,name);
        this->salary=salary;
        this->pos=pos;
    }
    ~Employee(){}

    //Setters
    void setName(char *name) {
        strcpy(this->name,name);
    }
    void setSalary(float salary) {
        this->salary=salary;
    }
    void setPosition(position pos) {
        this->pos=pos;
    }

    //Getters
    char *getName() {
        return name;
    }
    float getSalary() {
        return salary;
    }
    position getPosition() {
        return pos;
    }

};





//Not class - Functions prototypes
void enterData(Employee *employeeList, int numberEmployees);
void employeesSort(Employee *employeeList, int numberEmployees);
void printEmployees(Employee *employeeList, int numberEmployees);

int main() {
    cout<<"For how many employees will you enter data: ";

    int numberEmployees;
    cin>>numberEmployees;
    cout<<endl;
    Employee employeeList[numberEmployees];

    enterData(employeeList, numberEmployees);
    employeesSort(employeeList, numberEmployees);
    printEmployees(employeeList, numberEmployees);


    cout<<endl;
    system("pause");
    return 0;
}


//Functions body - PROTOTYPES
void enterData(Employee *employeeList, int numberEmployees) {
    for(int i=0;i<numberEmployees;i++) {
        char name[50];
        float salary;
        int pos;

        cout<<"Name: ";
        cin>>name;
        employeeList[i].setName(name);
        cout<<"Salary: ";
        cin>>salary;
        employeeList[i].setSalary(salary);
        cout<<"Position (1-Employee, 2-Director, 3-Chief): ";
        cin>>pos;
        employeeList[i].setPosition((position)pos);
    }
}

void employeesSort(Employee *employeeList, int numberEmployees) {
    Employee temp;
    for(int j=0;j<numberEmployees-1;j++) {
        for(int i=0;i<numberEmployees-1;i++) {
            if(employeeList[i+1].getSalary()>employeeList[i].getSalary()) {
                temp=employeeList[i];
                employeeList[i]=employeeList[i+1];
                employeeList[i+1]=temp;
            }
        }
    }
}

void printEmployees(Employee *employeeList, int numberEmployees) {
    cout<<endl<<"--------------------------------------------------";
    cout<<endl<<endl<<setw(20)<<left<<"Name:"<<setw(10)<<"Salary:"<<setw(10)<<"Position"<<endl;
    for(int i=0;i<numberEmployees;i++) {
        cout<<setw(20)<<employeeList[i].getName();
        cout<<setw(10)<<employeeList[i].getSalary();
        if(employeeList[i].getPosition()==1)
            cout<<setw(10)<<"Employee"<<endl;
        else if(employeeList[i].getPosition()==2)
            cout<<setw(10)<<"Director"<<endl;
        else if(employeeList[i].getPosition()==3)
            cout<<setw(10)<<"Chief"<<endl;
    }
}