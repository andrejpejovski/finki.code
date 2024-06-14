/*### Групи на социјална мрежа

Дадена е класа `User` во која се чуваат информации за корисничко име, име на компанијата во која работи и ниво на позицијата во компанијата (број од 1 - 10). Во класата се дефинирани сите потребни конструктори, оператори, set, get методи, оператор за печатење и вчитување. Оваа класа не треба да се менува.

Да се дефинира класа `Group` што ќе означува група корисници. Во неа се чуваат информации за:

- Членовите на групата (динамички алоцирана низа од објекти од класата `User`)
- Големина на групата (број на елементи во низата)
- Име на групата (стринг)

За класата да се имплементираат:

- Потребните конструктори и деструктор
- метод `void addMember (User & u)`што ќе додава нов член во групата. Да не се дозволи додавање на нов член со постоечко корисничко име.
- метод `double rating()` - што ќе го пресмета рејтингот на групата со формулата: `(10 - просечно_ниво_на_позициите_на_членовите) * број_на_членови / 100`.

Да се имплементира класа `PrivateGroup` во која покрај основните информации за една група ќе се чува и:

- Капацитет на приватната група (цел број). Капацитетот е ист за сите приватни групи и иницијално има вредност 10. Тој може да се менува.

За класата да се имплеметнираат потребните конструктори и деструктор.

Во класата `PrivateGroup` да се препокријат методите од класата `Group` на следниот начин:

- метод `void addMember (User & u)` - што ќе додава нов член во групата. Да не се дозволи надминување на капацитетот.
- метод `double rating()` - што ќе го пресмета рејтингот на групата со формулата: `(10 - просечно_ниво_на_позициите_на_членовите) * (број_на_членови / капацитет_на_група) * коефициент_за_приватна_група`. Коефициентот за приватна група е ист за сите приватни групи и изнесува 0.8. Тој не може да се менува!

За двете класи да се дефинира оператор за печатење `<<`. Форматот на печатење на двете групи погледнете го во првите два тест примера.*/

#include <iostream>
#include <cstring>
using namespace std;

class User {
private:
    char *username;;
    char *companyName;
    int positionLevel;
public:
    User(const char *username="",const char *companyName="",const int positionLevel=-1) {
        this->username=new char[strlen(username)+1];
        strcpy(this->username,username);

        this->companyName=new char[strlen(companyName)+1];
        strcpy(this->companyName,companyName);

        this->positionLevel=positionLevel;
    }
    User(const User &object) {
        this->username=new char[strlen(object.username)+1];
        strcpy(this->username,object.username);

        this->companyName=new char[strlen(object.companyName)+1];
        strcpy(this->companyName,object.companyName);

        this->positionLevel=object.positionLevel;
    }
    User &operator=(const User &object) {
        if(this!=&object) {
            delete [] username;
            delete [] companyName;

            this->username=new char[strlen(object.username)+1];
            strcpy(this->username,object.username);

            this->companyName=new char[strlen(object.companyName)+1];
            strcpy(this->companyName,object.companyName);

            this->positionLevel=object.positionLevel;
        }
        return *this;
    }

    //Functions
    char *getUserName() const{
        return username;
    }
    char *getCompanyName() const{
    return companyName;
    }
    int getPositionLevel() const {
        return positionLevel;
    }
    void setUsername(char *username) {
        delete [] username;
        this->username=new char[strlen(username)+1];
        strcpy(this->username,username);
    }
    void setCompanyName(char *companyName) {
        delete [] companyName;
        this->companyName=new char[strlen(companyName)+1];
        strcpy(this->companyName,companyName);
    }
    void setPositoinLevel(int positionLevel) {
        this->positionLevel=positionLevel;
    }
    friend istream &operator>>(istream &input, User &object);

    ~User() {
        delete [] username;
        delete [] companyName;
    }
};
class Group {
protected:
    User *users;
    int numberOfUsers;
    string nameGroup;
public:
    Group(string nameGroup="") {
        this->users=new User[0];
        this->numberOfUsers=0;
        this->nameGroup=nameGroup;
    }
    Group(const Group &object) {
        this->users=new User[0];
        this->numberOfUsers=object.numberOfUsers;
        this->nameGroup=object.nameGroup;
    }
    Group &operator=(Group &object)
    {
        delete [] users;
        users=new User[0];
        numberOfUsers=object.numberOfUsers;
        nameGroup=object.nameGroup;
        return *this;
    }

    //Functions
    virtual void addMember (User & u) {
        bool sameNameFound=false;

        for(int i=0;i<numberOfUsers&&sameNameFound==false;i++) {
            if(strcmp(users[i].getUserName(),u.getUserName())==0) {
                sameNameFound=true;
            }
        }

        if(sameNameFound)
            cout<<"Error: Member \""<<u.getUserName()<<"\" can't be added, same username exists."<<endl<<endl;
        else {
            User *newusers=new User[numberOfUsers+1];
            for(int i=0;i<numberOfUsers;i++) {
                newusers[i]=users[i];
            }
            delete [] users;
            users = newusers;
            users[numberOfUsers++]=u;
        }
    }
    friend ostream &operator<<(ostream &output, Group &object);
    virtual double rating() {
        double avgRating=0;
        for(int i=0;i<numberOfUsers;i++) {
            avgRating+=users[i].getPositionLevel();
        }
        avgRating/=numberOfUsers;

        return (10-avgRating)*numberOfUsers/100;
    }
    int getNumberOfUsers() {
        return numberOfUsers;
    }

    ~Group() {
        delete [] users;
    }
};
class PrivateGroup:public Group {
private:
    static int capacity;
    static double koeficient;
public:
    PrivateGroup(string name=""):Group(name) {}
    PrivateGroup(const PrivateGroup &object) :Group(object){}
    PrivateGroup &operator=(PrivateGroup &object) {
        if(this!=&object)
            Group::operator=(object);
        return *this;
    }

    //Functions
    virtual void addMember (User & u) {
        if(numberOfUsers==capacity)
            cout<<"Error: Member \""<<u.getUserName()<<"\" can't be added, max limit of "<<capacity<<" users was reached."<<endl<<endl;
        else {
            User *newusers=new User[numberOfUsers+1];
            for(int i=0;i<numberOfUsers;i++) {
                newusers[i]=users[i];
            }
            delete [] users;
            users = newusers;
            users[numberOfUsers++]=u;
        }
    }
    friend ostream &operator<<(ostream &output, PrivateGroup &object);
    virtual double rating() {
        double avgRating=0;
        for(int i=0;i<numberOfUsers;i++) {
            avgRating+=users[i].getPositionLevel();
        }
        avgRating/=numberOfUsers;

        return (10-avgRating)*(numberOfUsers/capacity)*koeficient;
    }
    static void setCapacity(int capacity) {
        capacity=capacity;
    }

    ~PrivateGroup(){}
};

//Group Functions
ostream &operator<<(ostream &output, Group &object) {
    output<<"Group: "<<object.nameGroup<<endl;
    output<<"Members: "<<object.numberOfUsers<<endl;
    output<<"Rating: "<<object.rating()<<endl;
    output<<"Members list:"<<endl;
    for(int i=0;i<object.numberOfUsers;i++) {
        output<<i+1<<". Username: "<<object.users[i].getUserName()<<"\t";
        output<<"Name: "<<object.users[i].getCompanyName()<<"\t";
        output<<"Position: "<<object.users[i].getPositionLevel()<<endl;
    }
    return output;
}

//PrivateGroup Functions
int PrivateGroup::capacity=3;
double PrivateGroup::koeficient=0.8;
ostream &operator<<(ostream &output, PrivateGroup &object) {
    output<<"Group: "<<object.nameGroup<<endl;
    output<<"Members: "<<object.numberOfUsers<<endl;
    output<<"Rating: "<<object.rating()<<endl;
    output<<"Members list:"<<endl;
    for(int i=0;i<object.numberOfUsers;i++) {
        output<<i+1<<". Username: "<<object.users[i].getUserName()<<"\t";
        output<<"Name: "<<object.users[i].getCompanyName()<<"\t";
        output<<"Position: "<<object.users[i].getPositionLevel()<<endl;
    }
    return output;
}

//User Functions
istream &operator>>(istream &input, User &object) {
    char tempUsername[100];
    char tempCompanyName[100];

    input >> tempUsername >> tempCompanyName >> object.positionLevel;

    // Deleting existing memory if any
    delete[] object.username;
    delete[] object.companyName;

    // Allocating new memory and copying the data
    object.username = new char[strlen(tempUsername) + 1];
    strcpy(object.username, tempUsername);

    object.companyName = new char[strlen(tempCompanyName) + 1];
    strcpy(object.companyName, tempCompanyName);

    return input;
}


int main() {
    // PrivateGroup g1("Narkomani");
    // User narkoman("najnarkoman123", "CairDOOEL", 10);
    // g1.addMember(narkoman);
    // User dva(narkoman);
    // User tri(dva);
    // User last(tri);
    // g1.addMember(dva);
    // g1.addMember(tri);
    // g1.addMember(last);
    // cout<<g1;

    cout << "INTEGRATION TEST" << endl;
    char name[50];
    int nGroups;
    cin >> nGroups;
    Group **groups = new Group *[nGroups];
    for (int i = 0; i < nGroups; i++) {
        int type;
        cin >> type;
        cin >> name;
        if (type == 1) { //normal group
            groups[i] = new Group(name);
        } else { //private group
            groups[i] = new PrivateGroup(name);
        }
        int nUsers;
        cin >> nUsers;
        for (int j = 0; j < nUsers; j++) {
            User u;
            cin >> u;

            groups[i]->addMember(u);

        }
    }

    cout << "BEFORE CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
    for (int i = 0; i < nGroups; ++i) {
        cout << *groups[i];
    }
    PrivateGroup::setCapacity(15);
    cout << "AFTER CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
    for (int i = 0; i < nGroups; ++i) {
        cout << *groups[i];
    }


    cout<<endl;
    system("pause");
    return 0;
}
