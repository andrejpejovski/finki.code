#include <iostream>
using namespace std;

class Book;
class Library;
class LibraryMember;

class Book {
private:
    string ime;
    string avtor;
    bool dostapnost;

    friend class Library;
    friend void checkOutBook(LibraryMember &member, Library &library, int bookIndex);
public:
    Book(const string &ime="",const string &avtor="", const bool &dostapnost=false) {
        this->ime=ime;
        this->avtor=avtor;
        this->dostapnost=dostapnost;
    }
    Book(const Book &copy) {
        this->ime=copy.ime;
        this->avtor=copy.avtor;
        this->dostapnost=copy.dostapnost;
    }

    ~Book(){}
};
class Library {
private:
    string ime;
    Book books[30];
    int numberOfBooks;

    friend void checkOutBook(LibraryMember &member, Library &library, int bookIndex);
public:
    Library(const string &ime="Brakja Miladinovci", const int &numberOfBooks=0) {
        this->ime=ime;
        this->numberOfBooks=numberOfBooks;
    }





    void addBook(Book &newBook) {
        if(numberOfBooks<2) {
            books[numberOfBooks]=newBook;
            numberOfBooks++;
        }
        else cout<<"Ne mozhe da se dodade nova kniga bidejki e bibliotekata e polna MAX 30 knigi"<<endl;
    }
    int getNumberOfBooks() {
        return numberOfBooks;
    }
    Book *getBooksList() {
        return books;
    }
    void print() {
        cout<<"Biblioteka ime: "<<ime<<endl;
        cout<<"Bibliotekata raspolaga so "<<numberOfBooks<<" knigi vo momentov"<<endl;
    }





    ~Library(){}
};
class LibraryMember {
private:
    string ime;
    int broj;

    friend void checkOutBook(LibraryMember &member, Library &library, int bookIndex);
public:
    LibraryMember(const string &ime="", const int &broj=-1) {
        this->ime=ime;
        this->broj=broj;
    }
    ~LibraryMember() {}
};


//Global Functions
void checkOutBook(LibraryMember &member, Library &library, int bookIndex)
{
    if(library.books[bookIndex].dostapnost==true) {
        cout<<member.ime<<" ID: "<<member.broj<<" checks out "<<library.books[bookIndex].ime<<endl;
        library.books[bookIndex].dostapnost==false;
    }
    else cout<<"Book: "<<library.books[bookIndex].ime<<" is not available"<<endl;
}


int main() {
    int n;
    cout<<"Enter number of books: ";
    cin>>n;

    Library Fetkin("Fetkin", 0);
    LibraryMember person ("Ime Imenkovski", 123456);

    //Entering books
    for(int i=0;i<n;i++) {
        string ime,avtor;
        bool dostapnost;

        cin>>ime>>avtor>>dostapnost;
        Book newBook(ime,avtor,dostapnost);
        Fetkin.addBook(newBook);
    }

    cout<<endl;
    Fetkin.print();
    cout<<endl;
    checkOutBook(person,Fetkin,1);

    cout<<endl;
    system("pause");
    return 0;
}
