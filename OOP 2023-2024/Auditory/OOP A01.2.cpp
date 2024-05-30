/*### Vector

Да се напише програма која ќе го пресметува векторскиот и скаларниот производ на два вектори. Векторите се претставени со координати во тродимензионален координатен систем. Скаларниот и векторскиот производ да се пресметуваат со посебни функции. За вектор да се дефинира посебна структура vector.*/

//scalar formula returns a integer: return x * other.x + y * other.y + z * other.z;
//vector formula returns another vector:

/*result.x = y * other.z - z * other.y;
result.y = z * other.x - x * other.z;
result.z = x * other.y - y * other.x;*/

#include <iostream>
using namespace std;

typedef struct vector {
    float x;
    float y;
    float z;
}vector;

float scalarProduct(vector v1, vector v2) {
    return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
}

vector vectorProduct(vector v1, vector v2) {
    vector result;
    result.x=v1.y*v2.z-v1.z*v2.y;
    result.y=v1.z*v2.x-v1.x*v2.z;
    result.z=v1.x*v2.y-v1.y*v2.x;
    return result;
}

void printVector(vector v) {
    cout<<"[ "<<v.x<<", "<<v.y<<", "<<v.z<<" ]"<<endl;
}

int main() {
    vector v1, v2;
    float scalarResult=-1;
    vector vectorResult;
    cout<<"Enter \"xyz\" for the first vector"<<endl;
    cin>>v1.x>>v1.y>>v1.z;

    cout<<endl<<"Enter \"xyz\" for the second vector"<<endl;
    cin>>v2.x>>v2.y>>v2.z;

    cout<<endl<<"Entered vectors: "<<endl;
    printVector(v1);
    printVector(v2);

    scalarResult=scalarProduct(v1,v2);
    cout<<endl<<"Scalar product: "<<scalarResult<<endl;

    vectorResult=vectorProduct(v1,v2);
    cout<<"Vector product: ";
    printVector(vectorResult);

    system("pause");
    return 0;
}
