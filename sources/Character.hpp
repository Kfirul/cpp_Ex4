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
        void setLocation(const Point &other);
        virtual string print() const;
        bool play()const;
        void setPlay(bool playNow);


        Character (Character&); // Copy Constructor.
        Character(Character&& ) noexcept; // Move Constructor.
        Character& operator = (const Character&); // Copy assignment operator.
        Character& operator = (Character&&) noexcept; // Move assignment operato
    };
}
#endif