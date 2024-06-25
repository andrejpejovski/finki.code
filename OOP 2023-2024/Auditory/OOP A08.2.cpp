/*# Квиз

Да се дефинира апстрактна класа QuizAttempt со две чисто виртуелни функции:

`double score()`

`void print()`

Во класата QuizAttempt да се чува информација за бројот на индексот на студентот (низа од 6 знаци).

Од класата Quiz да се изведат две класи: MCQuizAttempt (за претставување на обид на студент на квиз во кој има само прашања со избор на еден од повеќе понудени одговори) и TFQuizAttempt (за претставување на обид на студент на квиз во кој има само прашања за потврдување на вистинитост на некој изказ - точно/неточно).

Во класата MCQuizAttempt дополнително да се чуваат две низи од точно 10 знаци кои се однесуваат на:

Точните одговори на 10-те прашања во квизот

Одговорите кои студентот ги дал на 10-те прашања.

Во класата TFQuizAttempt дополнително да се чуваат две низи од точно 10 bool променливи кои се однесуваат на:

Точната вистинитост на 10-те T/F прашања во квизот

Одговорите кои студентот ги дал на 10-те прашања.

За класите да се имплементираат потребните конструктори.

Да се имплементира методот score() во двете класи на следниот начин:

Во класата MCQuizAttempt, студентот добива по 1 поен за секој точен одговор, а по -0.25 за секој неточен одговор

Во класата TFQuizAttempt, студентот добива по 1 поен за секој точен одговор, а по -0.5 за секој неточен одговор.

Да се имплементира методот print() во двете класи, согласно форматот даден во првите 2 тест примери.

Да се имплементира оператор >= за споредба на два обиди на квизови (од кој било тип) според бројот на освоените поени.

Да се имплементира глобална функција double averagePointsOfPassedStudents (QuizAttempt ** attempts, int n) која како резултат ќе го врати просечниот број на освоени поени од обидите на квизот кои се сметаат за положени (имаат најмалку 5.0 поени од вкупно 10.0).*/


#include <iostream>
#include <string.h>
using namespace std;

class QuizAttempt {
protected:
    char *brojIndeks;
public:
    QuizAttempt(char *indeks="") {
        brojIndeks=new char[7];
        strcpy(brojIndeks,indeks);
    }
    QuizAttempt(const QuizAttempt &object) {
        brojIndeks=new char[7];
        strcpy(brojIndeks,object.brojIndeks);
    }
    QuizAttempt &operator=(QuizAttempt &object) {
        if(this!=&object) {
            delete [] brojIndeks;
            brojIndeks=new char[7];
            strcpy(brojIndeks,object.brojIndeks);
        }
        return *this;
    }
    bool operator>=(QuizAttempt &object) {
        if(this->score()>=object.score())
            return true;
        else return false;
    }

    virtual double score()=0;
    virtual void print()=0;

    virtual ~QuizAttempt() {
        delete [] brojIndeks;
    }
};
class MCQuizAttempt:public QuizAttempt {
private:
    char *tocni;
    char *dadeni;
public:
    MCQuizAttempt(char *indeks="", char *tocni="", char *dadeni=""):QuizAttempt(indeks) {
        this->tocni = new char[11];
        strcpy(this->tocni,tocni);
        this->dadeni=new char[11];
        strcpy(this->dadeni,dadeni);
    }
    MCQuizAttempt(const MCQuizAttempt &object):QuizAttempt(object) {
        tocni = new char[11];
        strcpy(tocni,object.tocni);
        dadeni=new char[11];
        strcpy(dadeni,object.dadeni);
    }
    MCQuizAttempt &operator=(MCQuizAttempt &object){
        if(this!=&object) {
            QuizAttempt::operator=(object);
            delete [] tocni;
            delete [] dadeni;
            tocni = new char[11];
            dadeni = new char[11];
            strcpy(tocni,object.tocni);
            strcpy(dadeni,object.dadeni);
        }
        return *this;
    }

    double score() {
        double result=0;
        for(int i=0;i<10;i++) {
            if(dadeni[i]==tocni[i])
                result+=1;
            else result-=0.25;
        }
        return result;
    }
    void print() {
        for(int i=0;i<10;i++) {
            cout<<i+1<<". ";
            cout<<"Correct: "<<tocni[i]<<" ";
            cout<<"Answer: "<<dadeni[i]<<" ";
            cout<<"Points: ";
            if(tocni[i]==dadeni[i])
                cout<<"1"<<endl;
            else cout<<"-0.25"<<endl;
        }
        cout<<"Total score: "<<score()<<endl;
    }

    ~MCQuizAttempt() {
        delete [] tocni;
        delete [] dadeni;
    }
};


class TFQuizAttempt:public QuizAttempt {
private:
    bool *tocni;
    bool *dadeni;
public:
    TFQuizAttempt(char *indeks="", bool *tocni=nullptr, bool *dadeni=nullptr):QuizAttempt(indeks) {
        this->tocni = new bool[10];
        this->dadeni = new bool[10];
        for(int i=0;i<10;i++) {
            this->tocni[i]=tocni[i];
            this->dadeni[i]=dadeni[i];
        }
    }
    TFQuizAttempt(const TFQuizAttempt &object):QuizAttempt(object) {
        for(int i=0;i<10;i++) {
            tocni[i]=object.tocni[i];
            dadeni[i]=object.dadeni[i];
        }
    }
    TFQuizAttempt &operator=(TFQuizAttempt &object) {
        if(this!=&object) {
            QuizAttempt::operator=(object);
            for(int i=0;i<10;i++) {
                this->tocni[i]=object.tocni[i];
                this->dadeni[i]=object.dadeni[i];
            }
        }
        return *this;
    }

    double score() {
        double result=0;
        for(int i=0;i<10;i++) {
            if(tocni[i]==dadeni[i]) {
                result+=1;
            }
            else result-=0.5;
        }
        return result;
    }
    void print() {
        for(int i=0;i<10;i++) {
            cout<<i+1<<". Correct: ";
            if(tocni[i]==true)
                cout<<"True Answer: ";
            else cout<<"False Answer: ";
            if(dadeni[i]==true)
                cout<<"Correct ";
            else cout<<"False ";
            if(tocni[i]==dadeni[i])
                cout<<"1"<<endl;
            else cout<<"-0.5"<<endl;
        }
    }

    ~TFQuizAttempt() {
        delete [] tocni;
        delete [] dadeni;
    }
};

double averagePointsOfPassedStudents (QuizAttempt ** attempts, int n) {
    double passedAttempts=0;
    double sumPointsOfAllPassedAttempts=0;
    for(int i=0;i<n;i++) {
        if(attempts[i]->score()>=5) {
            passedAttempts++;
            sumPointsOfAllPassedAttempts+=attempts[i]->score();
        }
    }
    double result=sumPointsOfAllPassedAttempts/passedAttempts;
}


int main() {
    bool correctAnswersTF[] = {true, false, true, false, true, false, true, false, true, false};
    bool studentAnswersTF[] = {true, false, true, false, true, true, false, false, true, true};
    TFQuizAttempt quiz1("215031", correctAnswersTF, studentAnswersTF);
    quiz1.print();

    cout<<endl;
    system("pause");
    return 0;
}
