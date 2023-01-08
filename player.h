// Kemal Sarper Sahin

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class player {
public:
    player();

    string teamName;
    string fullName;
    int jerseyNumber;
    int salary;

    player(const string teamName, const string fullName, const int jerseyNumber, const int salary);

    void initialize1(const player &other);

    void initialize2(const string teamName, const string fullName, const int jerseyNumber, const int salary);
};

#endif // PLAYER_H

