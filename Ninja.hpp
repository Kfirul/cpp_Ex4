#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace ariel {
    class Ninja: public Character{
        int speed;

        public:
        Ninja(string&& name,Point location, int healthPoints, int speed);
        ~Ninja() override;
        void move(Character* enemy);
        void slash(Character* enemy);
        int getSpeed();
        string print() override;
    };

}
#endif