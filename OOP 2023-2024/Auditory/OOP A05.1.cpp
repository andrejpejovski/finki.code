/*
Динамички алоцирана низа**

Да се напише класа `Array` за работа со еднодимензионални полиња од целобројни елементи. За полето се чуваат информации за неговиот вкупен капцитет, тековниот број на елементи. Резервацијата на меморијата да се врши динамички.

Во класата да се преоптоварат следните оператори: - `+=` за додавање нови броеви во полето и притоа ако е исполнет капацитетот на полето (низата) да се зголеми за 100%. - `-=` која ги брише сите појавувања на целоброниот аргумент во полето, а притоа капацитетот да не се промени. - `<<` за печатење на елементите од полето. - `[]` за пристап до елемент и промена на вредноста на елемент од полето. - `==` за споредба на два објекти од класата `Array`.

Да се тестира класата во main функција.
 */

#include <iostream>
using namespace std;

class Array {
private:
    int capacity;
    int size;
    int *arr;
public:
    Array(int capacity=1)
    {
        this->capacity=capacity;
        size=0;
        arr=new int[capacity];
    }
    Array(const Array &object) {
        capacity=object.capacity;
        size=object.size;

        arr=new int[capacity];

        for(int i=0;i<size;i++) {
            arr[i]=object.arr[i];
        }
    }

    Array &operator+=(int number) {
        if(size==capacity) {
            int *temp=new int[capacity*2];
            for(int i=0;i<size;i++) {
                temp[i]=arr[i];
            }
            capacity*=2;
            delete [] arr;
            arr=temp;
        }
        arr[size++]=number;
        return *this;
    }
    Array &operator-=(int number) {
        int newSize=0;
        int j=0;
        for(int i=0;i<size;i++) {
            if(arr[i]!=number) {
                arr[j++]=arr[i];
                newSize++;
            }
        }
        size=newSize;
        return *this;
    }
    friend ostream &operator<<(ostream &output, Array &object);
    int &operator[](int number) {
        static int error=-1;
        if(number>=0 && number<size) {
            return arr[number];
        }
        else {
            cout<<"Out of range"<<endl;
            return error;
        }
    }
    bool operator==( Array &object) {
        if(capacity!=object.capacity)
            return false;
        else if (size!=object.size)
            return false;
        else {
            for(int i=0;i<size;i++) {
                if(arr[i]!=object.arr[i])
                    return false;
            }
        }
        return true;
    }

    ~Array() {
        delete [] arr;
    }
};

ostream &operator<<(ostream &output, Array &object) {
    for(int i=0;i<object.size;i++) {
        output<<object.arr[i]<<" ";
    }
    for(int i=object.size;i<object.capacity;i++) {
        output<<"- ";
    }
    output<<endl;
    return output;
}

int main() {
    Array a;
    a += (6);
    a += (4);
    a += (3);
    a += (2);
    a += (1);


    Array b(a);
    b -= (2);
    b -= (3);

    a[0] = 9; //primena na operatorot []

    cout << " a: " << a;
    cout << " b: " << b;

    if (a == b) cout << "Isti se";
    else cout << "Ne se isti"<<endl;

    cout<<endl;
    system("pause");
    return 0;
}
