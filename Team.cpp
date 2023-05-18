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
        if(team.size()<10)
            team.push_back(teammate);
    }

    void Team::attack(Team* enemiesTeam) {
        this.orderByCowboyNinja();
        enemiesTeam->order();
        if (!leader->isAlive()) {
            this.setLeader();
        }
        if (leader!=nullptr) {
            while(enemiesTeam->stillAlive()>0){
                Character* target = selectTarget(*enemiesTeam,leader->getLocation())
                for(Character* teammate: team){
                
                if(target->isAlive()){
                    if(dynamic_cast<Cowboy*>(teammate) && teammate->isAlive()){
                        if(teammate->hasboolets())
                            teammate->shoot(target);
                        else teammate ->reload();   
                    }
                    else if(dynamic_cast<Ninja*>(teammate) && teammate->isAlive()){
                        double distance = Ninja->getLocation().distance(target->getLocation());
                        if(distance <1)
                            teammate->slash(target);
                        else teammate->move(target);    
                    }

                }

                if(enemiesTeam->stillAlive()>0)
                    target = selectTarget(*enemiesTeam,leader->getLocation())
                else break;
            }
            }
        }
        }
    
        
    int Team::stillAlive() {
        int count=0;
        for (Character& character : team) {
            if (character.isAlive()) {
                count++;
            }
        }
        return count;
    }

    void Team::print() {
        this.orderByCowboyNinja();
        str="";
        cout << "Team Members:" << endl;
        for (const Character& teammate : team) {
            str += teammate.print();
        }
        cout<< str<<endl;
    }

    void Team::orderByCowboyNinja() {
        for (size_t i = 0; i < team.size(); i++) {
            if (dynamic_cast<Ninja*>(team[i])) {
                bool found = false;
                size_t j =i+1
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

    Character* Team:: selectTarget(Team enemiesTeam,Point leaderLocation){
        double minDistance = numeric_limits<double>::max();
            Character* target = nullptr;
            for (Character& enemy : enemiesTeam->team) {
                if (enemy.isAlive()) {
                    double distance = leaderLocation.distance(enemy.getLocation());
                    if (distance < minDistance) {
                        minDistance = distance;
                        target = &enemy;
                    }
                }   

            }
    }

    void Team::setLeader(){
        if(!this.leader->isAlive())
            Character* newLeader =nullptr;
            double minDistance = std::numeric_limits<double>::max();
            for (Character* character : team) {
                if(*this.leader!=*character && character->isAlive() && character.getLocation().Distance(character.getLocation()))
                    newLeader = character;
            }
        this.leader=newLeader;    
    }

    SmartTeam::SmartTeam(Character* leader) : Team(leader) {}

    SmartTeam::~SmartTeam() {}

    void SmartTeam::order() {
        // sort(team.begin(), team.end(), [](const Character& a, const Character& b) {
        //     return a.distance(a.getLocation()) < b.distance(b.getLocation());
        // });
    }

 
