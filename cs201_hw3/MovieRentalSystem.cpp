//
// Created by Kemal Sarper Sahin on 9.12.2022.
//
#include "MovieRentalSystem.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

MovieRentalSystem::MovieRentalSystem(const string movieInfoFileName, const string subscriberInfoFileName) {

    ifstream newfile1(movieInfoFileName);
    ifstream newfile2(subscriberInfoFileName);
    string tp;
    int movieSize;
    int subSize;
    bool isSub = false;
    bool isMov = false;
    int a,b;


    if(newfile1.is_open()){
        isMov= true;
        if(newfile2.is_open()) {
            isSub= true;
            getline(newfile1, tp);
            movieSize = stoi(tp);
            while (newfile1>>a>>b) {
                Movie temp(a, b);
                systemMovieList.insert(temp);
            }
            getline(newfile2,tp);
            subSize = stoi(tp);
            while (getline(newfile2,tp)){
                a = stoi(tp);
                Subscriber temp(a);
                systemSubList.insert(temp);
            }
        }
        else{
            cout<<"Input file "<<subscriberInfoFileName<<" does not exist"<< endl;
        }
    }
    else {cout<<"Input file "<< movieInfoFileName << " does not exist"<<endl;
    }
    newfile1.close();
    newfile2.close();
    if(isSub&&isMov){
        cout<<subSize <<" subscribers and " << movieSize  << " movies have been loaded"<< endl;
    }
}

MovieRentalSystem::~MovieRentalSystem() {
    for (int i = 0; i < systemSubList.itemCount; ++i) {
        systemSubList.getNodeAt(i)->item.moviesOfSub.clear();
    }
    systemSubList.clear();
    systemMovieList.clear();
}

void MovieRentalSystem::removeMovie(const int movieId) {
    for (int i = 0; i <systemMovieList.itemCount ; ++i) {
        if(systemMovieList.getNodeAt(i)->item.movID==movieId){
            if(systemMovieList.getNodeAt(i)->item.copies==systemMovieList.getNodeAt(i)->item.totalCopies){
                systemMovieList.remove(i);
                cout<<"Movie "<< movieId<<" has been removed" <<endl;
                return;
            }
            else{
                cout<<"Movie "<<movieId <<" cannot be removed -- at least one copy has not been returned"<<endl;
                return;
            }
        }
    }
    cout<<"Movie "<< movieId<<" does not exist" <<endl;

}

void MovieRentalSystem::addMovie(const int movieId, const int numCopies) {
    for (int i = 0; i < systemMovieList.itemCount; ++i) {
        if (systemMovieList.getNodeAt(i)->item.movID == movieId) {
            cout<<"Movie "<< movieId<<" already exists" <<endl;
            return;
        }
    }

    Movie temp(movieId, numCopies);
    systemMovieList.insert(temp);
    cout<<"Movie "<< movieId<<" has been added" <<endl;
}

void MovieRentalSystem::removeSubscriber(const int subscriberId) {
    for (int i = 0; i < systemSubList.itemCount; ++i) {
        if(systemSubList.getNodeAt(i)->item.subID==subscriberId) {
            for (int j = 0; j < systemSubList.getNodeAt(i)->item.moviesOfSub.itemCount; ++j) {
                if (systemSubList.getNodeAt(i)->item.moviesOfSub.getNodeAt(j)->item.isreturned == 0) {
                    cout << "Subscriber " << subscriberId<< " cannot be removed -- at least one movie has not been returned"<<endl;
                    return;
                }
            }
        }
    }

    for (int i = 0; i < systemSubList.itemCount;++i) {
        if (systemSubList.getNodeAt(i)->item.subID == subscriberId) {
            cout << "Subscriber " << subscriberId<< " has been removed"<<endl;
            systemSubList.remove(i);

            return;
        }
    }
        cout << "Subscriber " << subscriberId<< " does not exist"<<endl;
        return;
}

void MovieRentalSystem::rentMovie( const int subscriberId, const int movieId ){

    for (int i = 0; i < systemMovieList.itemCount; ++i) {
        if(systemMovieList.getNodeAt(i)->item.movID==movieId){
            if(systemMovieList.getNodeAt(i)->item.copies>0){
                for (int j = 0; j < systemSubList.itemCount; ++j) {
                    if(systemSubList.getNodeAt(j)->item.subID==subscriberId){
                        cout<<"Movie "<<movieId<<" has been rented by subscriber "<<subscriberId<< endl;
                        systemMovieList.getNodeAt(i)->item.copies--;
                        Transaction temp(&systemMovieList.getNodeAt(i)->item , 0);
                        systemSubList.getNodeAt(j)->item.moviesOfSub.insert(temp);
                        return;
                    }
                }
                cout<<"Subscriber "<< subscriberId <<" does not exist"<< endl;
                return;
            }
            cout<< "Movie "<<movieId<<" has no available copy for renting"<< endl;
            return;
        }
    }
    bool outcome = false;
    for (int i = 0; i < systemSubList.itemCount; ++i) {
        if(systemSubList.getNodeAt(i)->item.subID==subscriberId){
            outcome = true;
        }
    }
    if(outcome){
        cout<<"Movie "<< movieId <<" does not exist"<< endl;
        return;
    }
    else{
        cout<<"Subscriber "<<subscriberId<<" and movie "<<movieId<< " do not exist" <<endl;
        return;
    }

}

void MovieRentalSystem::returnMovie(const int subscriberId, const int movieId) {
    bool out = false;
    for (int j = 0; j < systemSubList.itemCount; ++j) {//j sub
        if(systemSubList.getNodeAt(j)->item.subID==subscriberId){

            for (int i = 0; i < systemMovieList.itemCount; ++i) {//mov
                if(systemMovieList.getNodeAt(i)->item.movID==movieId){

                    for (int k = 0; k < systemSubList.getNodeAt(j)->item.moviesOfSub.itemCount; ++k) {//k movies of sub
                        if(systemSubList.getNodeAt(j)->item.moviesOfSub.getEntry(k).aMovie->movID==movieId){
                            if(systemSubList.getNodeAt(j)->item.moviesOfSub.getNodeAt(k)->item.isreturned == 0) {
                                cout << "Movie " << movieId << " has been returned by subscriber " << subscriberId
                                     << endl;
                                systemMovieList.getNodeAt(i)->item.copies++;
                                systemSubList.getNodeAt(j)->item.moviesOfSub.getNodeAt(k)->item.isreturned = 1;
                                return;
                            } else{
                                out = true;
                            }
                        }

                    }
                    if(out) {


                        cout << "No rental transaction for subscriber " << subscriberId << " and movie " << movieId
                             << endl;
                        return;
                    }
                    cout << "No rental transaction for subscriber " << subscriberId << " and movie " << movieId
                         << endl;
                    return;
                }
            }
            cout<<"Movie "<<movieId<< " does not exist"<<endl;
            return;
        }
    }
    cout<<"Subscriber "<< subscriberId <<" does not exist"<< endl;
    return;
}

void MovieRentalSystem::showMoviesRentedBy(const int subscriberId) const {
    bool out = false;
    bool out2 = false;

    for (int i = 0; i < systemSubList.itemCount; ++i) {
        if(systemSubList.getNodeAt(i)->item.subID==subscriberId){
            out = true;
        }
    }
    if(!out){
        cout<<"Subscriber "<< subscriberId <<" does not exist"<< endl;
        return;
    }
    else{
        for (int i = 0; i < systemSubList.itemCount; ++i) {
            if(systemSubList.getNodeAt(i)->item.subID==subscriberId){
                out2 = true;
                if(systemSubList.getNodeAt(i)->item.moviesOfSub.isEmpty()){
                    cout<<"Subscriber "<<subscriberId<<" has not rented any movies"<<endl;
                    return;
                }
                cout<<"Subscriber "<< subscriberId <<" has rented the following movies:"<< endl;
                for (int j = 0; j < systemSubList.getNodeAt(i)->item.moviesOfSub.itemCount; ++j) {
                    if(systemSubList.getNodeAt(i)->item.moviesOfSub.getNodeAt(j)->item.isreturned==0){
                        cout<< systemSubList.getNodeAt(i)->item.moviesOfSub.getNodeAt(j)->item.aMovie->movID<<" not returned"<<endl;
                    } else{
                        cout<< systemSubList.getNodeAt(i)->item.moviesOfSub.getNodeAt(j)->item.aMovie->movID<<" returned"<<endl;
                    }
                }
            }
        }
        if(!out2)cout<<"Subscriber "<< subscriberId <<" does not exist"<< endl;
        return;
    }
}

void MovieRentalSystem::showSubscribersWhoRentedMovie(const int movieId) const {
    bool out2 = false;
    for (int i = 0; i < systemSubList.itemCount; ++i) {
        for (int j = 0; j < systemSubList.getNodeAt(i)->item.moviesOfSub.itemCount; ++j) {
            if(systemSubList.getNodeAt(i)->item.moviesOfSub.getNodeAt(j)->item.aMovie->movID==movieId){
                out2 = true;
            }
        }
    }



    bool out = false;
    for (int i = 0; i < systemMovieList.itemCount; ++i) {
        if(systemMovieList.getNodeAt(i)->item.movID==movieId){
            out = true;
        }
    }
    if(!out){
        cout<<"Movie "<<movieId<< " does not exist"<<endl;
        return;
    }
    if(!out2){
        cout<< "Movie "<<movieId<<" has not been rented by any subscriber"<<endl;
        return;
    }
    cout<<"Movie "<<movieId<< " has been rented by the following subscribers:"<<endl;
    for (int j = 0; j < systemSubList.itemCount; ++j) {
        for (int k = 0; k < systemSubList.getNodeAt(j)->item.moviesOfSub.itemCount; ++k) {
            if(systemSubList.getNodeAt(j)->item.moviesOfSub.getEntry(k).aMovie->movID==movieId){
                if(systemSubList.getNodeAt(j)->item.moviesOfSub.getNodeAt(k)->item.isreturned == 0){
                    cout<<systemSubList.getNodeAt(j)->item.subID<<" not returned"<<endl;
                }
                else cout<<systemSubList.getNodeAt(j)->item.subID<<" returned"<<endl;
            }
        }

    }
}

void MovieRentalSystem::showAllMovies() const {
    cout<<"Movies in the movie rental system:" << endl;
    for (int i = 0; i < systemMovieList.itemCount; ++i) {
        cout<< systemMovieList.getNodeAt(i)->item.movID << " " << systemMovieList.getNodeAt(i)->item.totalCopies <<endl;
    }
}

void MovieRentalSystem::showAllSubscribers() const {

    cout<<"Subscribers in the movie rental system:" << endl;
    if(systemSubList.isEmpty()){
        return;
    }
    for (int i = 0; i < systemSubList.itemCount; ++i) {
        cout << systemSubList.getNodeAt(i)->item.subID<<endl;
    }
}
template class LinkedList<Transaction>;
template class LinkedList<Subscriber>;
template class LinkedList<Movie>;
