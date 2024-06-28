/*Дадена е текстуална датотека “Primer.txt”. Да се напише програма која ќе ја прочита датотеката и на екран ќе го отпечати бројот на редови во кои има повеќе од 10 самогласки, како и вкупниот број на самогласки во датотеката.

Пример. Ако датотеката “Primer.txt” ја има следнава содржина:
Zdravo, kako si?
Eve, dobro sum. A ti?
I jas dobro. Kako se tvoite? Ima li neshto novo?
Dobri se i tie. Si kupiv avtomobil.

тогаш програмата треба да отпечати:
Vkupno 2 reda imaat povekje od 10 samoglaski.
Vo datotekata ima vkupno 42 samoglaski.
 */

#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

int main() {
    int totalValidRows=0, totalVowels=0, subSum=0;
    char c;

    ifstream file;
    file.open("Primer.txt");
    if(file.fail()) {
        cerr<<"Unable to open \"Primer.txt\" file"<<endl;
        return -1;
    }
    while(file.get(c)) {
            if(c!='\n') {
                c=tolower(c);
                if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
                    subSum++;
                    totalVowels++;
                }
            }else if(subSum>10) {
                totalValidRows++;
                subSum=0;
            }
    }

    cout<<"Vkupno "<<totalValidRows<<" reda imaat povekje od 10 samoglaski."<<endl;
    cout<<"Vo datotekata ima vkupno "<<totalVowels<<" samoglaski.";

    return 0;
}
