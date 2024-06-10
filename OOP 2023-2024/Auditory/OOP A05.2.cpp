#include <iostream>
#include <iomanip>
using namespace std;

class ComplexNumber {
private:
    float real;
    float imag;
public:
    ComplexNumber(float real=0, float imag=0) {
        this->real=real;
        this->imag=imag;
    }
    ComplexNumber (const ComplexNumber &object) {
        this->real=object.real;
        this->imag=object.imag;
    }

    ComplexNumber operator+(ComplexNumber &object) {
        ComplexNumber result;
        result.real=real+object.real;
        result.imag=imag+object.imag;
        return result;
    }
    ComplexNumber operator-(ComplexNumber &object) {
        ComplexNumber result;
        result.real=real-object.real;
        result.imag=imag-object.imag;
        return result;
    }
    ComplexNumber operator*(ComplexNumber &object) {
        ComplexNumber result;
        result.real = real * object.real - imag * object.imag;
        result.imag = real * object.imag + imag * object.real;
        return result;
    }
    ComplexNumber operator/(ComplexNumber &object) {
        ComplexNumber result;
        float denominator = object.real * object.real + object.imag * object.imag;
        result.real = (real * object.real + imag * object.imag) / denominator;
        result.imag = (imag * object.real - real * object.imag) / denominator;
        return result;
    }

    ComplexNumber &operator+=(ComplexNumber &object) {
        real=real+object.real;
        imag=imag+object.imag;
        return *this;
    }
    ComplexNumber &operator-=(ComplexNumber &object) {
        real=real-object.real;
        imag=imag-object.imag;
        return *this;
    }
    ComplexNumber &operator*=(ComplexNumber &object) {
        real = real * object.real - imag * object.imag;
        imag = real * object.imag + imag * object.real;
        return *this;
    }
    ComplexNumber &operator/=(ComplexNumber &object) {
        ComplexNumber result;
        float denominator = object.real * object.real + object.imag * object.imag;
        result.real = (real * object.real + imag * object.imag) / denominator;
        result.imag = (imag * object.real - real * object.imag) / denominator;
        return *this;
    }

    bool operator==(ComplexNumber &object) {
        if(real!=object.real)
            return false;
        else if(imag!=object.imag)
            return false;
        else return true;
    }

    friend ostream &operator<<(ostream &output, ComplexNumber &object);
    friend ComplexNumber operator+(float number, ComplexNumber &object);
    friend ComplexNumber operator+(ComplexNumber &object, float number);

    ~ComplexNumber(){}

};

ostream &operator<<(ostream &output, ComplexNumber &object) {
    output<<fixed<<setprecision(3)<<object.real<<" "<<fixed<<setprecision(3)<<object.imag<<"i"<<endl;
    return output;
}
ComplexNumber operator+(float number, ComplexNumber &object) {
    return ComplexNumber(object.real+number,object.imag);
}
ComplexNumber operator+(ComplexNumber &object, float number) {
    return ComplexNumber(object.real+number,object.imag);
}

int main() {
    ComplexNumber c1(2, -6);
    ComplexNumber c2(3, 5);
    ComplexNumber c = c1 + c2;
    cout << c1 << " + " << c2 << " = " << c << endl;
    c = c1 - c2;
    cout << c1 << " - " << c2 << " = " << c << endl;
    c = c1 * c2;
    cout << c1 << " * " << c2 << " = " << c << endl;
    c = c1 / c2;
    cout << c1 << " / " << c2 << " = " << c << endl;
    if (c == c1) {
        cout << "Numbers are equal" << endl;
    }

    c = c1 + 2;
    cout << c1 << " + " << 2 << " = " << c << endl;
    c = 2 + c1;
    cout << 2 << " + " << c1 << " = " << c << endl;


    cout<<endl;
    system("pause");
    return 0;
}
