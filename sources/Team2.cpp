#include "Team2.hpp"

namespace ariel {

    Team2::Team2(Character *leader) : Team(leader) {}

    void Team2::add(Character * teammate) {
        if(teammate->play())
        throw runtime_error("The fighter already play at other team");
        if(!teammate->isAlive()) throw invalid_argument ("Dead man can't play");
        //if(this->getLeader()==nullptr) throw invalid_argument ("Leader can't be null");

        if(this->getTeam().size()<10){
            this->getTeam().push_back(teammate);
        }
        else throw runtime_error("A group can be up to 10 fighters");
    }
}