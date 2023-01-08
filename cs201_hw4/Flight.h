//
// sec1-Kemal-Sarper-Şahin-22103801
//

#ifndef HW4_FLIGHT_H
#define HW4_FLIGHT_H
#include <string>
using namespace std;

class Flight {
public:
    Flight();
    string from;
    string to;
    int id;
    int cost;
    void instantiate(string f,string t ,int id, int cost);
};


#endif //HW4_FLIGHT_H
