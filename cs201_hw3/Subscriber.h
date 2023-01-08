//
// Created by Kemal Sarper Sahin on 10.12.2022.
//
#ifndef HW3_SUBSCRIBER_H
#define HW3_SUBSCRIBER_H
#include "Movie.h"
#include "LinkedList.h"
#include "Transaction.h"


class Subscriber {
public:
    int subID;
    LinkedList<Transaction> moviesOfSub;
    Subscriber(int id);
    Subscriber();
    ~Subscriber();
    bool operator<(Subscriber a);

};


#endif //HW3_SUBSCRIBER_H
