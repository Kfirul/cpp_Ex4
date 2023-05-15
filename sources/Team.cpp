#include "Team.hpp"

namespace ariel {

    Team::Team(Character* leader) : leader(leader) {
        // team.push_back(leader);
    }
    

    Team::~Team() {
        // for (Character* character : team) {
        //     delete character;
        // }
    }

    void Team::add(Character* teammate) {
        // team.push_back(*teammate);
    }

    void Team::attack(Team* enemiesTeam) {
        // order();
        // enemiesTeam->order();

        // if (leader->isAlive()) {
        //     for (Character& teammate : team) {
        //         if (teammate.isAlive()) {
        //             Character* target = nullptr;
        //             double minDistance = numeric_limits<double>::max();
        //             for (Character& enemy : enemiesTeam->team) {
        //                 if (enemy.isAlive()) {
        //                     double distance = teammate.distance(&enemy);
        //                     if (distance < minDistance) {
        //                         minDistance = distance;
        //                         target = &enemy;
        //                     }
        //                 }
        //             }

        //             if (target) {
        //                 teammate.move(target);
        //                 teammate.attack(target);
        //             }
        //         }
        //     }
        // }
    }

    bool Team::stillAlive() {
        // for (Character& character : team) {
        //     if (character.isAlive()) {
        //         return true;
        //     }
        // }
        return false;
    }

    void Team::print() {
        // cout << "Team Leader:" << endl;
        // leader->print();
        // cout << "Team Members:" << endl;
        // for (const Character& teammate : team) {
        //     teammate.print();
        // }
    }

    void Team::order() {
        // sort(team.begin(), team.end(), [](const Character& a, const Character& b) {
        //     return a.getHealth() > b.getHealth();
        // });
    }

    Team2::Team2(Character* leader) : Team(leader) {}

    Team2::~Team2() {}

    void Team2::order() {
        // sort(team.begin(), team.end(), [](const Character& a, const Character& b) {
        //     return a.getHealth() < b.getHealth();
        // });
    }

    SmartTeam::SmartTeam(Character* leader) : Team(leader) {}

    SmartTeam::~SmartTeam() {}

    void SmartTeam::order() {
        // sort(team.begin(), team.end(), [](const Character& a, const Character& b) {
        //     return a.distance(a.getLocation()) < b.distance(b.getLocation());
        // });
    }

} 
