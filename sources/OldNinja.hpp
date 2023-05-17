#ifndef OLDNINJA_H
#define OLDNINJA_H
#include "Ninja.hpp"
#include "Character.hpp"

namespace ariel{
class OldNinja:public Ninja{
        public:
        OldNinja (string name, Point location) ;
            // Ninja(name,location,150, 8) {}
    };
}

#endif