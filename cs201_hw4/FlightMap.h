//
// sec1-Kemal-Sarper-Şahin-22103801
//

#ifndef HW4_FLIGHTMAP_H
#define HW4_FLIGHTMAP_H

#include <string>
#include "City.h"
#include "Flight.h"
#include <bits/stdc++.h>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class FlightMap {
public:
    City * cityArr;
    City * currCity;
    int numberOfcities;
    Flight * flightArr;
    int numberOfFlights;
    stack<City*> aStack;
    bool isFinished;



    FlightMap( const string cityFile, const string flightFile );
    void unVisitAll();
    void markVisited(City aCity);
    ~FlightMap();
    void displayAllCities() const;
    void displayAdjacentCities( const string cityName ) const;
    void displayFlightMap() const;
    void findFlights( const string deptCity, const string destCity );
    void getCity(string name);
    int totalFinder(stack<City*>);
};


#endif //HW4_FLIGHTMAP_H
