#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <vector>

#include "Cowboy.hpp"
#include "Ninja.hpp"

using namespace std;
namespace ariel{
    class Team{
        Character *leader;
        vector<Character*> team;
        void order();
        public:
        Team(Character* leader);
        
        ~Team();
        void add(Character* teamate);
        void attack(Team* enemiesTeam);
        bool stillAlive();
        void print();

    };
    class Team2:public Team{
        void order();
        public:
         Team2(Character *leader);
        ~Team2();
    };
       class SmartTeam:public Team{
        void order();
        public:
        SmartTeam(Character* leader);
        ~SmartTeam();
    };
}
#endif