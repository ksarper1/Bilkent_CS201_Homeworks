// Kemal Sarper Sahin
#include "player.h"
#include <string>
#include <iostream>

using namespace std;

player::player(const string teamName, const string fullName, const int jerseyNumber, const int salary) {
    this->teamName = teamName;
    this->fullName = fullName;
    this->jerseyNumber = jerseyNumber;
    this->salary = salary;

}

player::player() {
    this->teamName = "";
    this->fullName = "";
    this->jerseyNumber = 0;
    this->salary = 0;
}

void player::initialize1(const player &other) {
    this->teamName = other.teamName;
    this->fullName = other.fullName;
    jerseyNumber = other.jerseyNumber;
    salary = other.salary;
}

void player::initialize2(const string teamName, const string fullName, const int jerseyNumber, const int salary) {
    this->teamName = teamName;
    this->fullName = fullName;
    this->jerseyNumber = jerseyNumber;
    this->salary = salary;
}
