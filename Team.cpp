#include "Team.hpp"
#include <limits>

using namespace ariel;

Team::Team(Character* leader) : leader(leader) {
    add(leader);
}

Team::~Team() {
    for (Character* character : team) {
        delete character;
    }
}

void Team::add(Character* teammate) {
    if (teammate->play()) {
        throw std::runtime_error("The fighter is already playing in another team");
    }
    
    if (!teammate->isAlive()) {
        throw std::invalid_argument("A dead character cannot be added to a team");
    }

    if (leader == nullptr) {
        throw std::invalid_argument("The leader cannot be null");
    }

    if (team.size() >= 10) {
        throw std::runtime_error("A team can have up to 10 fighters");
    }

    teammate->setPlay(true);
    team.push_back(teammate);
    orderByCowboyNinja();
}

void Team::attack(Team* enemyTeam) {
    if (enemyTeam == nullptr) {
        throw std::invalid_argument("Enemy team cannot be null");
    }

    if (enemyTeam->stillAlive() == 0) {
        throw std::runtime_error("Attacking a dead team should throw an exception");
    }

    setLeader();
    Character* target = selectTarget(*enemyTeam);

    for (Character* attacker : this->getTeam()) {
        if (attacker->isAlive() && target->isAlive()) {
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker)) {
                if (cowboy->hasboolets()) 
                    cowboy->shoot(target);
                
                else cowboy->reload();
                
            } else if (Ninja* ninja = dynamic_cast<Ninja*>(attacker)) {
                if (ninja->distance(target) < 1) 
                    ninja->slash(target);
                
                else ninja->move(target);
                
            }
        }

        if (this->stillAlive() == 0 || enemyTeam->stillAlive() == 0) {
            return;
        }

        if (!target->isAlive()) {
            target = selectTarget(*enemyTeam);
        }
    }
}


int Team::stillAlive() {
    int count = 0;
    for (Character* character : team) {
        if (character->isAlive()) {
            count++;
        }
    }
    return count;
}

void Team::print() {
    orderByCowboyNinja();
    std::cout << "Team Members:" << std::endl;
    for (const Character* teammate : team) {
        std::cout << teammate->print() << std::endl;
    }
}

void Team::orderByCowboyNinja() {
    for (size_t i = 0; i < team.size(); ++i) {
        if (dynamic_cast<Ninja*>(team[i])) {
            for (size_t j = i + 1; j < team.size(); ++j) {
                if (dynamic_cast<Cowboy*>(team[j])) {
                    swap(team[i], team[j]);
                    break;
                }
            }
        }
    }
}

Character* Team::selectTarget(Team& enemiesTeam) {
    double minDistance = std::numeric_limits<double>::max();
    Character* target = nullptr;

    for (Character* enemy : enemiesTeam.team) {
        if (enemy->isAlive()) {
            double distance = leader->getLocation().distance(enemy->getLocation());
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
            if (character != leader && character->isAlive()) {
                double distance = leader->getLocation().distance(character->getLocation());
                if (distance < minDistance) {
                    minDistance = distance;
                    newLeader = character;
                }
            }
        }

        leader = newLeader;
    }
}

std::vector<Character*>& Team::getTeam() {
    return team;
}

Character*& Team::getLeader() {
    return leader;
}

