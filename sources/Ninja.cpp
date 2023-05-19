#include "Ninja.hpp"

namespace ariel {

    Ninja::Ninja(string name, Point location,int health,int speed) : Character(name, location, health),speed(speed){}

    void Ninja::move(Character* enemy) {
        setLocation(Point::moveTowards(this->getLocation(), enemy->getLocation(), speed));
    }

    void Ninja::slash(Character* enemy) {
            enemy->hit(40);
    }

    int Ninja::getSpeed(){
        return this->speed;
    }

    string Ninja::print() const{
        return "N" + Character::print();
    }

} 
