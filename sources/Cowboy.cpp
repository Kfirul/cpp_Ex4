#include "Cowboy.hpp"

namespace ariel {

    Cowboy::Cowboy(string name, Point &location) : Character(name, location, 110), bullsCount(6) {}

    void Cowboy::shoot(Character* enemy) {
        if (hasboolets() && isAlive()) {
            enemy->hit(10);
            bullsCount--;
        }
        else {
            
        }
    }

    bool Cowboy::hasboolets() {
        return bullsCount > 0;
    }

    void Cowboy::reload() {
        bullsCount = 6;
    }

    string Cowboy::print() {
    return "";
}

} 