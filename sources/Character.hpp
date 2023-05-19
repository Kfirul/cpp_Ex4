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
        bool play_now;

        public:
        Character(string Name, Point &location, int healthPoints);
        Character(const Character& other);
        virtual ~Character() = default;
        bool isAlive() const;
        double distance(Character* other);
        void hit(int hurtPoint);
        string getName() const;
        Point getLocation() const;
        void setLocation(Point other);
        virtual string print() const;
        Character& operator=(const Character& other);
        bool play();
        void setPlay(bool playNow);
    };
}
#endif