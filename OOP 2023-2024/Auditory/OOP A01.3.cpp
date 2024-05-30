/*
Да се соберат, одземат и помножат два комплексни броја и функциите да бидат внатре во структурата
*/

#include <iostream>
using namespace std;

typedef struct complexNumber {
    float real;
    float imaginary;

    complexNumber complexNumberAdd (complexNumber number) {
        complexNumber result;
        result.real=real+number.real;
        result.imaginary=imaginary+number.imaginary;
        return result;
    }

    complexNumber complexNumberSubtract (complexNumber number) {
        complexNumber result;
        result.real=real-number.real;
        result.imaginary=imaginary-number.imaginary;
        return result;
    }

    complexNumber complexNumberMultiply (complexNumber number) {
        complexNumber result;
        result.real=real*number.real-imaginary*number.imaginary;
        result.imaginary=real*number.imaginary+imaginary*number.imaginary;
        return result;
    }

    void printComplexNumber() {
        cout<<real<<" + "<<imaginary<<"i"<<endl;
    }
}complexNumber;

int main()
{
    complexNumber n1, n2;

    cout<<"Enter the first Complex Number: "<<endl;
    cout<<"Real: ";
    cin>>n1.real;
    cout<<"Imaginary: ";
    cin>>n1.imaginary;

    cout<<endl<<"Enter the second Complex Number: "<<endl;
    cout<<"Real: ";
    cin>>n2.real;
    cout<<"Imaginary: ";
    cin>>n2.imaginary;

    cout<<endl<<"Numbers entered:"<<endl;
    n1.printComplexNumber();
    n2.printComplexNumber();

    cout<<endl<<"Sum:"<<endl;
    n1.complexNumberAdd(n2).printComplexNumber();

    cout<<endl<<"Difference (A-B):"<<endl;
    n1.complexNumberSubtract(n2).printComplexNumber();

    cout<<endl<<"Difference (B-A):"<<endl;
    n2.complexNumberSubtract(n1).printComplexNumber();

    cout<<endl<<"Product (A*B):"<<endl;
    n1.complexNumberMultiply(n2).printComplexNumber();

    cout<<endl<<"Product (B*A):"<<endl;
    n2.complexNumberMultiply(n1).printComplexNumber();

    system("pause");
    return 0;
}
