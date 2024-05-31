/*Триаголник

Да се напише класа за опишување на геометриско тело триаголник. Во класата да се напишат методи за пресметување на плоштината и периметарот на триаголникот.

Потоа да се напише главна програма во која ќе се инстнацира еден објект од оваа класа со вредности за страните кои претходно ќе се прочитаат од стандарден влез. На овој објект да се повикат соодветните методи за пресметување на плоштината и периметарот.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
private:
    float a;
    float b;
    float c;
public:
    Triangle(float a=1, float b=1, float c=1) {
        this->a=a;
        this->b=b;
        this->c=c;
    }
    ~Triangle(){}

    //Function prototypes
    float perimeter();
    float area();

    //Setters
    void setA(float a) {
        this->a=a;
    }
    void setB(float b) {
        this->b=b;
    }
    void setC(float c) {
        this->c=c;
    }

    //Getters
    float getA() {
        return a;
    }
    float getB() {
        return b;
    }
    float getC() {
        return c;
    }
};

int main() {
    float a,b,c;
    Triangle t;

    //Reading values from user
    cout<<"Enter the sides of the triangle:"<<endl;
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;
    cout<<"c: ";
    cin>>c;

    //Setting values in the object instance
    t.setA(a);
    t.setB(b);
    t.setC(c);

    cout<<endl<<"Triangle's perimeter is: "<<t.perimeter()<<endl;
    cout<<"Triangle's area is: "<<t.area()<<endl;


    cout<<endl;
    system("pause");
    return 0;
}

//Functions Implementation
float Triangle::perimeter() {
    return a+b+c;
}

float Triangle::area() {
    float s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}