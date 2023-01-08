//
// sec1-Kemal-Sarper-Şahin-22103801
//

#include "FlightMap.h"
#include <iostream>
#include "City.h"



FlightMap::FlightMap(const string cityFile, const string flightFile) {

    ifstream newfile1(cityFile);
    ifstream newfile2(flightFile);
    ifstream x(cityFile);
    ifstream y(flightFile);
    string tp;
    int citySize = 0;
    int flightSize = 0;
    bool isCity = false;
    bool isFlight = false;
    string a,b,from,to;
    int id,cost;

    if(x.is_open()){
        if(y.is_open()){
            while (x>>a){
                citySize++;
            }
            while (y>>a){
                flightSize++;
            }
        }
    }
    cityArr = new City[citySize];
    numberOfcities = citySize;
    flightArr = new Flight[flightSize];
    numberOfFlights = flightSize;



    if(newfile1.is_open()){
        isCity = true;
        if(newfile2.is_open()) {
            isFlight = true;
            int i = 0;
            while (newfile1>>a) {
                cityArr[i].setCityName(a);
                i++;

            }
            i = 0;

            for(int k=0;k<numberOfcities;k++) { //Sorting cities in alphabetical order
                for (int j = 1; j < numberOfcities - k; j++) {
                    if (cityArr[j - 1] > cityArr[j]) {
                        string temp = cityArr[j - 1].cityName;
                        cityArr[j - 1] = cityArr[j];
                        cityArr[j].cityName = temp;
                    }
                }
            }

            while (getline(newfile2,tp)){
                b = tp;
                int pos1 = b.find_first_of(';');    //from
                from = b.substr(0,pos1);
                b = b.substr(pos1+1,b.size()-pos1+1);
                pos1 = b.find_first_of(';');    //to
                to = b.substr(0,pos1);
                b = b.substr(pos1+1,b.size()-pos1+1);
                pos1 = b.find_first_of(';'); //id
                id = stoi(b.substr(0,pos1));
                b = b.substr(pos1+1,b.size()-pos1+1);
                cost = stoi(b);
                flightArr[i].instantiate(from,to,id,cost);
                i++;
            }
            i=0;
            for (int j = 0; j < numberOfFlights; ++j) { //initializing adjacentCities
                string f = flightArr[j].from;
                for (int k = 0; k < numberOfcities; ++k) {
                    if(cityArr[k].cityName==f){
                        cityArr[k].adjacentCities = cityArr[k].adjacentCities + flightArr[j].to;
                    }
                }
            }

            for (int j = 0; j <numberOfcities ; ++j) { //sorting adjacentCities in alphabetic order
                sort(cityArr[j].adjacentCities.begin(), cityArr[j].adjacentCities.end());
            }

        }
        else{
            cout<<"Input file "<<flightFile<<" does not exist"<< endl;
        }
    }
    else {cout<<"Input file "<< cityFile << " does not exist"<<endl;
    }
    newfile1.close();
    newfile2.close();
    if(isFlight&&isCity){
        cout<<citySize <<" cities and " << flightSize  << " flights have been loaded"<< endl;
    }
}

FlightMap::~FlightMap() {
    delete [] cityArr;
    delete [] flightArr;

}

void FlightMap::displayAllCities() const {
    cout<<"The list of the cities that HPAir serves is given below:"<<endl;
    string a = "";
    for (int i = 0; i < numberOfcities; ++i) {
        a= a+cityArr[i].cityName +", ";
    }
    cout<<a<<endl;
}

void FlightMap::displayAdjacentCities(const string cityName) const {
    string s = cityName + " -> ";
    string a = "";

    for (int i = 0; i < numberOfcities; ++i) {
        if(cityArr[i].cityName== cityName){
            cout<<"The cities adjacent to "<<cityName <<" are:"<<endl;
            for (int j = 0; j < cityArr[i].adjacentCities.size(); ++j) {
                a = a+ cityArr[i].adjacentCities.substr(j,1)+ ", ";
            }
        }
    }
    s = s+a;
    cout<<s<<endl;

}

void FlightMap::displayFlightMap() const {
    cout<<"The whole flight map is given below:"<<endl;
    for (int i = 0; i < numberOfcities; ++i) {
        string cityName = cityArr[i].cityName;
        string s = cityName + " -> ";
        string a = "";
        for (int j = 0; j < cityArr[i].adjacentCities.size(); ++j) {
            a = a+ cityArr[i].adjacentCities.substr(j,1)+ ", ";
        }
        s= s+a;
        cout<<s<<endl;
    }
}

void FlightMap::unVisitAll() {
    for (int i = 0; i < numberOfcities; ++i) {
        cityArr[i].isVisited = false;
    }
}

void FlightMap::markVisited(City aCity) {
 aCity.isVisited = true;
}

    void FlightMap::getCity(string name) {
        if(name != "-1"){
            for (int i = 0; i < numberOfcities; ++i) {
                if( name == cityArr[i].cityName ){
                    currCity = &cityArr[i];
                }
            }
        }

    }

int FlightMap::totalFinder(stack<City*> a) {
    City tempTo, tempFrom;
    tempTo = * a.top();
    int size = a.size();
    int total = 0;
    a.pop();
    for (int i = 0; i < size-1; ++i) {
        tempFrom = * a.top();
        for (int j = 0; j < numberOfFlights; ++j) {
            if(flightArr[j].to == tempTo.cityName && flightArr[j].from == tempFrom.cityName ){
                total += flightArr[j].cost;
            }
        }
        tempTo =* a.top();
        a.pop();
    }

    return total;
}

void FlightMap::findFlights(const string deptCity, const string destCity) {
    int fromIndex, toIndex;
    unVisitAll();
    map<int, stack<City *>> aMap;
    bool isDestination;

    for (int i = 0; i < numberOfcities; ++i) {
        if (cityArr[i].cityName == deptCity) {
            fromIndex = i;
        }
        if (cityArr[i].cityName == destCity) {
            toIndex = i;
        }
    }
    aStack.push(&cityArr[fromIndex]);
    aStack.top()->isVisited = true;
    isFinished = false;

    while (!isFinished) {
        if (aStack.top()->getNextAdjacentCity() == "-1") {

            aStack.top()->isVisited = false;
            aStack.top()->nextCityPos = 0;
            aStack.pop();

            isFinished = aStack.empty();
        } else {
            aStack.top()->nextCityPos--;
            getCity(aStack.top()->getNextAdjacentCity());

            if (currCity->cityName == destCity) {
                isDestination = true;
                stack<City *> tempStack;
                aStack.push(currCity);
                int total = totalFinder(aStack);
                int aStackSize = aStack.size();
                for (int i = 0; i < aStackSize; i++) {
                    City *temp1 = aStack.top();
                    tempStack.push(temp1);
                    aStack.pop();
                }
                aMap.insert(pair<int, stack<City *>>(total, tempStack));
                aStackSize = tempStack.size();
                for (int i = 0; i < aStackSize; i++) {
                    City *temp1 = tempStack.top();
                    aStack.push(temp1);
                    tempStack.pop();
                }
                aStack.pop();
            } else if (!currCity->isVisited) {
                currCity->isVisited = true;
                aStack.push(currCity);
            } else {
                //aStack.pop();
            }
        }
    }
    cout << "Request is to fly from " << deptCity << " to " << destCity << ":" << endl;
    if (aMap.empty()) {
        cout << "Sorry. HPAir does not fly from " << deptCity << " to " << destCity << "." << endl;
    } else if(isDestination){
        City tempTo, tempFrom;
        int cost, flightId;

        for (auto i = aMap.begin(); i != aMap.end(); ++i) {
            int size = i->second.size();
            tempFrom = *i->second.top();
            i->second.pop();
            for (int j = 0; j < size - 1; ++j) {
                tempTo = *i->second.top();
                for (int k = 0; k < numberOfFlights; ++k) {
                    if (flightArr[k].to == tempTo.cityName && flightArr[k].from == tempFrom.cityName) {
                        cost = flightArr[k].cost;
                        flightId = flightArr[k].id;
                        cout << "Flight #" << flightId << " from " << flightArr[k].from << " to " << flightArr[k].to
                             << ", Cost: " << cost << " TL" << endl;

                    }
                }
                tempFrom=*i->second.top();
                i->second.pop();
            }
            cout << "Total Cost: " << i->first << " TL" << endl;
        }

    }
}



