#ifndef COWBOY_HPP
#define COWBOY_HPP
#include "Character.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace ariel {
    class Cowboy: public Character{
        int bullsCount;

        public:
        Cowboy(string name, Point &location);
        void shoot(Character* enemy);
        bool hasboolets();
        void reload();
        string print() override;
    
    };
}
#endif