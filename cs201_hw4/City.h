//
// sec1-Kemal-Sarper-Şahin-22103801
//

#ifndef HW4_CITY_H
#define HW4_CITY_H
#include <string>
#include <iostream>
using namespace std;

class City {
public:
    unsigned int nextCityPos;
    string cityName;
    string  adjacentCities;
    bool isVisited;
    City(string aCityName);
    City();
    City& operator=(const City &other);

    bool operator>(const City &other);
    void setCityName(string aCityName);
    void initialize1(const City &other);
    string getNextAdjacentCity();

};


#endif //HW4_CITY_H
