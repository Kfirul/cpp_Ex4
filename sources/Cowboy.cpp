#include "Cowboy.hpp"

namespace ariel {

    Cowboy::Cowboy(string name, Point location) : Character(name, location, 110), booletsCount(6) {}

    void Cowboy::shoot(Character* enemy) {
        if (hasboolets() && isAlive()) {
            enemy->hit(10);
            booletsCount--;
        }
    }

    bool Cowboy::hasboolets() {
        return booletsCount > 0;
    }

    void Cowboy::reload() {
        booletsCount = 6;
    }

    string Cowboy::print() const{
    return "C" + Character::print();
}

} 