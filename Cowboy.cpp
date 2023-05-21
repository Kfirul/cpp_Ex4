#include "Cowboy.hpp"

namespace ariel {

    Cowboy::Cowboy(string name, Point location) : Character(name, location, 110), booletsCount(6) {}

    void Cowboy::shoot(Character* enemy) {
        if(this==enemy) throw runtime_error ("No self harm");
        if(!this->isAlive() || !enemy->isAlive()) throw runtime_error ("Dead characters cannot attack and characters cannot attack a dead enemy");
        if (hasboolets() && isAlive()) {
            enemy->hit(10);
            booletsCount--;
        }
    }

    bool Cowboy::hasboolets() {
        return booletsCount > 0;
    }

    void Cowboy::reload() {
        if(!this->isAlive()) throw runtime_error("Dead cowboy can not reload");
        booletsCount = 6;
    }

    string Cowboy::print() const{
    return "C " + Character::print();
}

} 