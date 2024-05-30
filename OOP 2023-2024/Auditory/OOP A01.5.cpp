/*Држави

Да се напише програма која од стандарден влез ќе чита податоци за држави и на екран ќе го отпечати името и презимето на претседателот на државата чиj што главен град има најмногу жители. Податоци за држава:

- име
- претседател
- главен град
- број на жители.

Податоци за град:

- име
- број на жители.

Податоци за претседател:

- име
- презиме
- политичка партија.
*/

#include <iostream>
using namespace std;


typedef struct City {
    char cityName[50];
    int cityPopulation;
}City;

typedef struct President {
    char presidentName[50];
    char presidentSurname[50];
    char politicalParty[50];
}President;

typedef struct Country {
    char countryName[50];
    President president;
    City city;
    int countryPopulation;
}Country;

//Entering data
void enterCountries (Country *country, int numberOfCountries)
{
    for(int i=0;i<numberOfCountries;i++) {
        cout<<"Country name: ";
        cin>>country[i].countryName;
        cout<<"President name: ";
        cin>>country[i].president.presidentName;
        cout<<"President surname: ";
        cin>>country[i].president.presidentSurname;
        cout<<"President's political pary: ";
        cin>>country[i].president.politicalParty;
        cout<<"Country city name: ";
        cin>>country[i].city.cityName;
        cout<<"Country city population: ";
        cin>>country[i].city.cityPopulation;
        cout<<"Country population: ";
        cin>>country[i].countryPopulation;
        cout<<endl<<endl;
    }
}


//Sorting data
void sortCountries(Country *countries, int numberOfCountries) {
    for(int j=0;j<numberOfCountries-1;j++) {
        for(int i=0;i<numberOfCountries-1;i++) {
            Country tempCountry;
            if(countries[i+1].city.cityPopulation>countries[i].city.cityPopulation) {
                tempCountry=countries[i];
                countries[i]=countries[i+1];
                countries[i+1]=tempCountry;
            }
        }
    }
}

int main() {
    int numberOfCountries=-1;
    cout<<"Enter number of countries: ";
    cin>>numberOfCountries;
    Country countries[numberOfCountries];

    enterCountries(countries, numberOfCountries);
    sortCountries(countries,numberOfCountries);
    cout<<"President name of the country which capital city has the biggest population is: "<<endl<<countries[0].president.presidentName<<" "<<countries[0].president.presidentSurname<<endl;

    system("pause");
    return 0;
}
