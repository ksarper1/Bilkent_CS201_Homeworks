// Kemal Sarper Sahin


#ifndef LEAGUEMANAGEMENTSYSTEM_H
#define LEAGUEMANAGEMENTSYSTEM_H

#include "team.h"

using namespace std;

class LeagueManagementSystem {
private:
    int numTeams;
    team *teamArr;


public:
    LeagueManagementSystem();

    ~LeagueManagementSystem();

    void addTeam(const string name, const int year);

    void removeTeam(const string name);

    void addPlayer(const string teamName, const string playerName, const int jersey, const int salary);

    void removePlayer(const string teamName, const string playerName);

    void transferPlayer(const string playerName, const string departTeamName, const string arriveTeamName);

    void showAllTeams() const;

    void showTeam(const string name) const;

    void showPlayer(const string name) const;
};

#endif // LEAGUEMANAGEMENTSYSTEM_H
