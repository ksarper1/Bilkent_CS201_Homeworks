//
// sec1-Kemal-Sarper-Şahin-22103801
//

#include "Flight.h"

Flight::Flight() {
    from = "";
    to = "";
    id = 0;
    cost = 0;
}

void Flight::instantiate(string f, string t, int id, int cost) {
    this->from = f;
    this->to = t;
    this->id = id;
    this->cost = cost;
}
