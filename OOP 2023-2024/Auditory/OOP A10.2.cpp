/*Да се напише програма која секој ред од дадена текстуална датотека “vlezna.txt” ќе го копира во друга датотека “izlezna.txt”, така што пред секој прочитан ред од датотеката “vlezna.txt” ќе додаде уште еден ред во кој ќе стои бројот на знаци што ги содржи прочитаниот ред. Во секој ред може да има најмногу 80 знаци.

Пример. Ако датотеката “vlezna.txt” ја има следнава содржина:

Jas ucham Objektno-orientirano Programiranje.
Koga se polaga vtoriot kolokvium?
Ne znam, seushte ne e objaveno na sajtot.


тогаш по извршувањето на програмата содржината на датотеката “izlezna.txt” треба да биде следнава:

45
Jas ucham Objektno-orientirano Programiranje.
33
Koga se polaga vtoriot kolokvium?
41
Ne znam, seushte ne e objaveno na sajtot.*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream inputFile;
    ofstream outputFile;

    inputFile.open("vlezna.txt");
    if(inputFile.fail()) {
        cerr<<"Unable to open \"vlezna.txt\" file"<<endl;
        return -1;
    }

    outputFile.open("izlezna.txt",ios_base::trunc);
    if(outputFile.fail()) {
        cerr<<"Unable to open \"izlezna.txt\" file"<<endl;
        return -2;
    }

    string tempRow;
    int totalRowChars=0;
    char c;

    while(getline(inputFile,tempRow)) {
            outputFile<<tempRow.length()<<endl;
            outputFile<<tempRow<<endl;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
