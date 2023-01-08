//
// Created by Kemal Sarper Sahin on 10.12.2022.
//

#include "Movie.h"
Movie::Movie(int amovID, int acopies) {
    movID=amovID;
    copies=acopies;
    totalCopies=copies;
}
Movie::Movie() {
    movID=0;
    copies=0;
    totalCopies=copies;
}
bool Movie::operator<(Movie a){
    if(this->movID < a.movID){
        return true;
    }
    else{
        return false;
    }
}

