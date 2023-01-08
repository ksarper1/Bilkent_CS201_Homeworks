// Kemal Sarper Sahin
#include <iostream>
#include <string>
#include "LeagueManagementSystem.h"
using namespace std;

LeagueManagementSystem::LeagueManagementSystem() {
    numTeams = 0;
    teamArr = NULL;
}

LeagueManagementSystem::~LeagueManagementSystem() {
    delete[] teamArr;
    teamArr = NULL;
}

void LeagueManagementSystem::addTeam(const string name, const int year) {

    for (int i = 0; i < numTeams; i++) {
        if (teamArr[i].name == name) {
            cout << "Cannot add team. Team " << name << " already exists." << endl;
            return;
        }
    }
    if (teamArr == NULL) {
        teamArr = new team[1];
        teamArr[0].initialize2(name, year);
        numTeams = 1;
    } else {
        team *tempArr = new team[numTeams + 1];
        for (int i = 0; i < numTeams; i++) {
            tempArr[i].initialize1(teamArr[i]);
        }
        tempArr[numTeams].initialize2(name, year);
        delete[] teamArr;
        teamArr = NULL;
        teamArr = tempArr;
        numTeams++;
    }
    cout << "Added Team " << name << "." << endl;
}

void LeagueManagementSystem::removeTeam(const string name) {
    bool result = false;

    for (int i = 0; i < numTeams; i++) {
        if (teamArr[i].name == name) {
            result = true;
            if (numTeams == 1) {
                delete[] teamArr;
                teamArr = NULL;
                numTeams = 0;
            } else {
                team *tempArr = new team[numTeams - 1];
                for (int j = 0; j < i; j++) {
                    tempArr[j].initialize1(teamArr[j]);
                }
                for (int j = i + 1; j < numTeams; j++) {
                    tempArr[j - 1].initialize1(teamArr[j]);
                }
                delete[] teamArr;
                teamArr = NULL;
                teamArr = tempArr;
                numTeams--;
            }
        }
    }
    if (result == false) {
        cout << "Cannot remove team. Team " << name << " does not exist." << endl;
        return;
    }
    cout << "Removed team " << name << "." << endl;
}

void LeagueManagementSystem::showAllTeams() const {
    cout << "Teams in the league management system:" << endl;
    if (numTeams == 0) {
        cout << "None" << endl;
        cout << endl;
    } else {
        for (int i = 0; i < numTeams; i++) {
            cout << "Team " << teamArr[i].name << ", " << teamArr[i].year << ", " << teamArr[i].playerNumber
                 << " players, " << teamArr[i].sumSalary() << " TL total salary." << endl;
        }
    }
}

void LeagueManagementSystem::showTeam(const string name) const {
    bool result = false;
    for (int i = 0; i < numTeams; i++) {
        if (teamArr[i].name == name) {
            result = true;
            cout << "Team " << teamArr[i].name << ", " << teamArr[i].year << ", " << teamArr[i].playerNumber
                 << " players, " << teamArr[i].sumSalary() << " TL salary." << endl;
            cout << "Players:" << endl;


            for (int j = 0; j < teamArr[i].playerNumber; j++) {
                cout << teamArr[i].playersArr[j].fullName << ", jersey " << teamArr[i].playersArr[j].jerseyNumber
                     << ", " << teamArr[i].playersArr[j].salary << " Tl salary." << endl;
            }
        }
    }
    if (!result) {
        cout << "Team " << name << " does not exist." << endl;
    }
}

void
LeagueManagementSystem::addPlayer(const string teamName, const string playerName, const int jersey, const int salary) {
    bool result = false;

    for (int i = 0; i < numTeams; i++) {
        if (teamArr[i].name == teamName) {
            result = true;
            if (teamArr[i].addPlayer(playerName, jersey, salary)) {
                cout << "Added player " << playerName << " to team " << teamName << "." << endl;
                break;
            } else break;
        }
    }
    if (!result) {
        cout << "Cannot add player. Team " << teamName << " does not exist." << endl;
    }
    return;
}

void LeagueManagementSystem::removePlayer(const string teamName, const string playerName) {
    bool result = false;

    for (int i = 0; i < numTeams; i++) {
        if (teamArr[i].name == teamName) {
            result = true;
            if (teamArr[i].removePlayer(playerName)) {
                cout << "Removed player " << playerName << " from team " << teamName << "." << endl;
                break;
            }
        }
    }
    if (!result)
        cout << "Cannot remove player. Team " << teamName << " does not exist. " << endl;

    return;
}

void LeagueManagementSystem::transferPlayer(const string playerName, const string departTeamName,
                                            const string arriveTeamName) {
    bool isDepartTeam = false;
    bool isArriveTeam = false;
    bool isPlayer = false;


    for (int i = 0; i < numTeams; i++) {
        if (teamArr[i].name == departTeamName) {
            isDepartTeam = true;

            int playerIndex = teamArr[i].findPlayerIndex(playerName);

            if (playerIndex == -1) {
                cout << "Cannot transfer player. Player " << playerName << " does not exist." << endl;
                return;
            }
            for (int j = 0; j < numTeams; j++) {
                if (teamArr[j].name == arriveTeamName) {

                    isArriveTeam = true;
                    if (teamArr[j].addPlayerForTransfer(teamArr[i].playersArr[playerIndex].fullName,
                                                        teamArr[i].playersArr[playerIndex].jerseyNumber,
                                                        teamArr[i].playersArr[playerIndex].salary)) {
                        teamArr[i].removePlayerForTransfer(playerName);
                        cout << "Transferred player " << playerName << " from " << departTeamName << " to "
                             << arriveTeamName << "." << endl;
                        break;
                    }
                }
            }
        }
    }
    if (!isDepartTeam) {
        cout << "Cannot transfer player. Team " << departTeamName << " does not exist." << endl;
        return;
    }
    if (!isArriveTeam) {
        cout << "Cannot transfer player. Team " << arriveTeamName << " does not exist." << endl;
        return;
    }

    return;
}

void LeagueManagementSystem::showPlayer(const string name) const {
    bool result = false;

    for (int i = 0; i < numTeams; i++) {
        for (int j = 0; j < teamArr[i].playerNumber; j++) {
            if (teamArr[i].playersArr[j].fullName == name) {
                result = true;
                cout << "player " << teamArr[i].playersArr[j].fullName << ", jersey "
                     << teamArr[i].playersArr[j].jerseyNumber << ", " << teamArr[i].playersArr[j].salary << " TL salary."
                     << endl;
                cout << "Plays in team " << teamArr[i].name <<  "." <<endl;
                return;
            }
        }
    }
    if (!result) {
        cout << "Player " << name << " does not exist." << endl;
        return;
    }
}
