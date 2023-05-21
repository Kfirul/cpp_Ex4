#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <vector>

#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"


using namespace std;
namespace ariel{
    class Team{
        Character *leader;
        vector<Character*> team;
        void orderByCowboyNinja();
        Character* selectTarget(Team& enemiesTeam);
        void setLeader();
        public:
        Team(Character* leader);
        
        virtual ~Team();
        virtual void add(Character* teamate);
        void attack(Team* enemiesTeam);
        int stillAlive();
        void print();
        vector<Character*>& getTeam();
        Character*& getLeader();
        template<typename T>
        void swap(T&obj1 ,T&obj2){
            T tmp=obj1;
            obj1=obj2;
            obj2=tmp;
        }

    Team (Team&) = delete; // Copy Constructor.
    Team (Team&&) noexcept = delete; // Move Constructor.
    Team& operator = (const Team&) = delete; // Copy assignment operator.
    Team& operator = (Team&&) noexcept = delete; // Move assignment operator.  

    };
}
#endif