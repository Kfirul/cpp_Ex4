#include "Character.hpp"

using namespace ariel;

    Character::Character(string Name, Point &loc, int healthPoints)
        : name(Name), location(loc), health(healthPoints),play_now(false) {}

    Character::Character(const Character& other)
        : name(other.getName()), location(other.getLocation()), health(other.health) {}

    bool Character::isAlive() const{
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

    string Character::getName() const {
        return name;
    }

    Point Character::getLocation() const{
        return location;
    }

    void Character::setLocation(Point other){
        location = Point(getLocation());
    }

    string Character::print() const{
        if(!isAlive())
            return "name: ("+name  + "), Locatin: " +location.print();
       return "name: "+name + ", health: "+to_string(health)  + ", Locatin: " +location.print();
    }

    bool Character::play() const {
        return play_now;
    }

    void Character::setPlay(bool playNow) {
        play_now = playNow;
    }



    Character& Character::operator=(const Character& other){
    if(this==&other) return *this;
    this->name=other.name;
    this->location=other.location;
    this->health=other.health;
    return *this;
 }


