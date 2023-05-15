#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include "Point.hpp"
using namespace std;
namespace ariel{
    class Character{
        Point location;
        int health;
        string name;

        public:
        Character(string Name, Point &location, int healthPoints);
        Character(Character& other);
        bool isAlive();
        double distance(Character* other);
        void hit(int hurtPoint);
        string getName();
        Point getLocation();
        virtual string print();
        Character& operator=(const Character& other);
    };
}
#endif