#include "Ninja.hpp"

namespace ariel {

    Ninja::Ninja(string&& name, int healthPoints, Point location, int speed)
        : Character(std::move(name), location, healthPoints), speed(speed) {}

    void Ninja::move(Character* enemy) {
        // Point enemyLocation = enemy->getLocation();
        // Point currentLocation = getLocation();
        // double distance = currentLocation.distance(enemyLocation);
        // setLocation(moveTowards(currentLocation, enemyLocation, distance));
    }

    void Ninja::slash(Character* enemy) {
        enemy->hit(40);
    }

    int Ninja::getSpeed(){
        return this->speed;
    }

    OldNinja::OldNinja(string&& name, Point location)
        : Ninja(std::move(name), 150, location, 8) {}

    YoungNinja::YoungNinja(string&& name, Point location)
        : Ninja(std::move(name), 100, location, 14) {}

    TrainedNinja::TrainedNinja(string&& name, Point location)
        : Ninja(std::move(name), 120, location, 12) {}

} 
