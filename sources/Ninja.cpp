#include "Ninja.hpp"

namespace ariel {

    Ninja::Ninja(string& name, Point location,int healthPoints, int speed)
        : Character(std::move(name), location, healthPoints), speed(speed) {}

    void Ninja::move(Character* enemy) {
        setLocation(moveTowards(this->getLocation(), enemy->getLocation(), speed));
    }

    void Ninja::slash(Character* enemy) {
            enemy->hit(40);
    }

    int Ninja::getSpeed(){
        return this->speed;
    }

    string Ninja::print(){
        "N" + Character::print();
    }

} 
