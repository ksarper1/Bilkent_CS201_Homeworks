//
// Created by Kemal Sarper Sahin on 10.12.2022.
//

#ifndef HW3_MOVIE_H
#define HW3_MOVIE_H


class Movie {
public:
    int movID;
    int copies;
    int totalCopies;

    Movie(int amovID,int acopies);
    Movie();
    bool operator<(Movie a);
};


#endif //HW3_MOVIE_H
