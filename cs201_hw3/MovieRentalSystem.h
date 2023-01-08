//
// Created by Kemal Sarper Sahin on 10.12.2022.
//
#ifndef MRS_h
#define MRS_h
#include "LinkedList.h"
#include "Subscriber.h"
#include "Movie.h"
using namespace std;

class MovieRentalSystem {
public:
    LinkedList<Subscriber> systemSubList;
    LinkedList<Movie> systemMovieList;


    MovieRentalSystem( const string movieInfoFileName,
                       const string subscriberInfoFileName );
    ~MovieRentalSystem();
    void removeMovie( const int movieId );
    void addMovie( const int movieId, const int numCopies );
    void removeSubscriber( const int subscriberId );
    void rentMovie( const int subscriberId, const int movieId );
    void returnMovie( const int subscriberId, const int movieId );
    void showMoviesRentedBy( const int subscriberId ) const;
    void showSubscribersWhoRentedMovie( const int movieId ) const;
    void showAllMovies() const;
    void showAllSubscribers() const;

};
#endif
