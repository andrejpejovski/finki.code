/*
Класа за опис на рационален број. Да се дефинира класа која ќе овозможи работа со дропки.

Operators: cin, cout, +, -, *, * (object, int)
*/

#include <iostream>
using namespace std;

class Dropka {
private:
    float broitel, imenitel;
public:
    Dropka(float broitel=1, float imenitel =1) {
        this->broitel=broitel;
        this->imenitel=imenitel;
    }
    Dropka(const Dropka &object) {
        this->broitel=object.broitel;
        this->imenitel=object.imenitel;
    }

    friend istream &operator>>(istream &input, Dropka &object);
    friend ostream &operator<<(ostream &output, const Dropka &object);
    Dropka operator+(const Dropka &object) {
        float resBroitel=broitel*object.imenitel+imenitel*object.broitel;
        float resImenitel=imenitel*object.imenitel;
        return Dropka(resBroitel,resImenitel);
    }
    friend Dropka operator+(const Dropka &object, float number);
    Dropka operator-(Dropka &object) {
        Dropka result;
        result.broitel=broitel*object.imenitel-imenitel*object.broitel;
        result.imenitel=imenitel*object.imenitel;
        return result;
    }
    Dropka operator*(Dropka &object) {
        Dropka result;
        result.broitel=broitel*object.broitel;
        result.imenitel=imenitel*object.imenitel;
        return result;
    }
    friend Dropka operator*(const Dropka &object, float number);
    operator float(){
        if(imenitel!=0)
            return broitel/imenitel;
        return 0;
    }
    bool operator>>(Dropka &object) {
        if(broitel/imenitel>object.broitel/object.imenitel)
            return true;
        return false;
    }
    bool operator==(Dropka &object) {
        if(broitel*object.imenitel==imenitel*object.broitel)
            return true;
        return false;
    }

    ~Dropka(){}

};
istream &operator>>(istream &input, Dropka &object) {
    cout<<"Vnesi broitel: ";
    input>>object.broitel;

    cout<<"Vnesi imenitel: ";
    input>>object.imenitel;
    return input;
}
ostream &operator<<(ostream &output, const Dropka &object)
{
    output<<object.broitel<<"/"<<object.imenitel;
    return output;
}
Dropka operator+(const Dropka &object, float number)
{
    Dropka result;
    result.broitel=number*object.imenitel+object.broitel;
    result.imenitel=object.imenitel;
    return result;
}
Dropka operator*(const Dropka &object, float number) {
    Dropka result;
    result.broitel=object.broitel*number;
    result.imenitel=object.imenitel;
    return result;
}

int main() {
    //Main funkcijata e iskopirana od zadacata i celata zadaca e napisana vrz osnova na main funckijata za da raboti, ne se dopisani odredeni operatori bidejki ne se baraat vo main funkcijata. Isto taka pri mnozenje na dropkite ne se vrakja uprostenata verzija od dropkata.

    Dropka d1(1, 2), d2(2, 3);
    int x = 5;

    Dropka c;
    cin >> c;
    cout<< "Vnesenata dropka e: " << c << endl;

    cout << "d1: " << d1 <<endl<< "d2: " << d2<<endl;
    cout<<d1 << " + " << d2 << " = " << d1 + d2<<endl;
    cout<< d2 << " + 10"<< " = " << d2 + 10 <<endl;
    cout<<d1 << " - " << d2 << " = " << d1 - d2 <<endl;
    //Ova ne go dava uprosteniot rezultat
    cout<<d1 << " * " << d2 << " = " << d1 * d2 <<endl;

    // Koj operator kje se povika za d2*2 ??
    cout<<d2 << " * 2" << " = " << d2 * 2 <<endl;

    cout<<"(float)" << d2 << " = " << static_cast<float>(d2) <<endl;

    cout<<d1 << " > " << d2 << " = " << (d1 > d2) <<endl;
    cout<< d1 << " == " << d2 << " = " << (d1 == d2) << '\n';

    cout<<endl;
    system("pause");
    return 0;
}
