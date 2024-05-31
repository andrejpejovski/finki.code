/*E-mail

Да се напише класа која опишува една e-mail порака. Во класата треба да се имплементира метод за прикажување на целокупната порака на екран. Потоа да се напише главна програма во која се внесуваат параметрите на пораката, се инстанцира објект од оваа класа и се печати на екран неговата содржина. За проверување на валидноста на e-mail пораката (постоење на знакот `@` во адресата) да се напише соодветна функција.
*/

#include <iostream>
#include <cstring>
using namespace std;

class Email {
private:
    enum length{emailLength=100, subjectLength=200, bodyLength=500};
    char to[bodyLength];
    char subject[subjectLength];
    char body[bodyLength];
public:
    Email(char *to="", char *subject="", char *body="") {
        strcpy(this->to,to);
        strcpy(this->subject,subject);
        strcpy(this->body,body);
    }
    ~Email(){}

    //Setters
    void setTo(char *to) {
        strcpy(this->to,to);
    }
    void setSubject(char *subject) {
        strcpy(this->subject,subject);
    }
    void setBody(char *body) {
        strcpy(this->body,body);
    }

    //Getters
    char *getTo() {
        return to;
    }
    char *getSubject() {
        return subject;
    }
    char *getBody() {
        return body;
    }

    //Class Functions prototypes
    void printEmail();
    bool validateEmail();
};

//Main Functions prototypes
void enterData(Email *msg);

int main() {
    Email newEmail;

    enterData(&newEmail);
    if(newEmail.validateEmail())
        newEmail.printEmail();
    else cerr<<endl<<"Error in the message"<<endl;

    cout<<endl;
    system("pause");
    return 0;
}


//Clas Functions - Prototypes
void Email::printEmail() {
    cout<<endl<<"------------------------------"<<endl;
    cout<<"To: "<<to<<endl;
    cout<<"Subject: "<<subject<<endl;
    cout<<"Body: "<<body<<endl;
    cout<<"------------------------------"<<endl;
}

bool Email::validateEmail() {
    int counter=0;
    for(int i=0;i<strlen(to);i++) {
        if(to[i]=='@')
            counter++;
    }
    //cout<<"@ times: "<<counter<<endl;
    if(counter!=1)
        return false;
    else return true;
}


//Main functions - Prototypes
void enterData(Email *msg) {
    char input[500];
    cout<<"To: ";
    cin>>input;
    msg->setTo(input);

    cout<<"Subject: ";
    cin>>input;
    msg->setSubject(input);

    cout<<"Body: ";
    cin>>input;
    msg->setBody(input);
}