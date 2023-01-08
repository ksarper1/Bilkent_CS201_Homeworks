// Kemal Sarper Sahin
#ifndef TEAM_H
#define TEAM_H
#include <string>
#include "player.h"

class team
{
    public:
        string name;
        int year;
        int playerNumber;

        player* playersArr=NULL;

        team();
        team(const team &other);
        team(string name, int year);
        ~team();

        team& operator=(const team &other);

        int findPlayerIndex(string playerName);

        bool addPlayer(const string &playerName,const int &jerseyNumber,const int &salary);
        bool removePlayer(const string playerName);

        bool removePlayerForTransfer(const string playerName);
        bool addPlayerForTransfer(const string playerName,const int jerseyNumber,const int salary);

        void initialize1(const team &other);
        void initialize2(const string name, const int year);

        int sumSalary();
};

#endif // TEAM_H
