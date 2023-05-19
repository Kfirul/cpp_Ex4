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
        Character* selectTarget(Team enemiesTeam,Point leaderLocation);
        void setLeader();
        public:
        Team(Character* leader);
        
        ~Team();
        virtual void add(Character* teamate);
        void attack(Team* enemiesTeam);
        int stillAlive();
        void print();
        vector<Character*>& getTeam();

        template<typename T>
        void swap(T&a ,T&b){
            T tmp=a;
            a=b;
            b=tmp;
        }

    };
}
#endif