/*# Array

Да се напише класа Array за работа со вектор од целобројни елементи.

Во класата да се преоптоварат следните оператори: += за додавање нови броеви во векторот и притоа ако е исполнет капацитетот на векторот (низата) да се зголеми за 100%. -= која ги брише сите појавувања на целоброниот аргумент во низата, а притоа капацитетот да не се промени. << за печатење на елементите од низата. - [] за пристап до елемент од векторот, доколку индексот не е валиден да се фрли исклучок (објект од класата IndexOutOfRangeException). - == за споредба на два објекти од класата Array за еднаквост на векторите.

Да се тестира класата во main функција.*/

#include <iostream>
#include <vector>
using namespace std;

class IndexOutOfRangeException {
private:
    int id;
public:
    IndexOutOfRangeException(int id) {
        this->id=id;
    }
    void printException() {
        cout<<"Exception: ID: "<<id<<" is invalid"<<endl;
    }
};
class Array {
private:
    vector<int> vec;
public:
    Array(int capacity=1) {
        vec.reserve(capacity);
    }
    Array &operator+=(int n){
        // cout<<"Pre Size: "<<vec.size()<<endl;
        // cout<<"Pre Capacity: "<<vec.capacity()<<endl;
        if(vec.capacity()==vec.size())
            vec.reserve(vec.capacity()*2);
        vec.insert(vec.end(),n);
        // cout<<"Post Size: "<<vec.size()<<endl;
        // cout<<"Post Capacity: "<<vec.capacity()<<endl<<endl;
        return *this;
    }
    Array &operator-=(int n) {
        int newSize=0;
        int LastID=0;
        for(auto i=vec.begin();i<vec.end();i++) {
            if(*i!=n) {
                vec.at(LastID++)=*i;
            }
        }
        vec.resize(LastID);
        return *this;
    }
    void printVec() {

    }
    void showCapacty() {
        cout<<"Capacity: "<<vec.capacity()<<endl;
    }

    int getSize() {
        return vec.size();
    }

    int operator[](int n) {
        if(n<0 || n>=vec.size())
            throw IndexOutOfRangeException(n);
        else return vec[n];
    }

    int getCapacity() {
        return vec.capacity();
    }
    friend ostream &operator<<(ostream &output, Array &object);

    bool operator==(Array &other) {
        return vec==other.vec;
    }
    ~Array(){};
};


ostream &operator<<(ostream &output, Array &object) {
    for(auto i=0;i<object.getSize();i++) {
        output<<object[i]<<" ";
    }
    output<<endl;
    return output;
}

int main() {
    Array x(2);
    cout<<"Size: "<<x.getSize()<<endl;
    cout<<"Capacity: "<<x.getCapacity()<<endl;
    cout<<"Array: "<<x<<endl;

    cout<<"Test case 1: operator +="<<endl;
    x+=1;
    cout<<"Array: "<<x<<endl;

    cout<<"Test case 2: operator -="<<endl;
    x+=2;
    x+=2;
    x+=3;
    x-=2;
    cout<<"Array: "<<x<<endl;

    cout<<"Test case 3: exceptions"<<endl;
    int temp=0;
    try {
        temp=x[9];
    }
    catch(IndexOutOfRangeException e) {
        e.printException();
        cout<<endl;
    }

    cout<<"Test case 4: operator =="<<endl;
    Array comparator;
    comparator+=0;
    if(x==comparator)
        cout<<"Same arrays"<<endl;
    else cout<<"Not the same arrays"<<endl;

    cout<<endl;
    system("pause");
    return 0;
}
