#include "Character.hpp"

using namespace ariel;

    Character::Character(string Name, Point &loc, int healthPoints)
        : name(Name), location(loc), health(healthPoints) {}

    Character::Character(Character& other)
        : name(other.getName()), location(other.getLocation()), health(other.health) {}

    bool Character::isAlive() {
        return health > 0;
    }

    double Character::distance(Character* other) {
        return location.distance(other->getLocation());
    }

    void Character::hit(int hurtPoint) {
        if (hurtPoint > 0) {
            health -= hurtPoint;
            if (health < 0) {
                health = 0;
            }
        }
    }

    string Character::getName() {
        return name;
    }

    Point Character::getLocation() {
        return location;
    }

    void Character::setLocation(Point other){
        location = Point(getLocation());
    }

    string Character::print() {
        if(!isAlive())
            return "name: ("+name  + "), Locatin: " location.print();
       return "name: "+name + ", health: "+to_string(health)  + ", Locatin: " +location.print();
    }

    Character& Character::operator=(const Character& other){
    if(this==&other) return *this;
    this->name=other.name;
    this->location=other.location;
    this->health=other.health;
    return *this;
 }


