//
// Created by Kemal Sarper Sahin on 10.12.2022.
//

#include "Transaction.h"

Transaction::Transaction() {
    aMovie = NULL;
    isreturned = 0;
}

bool Transaction::operator<(Transaction a) {
    if ((*aMovie).movID < a.aMovie->movID) {
        return true;
    } else {
        return false;
    }
}

Transaction::Transaction(Movie *aMovei, int returned) {
    this->aMovie = aMovei;
    this->isreturned = returned;
}

