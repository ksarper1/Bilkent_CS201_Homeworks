//
// sec1-Kemal-Sarper-Şahin-22103801
//

#include "City.h"
using namespace std;

City::City(string aCityName) {
    this->cityName=aCityName;
    this->isVisited = false;
    this->adjacentCities="";
    this->nextCityPos = 0;
}


City::City() {
    this->cityName="";
    this->adjacentCities="";
    this->isVisited = false;
    this->nextCityPos = 0;


}

void City::setCityName(string aCityName) {
    this->cityName=aCityName;
}

City &City::operator=(const City &other) {
    if(this == &other){
        return *this;
    }
    this->cityName = other.cityName;
    this->adjacentCities = other.adjacentCities;
    this->nextCityPos = other.nextCityPos;

}

void City::initialize1(const City &other) {
    this->cityName = other.cityName;
    this->adjacentCities = other.adjacentCities;
    this->nextCityPos = other.nextCityPos;

}
bool City::operator>(const City &other) {
    bool found = false;
    string thisName = (cityName);
    string otherName = (other.cityName);

        if(thisName.compare(otherName) > 0){ // this < other
            return true;
        }
        else return false;

    //string z[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    //string T = this->cityName.substr(0,1);
    //string O = other.cityName.substr(0,1);
    //int Tindex=0;
    //int Oindex=0;
    //for (int i = 0; i < 26; ++i) {
    //    if(z[i]==T){
    //        Tindex = i;
    //    }
    //    if(z[i]==O){
    //        Tindex = Oindex;
    //    }
    //}
    //
    //return Tindex>Oindex;

}

string City::getNextAdjacentCity() {
    if(nextCityPos == adjacentCities.size()){
        return "-1";
    }
    else
        nextCityPos++;
    return adjacentCities.substr(nextCityPos-1,1);
}
