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
        Ninja(string&& name, int healthPoints, Point location, int speed);
        void move(Character* enemy);
        void slash(Character* enemy);
        int getSpeed();
    };

    class OldNinja:public Ninja{
        public:
        OldNinja(string&& name , Point location);
    };
       class YoungNinja:public Ninja{
        public:
        YoungNinja(string&& name , Point location);
    };
       class TrainedNinja:public Ninja{
        public:
        TrainedNinja(string&& name , Point location);
    };
}
#endif