//
// Created by Sarper on 13.12.2022.
//
#ifndef HW3_TRANSACTION_H
#define HW3_TRANSACTION_H
#include <string>
#include "Movie.h"

class Transaction {
public:
    int isreturned;
    Movie* aMovie;
    Transaction( Movie* aMovei , int returned);
    bool operator<(Transaction a);
    Transaction();
};


#endif //HW3_TRANSACTION_H