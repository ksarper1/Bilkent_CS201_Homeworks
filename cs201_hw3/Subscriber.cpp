//
// Created by Kemal Sarper Sahin on 10.12.2022.
//

#include "Subscriber.h"

Subscriber::Subscriber(int id) {
    subID=id;

}

Subscriber::Subscriber() {
    subID=0;
}
Subscriber::~Subscriber() {
    moviesOfSub.clear();
    subID=0;
}
bool Subscriber::operator<(Subscriber a){
    if(this->subID < a.subID){
        return true;
    }
    else{
        return false;
    }
}