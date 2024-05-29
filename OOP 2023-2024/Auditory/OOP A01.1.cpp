/*Date

Да се напише програма која ќе споредува два датуми (ден, месец, година) и ќе ја пресмета разликата во денови од едниот до другиот датум. Пресметките да се реализираат во посебни функции. За датумот да се дефинира посебна структура date. */

#include <iostream>
#include <iomanip>
using namespace std;

typedef struct date
{
    int day;
    int month;
    int year;
}date;

void printDate(date date)
{
    cout<<"Date: ";
    cout<<setfill('0')<<setw(2)<<date.day;
    cout<<".";
    cout<<setfill('0')<<setw(2)<<date.month;
    cout<<".";
    cout<<setfill('0')<<setw(4)<<date.year<<endl;
}

int compareDates(date d1, date d2)
{
    //1 date1>date2
    //0 if they are equal
    //2 date2>date1

    if(d1.year>d2.year) {
        return 1;
    }else if(d2.year>d1.year) {
        return 2;
    }else if(d1.month>d2.month) {
        return 1;
    }else if(d2.month>d1.month) {
        return 2;
    }else if(d1.day>d2.day) {
        return 1;
    }else if(d2.day>d1.day) {
        return 2;
    }else {
        return 0;
    }
}

void calculateDates(date d1, date d2) {
    int compareResultFunction=-1;
    int daysDiff=-1;

    compareResultFunction=compareDates(d1, d2);

    if(compareResultFunction==1) {
        daysDiff=(d1.year-d2.year)*365+(d1.month-d2.month)*30+(d1.day-d2.day);
        cout<<"Date 1 is ahead: "<<daysDiff<<" days.";
    }else if(compareResultFunction==2) {
        daysDiff=(d2.year-d1.year)*365+(d2.month-d1.month)*30+(d2.day-d1.day);
        cout<<"Date 2 is ahead: "<<daysDiff<<" days.";
    }else {
        cout<<"Both dates are identical.";
    }
}

int main() {
    date d1, d2;



    //Date 1
    cout<<"Enter date:"<<endl<<"Day:";
    cin>>d1.day;

    cout<<"Month:";
    cin>>d1.month;

    cout<<"Year:";
    cin>>d1.year;


    //Date 2
    cout<<endl<<endl<<"Enter date:"<<endl<<"Day:";
    cin>>d2.day;

    cout<<"Month:";
    cin>>d2.month;

    cout<<"Year:";
    cin>>d2.year;

    cout<<endl;
    printDate(d1);
    printDate(d2);
    cout<<endl;

    calculateDates(d1,d2);

    return 0;
}
