/*Студенти

Од стандарден влез се читаат податоци за непознат број студенти (не повеќе од 100). Податоците се внесуваат така што во секој ред се состои од:

- името
- презимето
- бројот на индекс (формат xxyzzzz)
- четири броја (поени од секоја задача)

со произволен број празни места или табулатори меѓу нив.

Да се напише програма која ќе испечати список на студенти, каде во секој ред ќе има: презиме, име, број на индекс, вкупен број на бодови сортиран според бројот на бодови. При тоа имињата и презимињата да се напишат со голема почетна буква.*/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string.h>
using namespace std;

typedef struct student {
    char name[100];
    char surname[100];
    char indexNumber[10];
    float score1, score2, score3, score4, sum;

    void printFullName() {
        //Formatting the name
        name[0]=toupper(name[0]);
        for(int i=1;i<strlen(name);i++) {
            name[i]=tolower(name[i]);
        }

        //Formatting the surname
        surname[0]=toupper(surname[0]);
        for(int i=1;i<strlen(surname);i++) {
            surname[i]=tolower(surname[i]);
        }


        cout<<setw(15)<<left<<name<<setw(15)<<left<<surname;
    }
}student;

//Calculating total score for every stdent
void calculateScore(student *studentList, int numberStudents) {
    for(int i=0;i<numberStudents;i++) {
        studentList[i].sum=studentList[i].score1+studentList[i].score2+studentList[i].score3+studentList[i].score4;
    }
}

//Bubble sort (hi-lo)
 void sortStudents(student *studentList, int numberStudents)
 {
     for(int j=0;j<numberStudents-1;j++) {
         for(int i=0;i<numberStudents-1;i++) {
             student temp;
             if(studentList[i+1].sum>studentList[i].sum) {
                 temp=studentList[i];
                 studentList[i]=studentList[i+1];
                 studentList[i+1]=temp;
             }
         }
     }
 }

void printAllStudents(student *studentList, int numberStudents) {
    cout<<endl<<endl<<"All Students Sorted (high-low):"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<setw(15)<<left<<"(Name)"<<setw(15)<<left<<"(Surname)"<<setw(10)<<left<<"(Index)"<<setw(10)<<left<<"(Total Score)"<<endl<<endl;
    for(int i=0;i<numberStudents;i++) {
        studentList[i].printFullName();
        cout<<setw(10)<<studentList[i].indexNumber;
        cout<<setw(10)<<studentList[i].sum<<endl;
    }
}

int main() {
    int numberStudents=-1;

    cout<<"Number of students: ";
    cin>>numberStudents;

student studentList[numberStudents];

    //Entering data for every student
    for(int i=0;i<numberStudents;i++) {
        cout<<"Name: ";
        cin>>studentList[i].name;
        cout<<"Surname: ";
        cin>>studentList[i].surname;
        cout<<"Index: ";
        cin>>studentList[i].indexNumber;
        cout<<"Score (x4): "<<endl;
        cin>>studentList[i].score1;
        cin>>studentList[i].score2;
        cin>>studentList[i].score3;
        cin>>studentList[i].score4;
        cout<<endl;
    }


    calculateScore(studentList, numberStudents);
    sortStudents(studentList, numberStudents);
    printAllStudents(studentList, numberStudents);

    cout<<endl;
    system("pause");
    return 0;
}
