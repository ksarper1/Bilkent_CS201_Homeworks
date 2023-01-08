//Kemal Sarper Sahin
#include "team.h"
#include <iostream>
#include <string>

using namespace std;

team::team(string name, int year)
{
    this->name = name;
    this->year = year;
    playerNumber = 0;
    playersArr = NULL;
}

team& team::operator= (const team& other){
    if(this == &other){
        return *this;
    }
    this->name = other.name;
    this->year = other.year;
    this->playerNumber = other.playerNumber;

    if(playersArr != NULL) {
        delete[] playersArr;
        playersArr = NULL;
    }

    playersArr = new player[playerNumber];

    for(int i=0;i<playerNumber;i++)
        playersArr[i].initialize1(other.playersArr[i]);
    return *this;
}

team::team(){
    name = "";
    year = 0;
    playerNumber = 0;
    playersArr = NULL;
}

team::team(const team &other){
    this->name = other.name;
    this->year = other.year;
    this->playerNumber = other.playerNumber;

    if(playersArr != NULL) {
        delete[] playersArr;
        playersArr = NULL;
    }

    playersArr = new player[playerNumber];

    for(int i=0;i<playerNumber;i++)
        playersArr[i].initialize1(other.playersArr[i]);
}

team::~team()
{
    if(playersArr != NULL) {
        delete  [] playersArr;
    }
    playersArr = NULL;
    playerNumber = 0;
    year = 0;
    name = "";
}

void team::initialize1(const team &other){
    this->name = other.name;
    this->year = other.year;
    this->playerNumber = other.playerNumber;

    if(playersArr != NULL) {
        delete[] playersArr;
        playersArr = NULL;
    }

    playersArr = new player[playerNumber];

    for(int i=0;i<playerNumber;i++)
        playersArr[i].initialize1(other.playersArr[i]);
}

int team::findPlayerIndex(string playerName){
    if(playerNumber!=0){
        for(int i=0; i<playerNumber; i++)
            if(playersArr[i].fullName == playerName){
                return i;
            }
        }
    }
    return -1;
}

void team::initialize2(const string name, const int year){
    this->name = name;
    this->year = year;
    playerNumber = 0;
    if(playersArr != NULL){
        delete [] playersArr;
        playersArr = NULL;
    }
    playersArr = new player[playerNumber];

}

bool team::addPlayer(const string &playerName,const int &jerseyNumber,const int &salary ){

    for(int i=0;i<playerNumber;i++){
        if(playersArr[i].jerseyNumber == jerseyNumber){
            cout<< "Cannot add player.Jersey number "<< jerseyNumber <<" already exists in team"<< name <<"."<<endl;
            return false;
        }
        if(playersArr[i].fullName == playerName){
            cout<< "A player with this name already exists." <<endl;
            return false;
        }
    }
    if(playersArr == NULL){
        playersArr = new player[1];
        playersArr[0].initialize2(this->name,playerName,jerseyNumber,salary);
    }
    else{
        player* tempArr = new player[playerNumber+1];
        for(int i=0;i<playerNumber;i++){
            tempArr[i].initialize1(playersArr[i]);
        }
        tempArr[playerNumber].initialize2(this->name,playerName,jerseyNumber,salary);
        delete [] playersArr;
        playersArr = NULL;
        playersArr = tempArr;
    }

    playerNumber++;
    return true;
}

bool team::removePlayer(const string playerName){
    int result = findPlayerIndex(playerName);
    if(result != -1){
            if(playerNumber == 1){
                delete [] playersArr;
                playersArr = NULL;
                playerNumber = 0;
            }
            else{
                player * tempArr = new player[playerNumber - 1];

                for(int i=0; i< result;i++){
                    tempArr[i].initialize1(playersArr[i]);
                }
                for(int i=result ; i< playerNumber-1 ; i++){
                    tempArr[i].initialize1(playersArr[i+1]);
                }
                playerNumber--;
                delete [] playersArr;
                playersArr = NULL;
                playersArr = tempArr;

                }
            return true;
    }
    else {
        cout<<"cannot remove player, player "<<playerName<< " does not exist."<<endl;
        return false;
    }

}

int team::sumSalary(){
 int sum = 0;
 for(int i=0;i<playerNumber;i++){
    sum+= playersArr[i].salary;
    }
    return sum;
}

bool team::removePlayerForTransfer(const string playerName){
    int result = findPlayerIndex(playerName);
    if(result != -1){
        if(playerNumber == 1){
            delete [] playersArr;
            playersArr = NULL;
            playerNumber = 0;
        }
        else{
            player * tempArr = new player[playerNumber - 1];

            for(int i=0; i< result;i++){
                tempArr[i].initialize1(playersArr[i]);
            }
            for(int i=result ; i< playerNumber-1 ; i++){
                tempArr[i].initialize1(playersArr[i+1]);
            }
            playerNumber--;
            delete [] playersArr;
            playersArr = NULL;
            playersArr = tempArr;

        }
        return true;
    }
    else {
        cout<<"cannot transfer player, player "<<playerName<< " does not exist."<<endl;
        return false;
    }
}

bool team::addPlayerForTransfer(const string playerName,const int jerseyNumber,const int salary ){

    for(int i=0;i<playerNumber;i++){
        if(playersArr[i].jerseyNumber == jerseyNumber){
            cout<< "Cannot transfer player.Jersey number "<< jerseyNumber <<" already exists in team "<< name << "." <<endl;
            return false;
        }
        if(playersArr[i].fullName == playerName){
            cout<< "A player with this name already exists." <<endl;
            return false;
        }
    }
    if(playersArr == NULL){
        playersArr = new player[1];
        playersArr[0].initialize2(this->name,playerName,jerseyNumber,salary);
    }
    else{
        player* tempArr = new player[playerNumber+1];
        for(int i=0;i<playerNumber;i++){
            tempArr[i].initialize1(playersArr[i]);
        }
        tempArr[playerNumber].initialize2(this->name,playerName, jerseyNumber,salary);
        delete [] playersArr;
        playersArr = NULL;
        playersArr = tempArr;
    }
    playerNumber++;
    return true;
}