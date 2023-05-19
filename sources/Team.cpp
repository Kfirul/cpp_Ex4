#include "Team.hpp"
#include <limits>

using namespace ariel ;

    Team::Team(Character* leader) : leader(leader),team(0) {
        add(leader);
    }
    
    Team::~Team() {
        for (Character* character : team) {
            delete character;
        }
    }

    void Team::add(Character* teammate) {
        if(team.size()<10){
            team.push_back(teammate);
            this->orderByCowboyNinja();
        }
    }

    void Team::attack(Team* enemiesTeam) {
        
        if (!leader->isAlive()) {
            this->setLeader();
        }
        if (leader!=nullptr) {
            while(enemiesTeam->stillAlive()>0){
                Character* target = selectTarget(*enemiesTeam,leader->getLocation());
                for(Character* teammate: team){
                
                if(target->isAlive()){
                    if(dynamic_cast<Cowboy*>(teammate) && teammate->isAlive()){
                        Cowboy *cowboy = dynamic_cast<Cowboy*>(teammate);
                        if(cowboy->hasboolets())
                            cowboy->shoot(target);
                        else cowboy ->reload();   
                    }
                    else if(dynamic_cast<Ninja*>(teammate) && teammate->isAlive()){
                        Ninja *ninja = dynamic_cast<Ninja*>(teammate);
                        Point NinjaLocation= ninja->getLocation();
                        double distance = NinjaLocation.distance(target->getLocation());
                        if(distance <1)
                            ninja->slash(target);
                        else ninja->move(target);    
                    }

                }

                if(enemiesTeam->stillAlive()>0)
                    target = selectTarget(*enemiesTeam,leader->getLocation());
                else break;
            }
            }
        }
        }
    
        
    int Team::stillAlive() {
        int count=0;
        for (Character* character : team) {
            if (character->isAlive()) {
                count++;
            }
        }
        return count;
    }

    void Team::print() {
        this->orderByCowboyNinja();
        string str="";
        cout << "Team Members:" << endl;
        for (const Character* teammate : team) {
            str += teammate->print();
        }
        cout<< str<<endl;
    }

    void Team::orderByCowboyNinja() {
        for (size_t i = 0; i < team.size(); i++) {
            if (dynamic_cast<Ninja*>(team[i])) {
                bool found = false;
                size_t j =i+1;
                while(j<team.size() && !found){
                    if(dynamic_cast<Cowboy*>(team[j])){
                        Character* char1 = team[i] , *char2 = team[j];
                        swap(char1,char2);
                        found = true;
                    }
                }
            }
         
        }
    }

    Character* Team::selectTarget(Team enemiesTeam, Point leaderLocation) {
    double minDistance = std::numeric_limits<double>::max();
    Character* target = nullptr;
    for (Character* enemy : enemiesTeam.team) {
        if (enemy->isAlive()) {
            double distance = leaderLocation.distance(enemy->getLocation());
            if (distance < minDistance) {
                minDistance = distance;
                target = enemy;
            }
        }
    }
    return target; 
    }


    void Team::setLeader() {
    if (!leader->isAlive()) {
        Character* newLeader = nullptr;
        double minDistance = std::numeric_limits<double>::max();
        for (Character* character : team) {
            if (leader != character && character->isAlive() && leader->getLocation().distance(character->getLocation()) < minDistance) {
                minDistance = leader->getLocation().distance(character->getLocation());
                newLeader = character;
            }
        }
        leader = newLeader;
    }
}

    vector<Character*>& Team:: getTeam(){
        return team;
    }
 
