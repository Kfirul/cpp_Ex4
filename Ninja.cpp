#include "Ninja.hpp"

namespace ariel {

    Ninja::Ninja(string name, Point location,int health,int speed) : Character(name, location, health),speed(speed){}

    void Ninja::move(Character* enemy) {
        setLocation(Point::moveTowards(this->getLocation(), enemy->getLocation(), speed));
    }

    void Ninja::slash(Character* enemy) {
        if(!this->isAlive()|| !enemy->isAlive()) throw runtime_error ("Dead characters cannot attack and characters cannot attack a dead enemy");
        if(this==enemy) throw runtime_error ("No self harm");
        double distance = this->getLocation().distance(enemy->getLocation());
        if (distance < 1) 
            enemy->hit(40);
    }

    int Ninja::getSpeed(){
        return this->speed;
    }

    string Ninja::print() const{
        return "N " + Character::print();
    }

} 
