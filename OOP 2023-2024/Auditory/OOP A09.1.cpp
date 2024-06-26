#include <iostream>
#include <string.h>
using namespace std;

class NegativeValueException {
protected:
    char message[100];
public:
    NegativeValueException(char *exception_message="") {
        strcpy(message,exception_message);
    }
    void printException() {
        cout<<"Exception: "<<message<<endl;
    }
    ~NegativeValueException(){};
};
class Discount {
public:
    static float EURMKD;
    static float USDMKD;
    Discount(){}
    virtual float discount_price()=0;
    virtual float price()=0;
    virtual void print_rule()=0;
    virtual ~Discount(){}
};
float Discount::EURMKD=61.5;
float Discount::USDMKD=54.5;

class Product {
protected:
    char name[50];
    float price;
public:
    Product(const char *name="",float price=0) {
        strcpy(this->name,name);
        this->price=price;
    }

    float getPrice() {
        return price;
    }
    char *getName() {
        return name;
    }
    void changePrice(float newPrice) {
        if(newPrice<0) throw NegativeValueException("Negative value entered as product price");
        else price=newPrice;
    }

    ~Product(){}
};

class FoodProduct:public Discount, public Product {
public:
    FoodProduct(char *name="", float price=0):Product(name,price){};
    float discount_price() {
        return price();
    }
    float price() {
        return getPrice();
    }
    void print_rule() {
        cout<<"Hranata nema popust"<<endl;
    }
    ~FoodProduct(){}
};
class Drinks:public Discount, public Product {
protected:
    bool isAlchochol;
public:
    Drinks(char *name="", float price=0, bool isAlchochol=false):Product(name,price) {
        this->isAlchochol=isAlchochol;
    };
    float discount_price() {
        if(isAlchochol && (price()/EURMKD)>20)
            return price()*0.95;
        else if(!isAlchochol && strcmp(name,"Coca-Cola")==0)
            return price()*0.9;
        else return price();
    }
    float price() {
        return getPrice();
    }
    void print_rule() {
        cout<<"Alkoholnite pijaloci >20evra 5% popuust, Coca-Cola 10% popust"<<endl;
    }
    ~Drinks(){}
};
class Cosmetics:public Discount, public Product {
public:
    Cosmetics(char *name="", float price=0):Product(name,price){};
    float discount_price() {
        if(price()/EURMKD>5)
            return price()*0.88;
        else if(price()/USDMKD>20)
            return price()*0.86;
    }
    float price() {
        return getPrice();
    }
    void print_rule() {
        cout<<">5 evra 12% popust, >20 dolari 14% popust"<<endl;
    }
    ~Cosmetics(){}
};

float total_discount(Discount **items, int n) {
    float sum=0;
    for(int i=0;i<n;i++) {
        sum+=items[i]->discount_price();
    }
    return sum;
}

int main() {
    int enteringItems;
    cout<<"How many products you're going to enter: ";
    cin>>enteringItems;

    Discount **items=new Discount*[enteringItems];

    for(int i=0;i<enteringItems;i++) {
        int productType;
        cout<<endl<<"Enter new product: 1-Food Product | 2-Drinks | 3-Cosmetics"<<endl;
        cin>>productType;
        if(productType==1) {
            char name[50];
            float price;

            cout<<"Food name: ";
            cin>>name;
            cout<<"Food price: ";
            cin>>price;

            items[i]=new FoodProduct(name,price);
            cout<<endl;
            items[i]->print_rule();
            cout<<"Price: "<<items[i]->discount_price()<<endl<<endl;
        }else if(productType==2) {
            char name[50];
            float price;
            bool isAlchochol;

            cout<<"Drink name: ";
            cin>>name;
            cout<<"Drink price: ";
            cin>>price;
            cout<<"Is alchocol drink (1-Yes | 0-No): ";
            cin>>isAlchochol;

            items[i]=new Drinks(name,price,isAlchochol);
            cout<<endl;
            items[i]->print_rule();
            cout<<"Price: "<<items[i]->discount_price()<<endl<<endl;
        }else if(productType==3) {
            char name[50];
            float price;

            cout<<"Cosmetic name: ";
            cin>>name;
            cout<<"Cosmetic price: ";
            cin>>price;

            items[i]=new Cosmetics(name,price);
            cout<<endl;
            items[i]->print_rule();
            cout<<"Price: "<<items[i]->discount_price()<<endl<<endl;
        }
    }

    cout<<endl<<"Vkupnata suma so vkluceni popusti na site vneseni proizvodi iznesuva "<<total_discount(items, enteringItems)<<endl;

    cout<<endl<<"Promenete ja cenata na proizvodite od kozmetika"<<endl;
    for(int i=0;i<enteringItems;i++) {
        Cosmetics *ptr=dynamic_cast<Cosmetics*>(items[i]);
        if(ptr!=nullptr) {
            float newPrice;
            cout<<"Vnesi nova cena za "<<ptr->getName()<<": ";
            cin>>newPrice;
            try {
                ptr->changePrice(newPrice);
            }
            catch (NegativeValueException &i) {
                i.printException();
            }
            cout<<"Novata cena za "<<ptr->getName()<<" so popust e: "<<ptr->discount_price()<<endl;
        }
    }


    for(int i=0;i<enteringItems;i++) {
        delete items[i];
    }
    delete [] items;

    cout<<endl;
    system("pause");
    return 0;
}
