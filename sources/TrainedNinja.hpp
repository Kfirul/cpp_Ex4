#ifndef TraindNinja_H
#define TraindNinja_H
#include "Ninja.hpp"
#include "Character.hpp"

namespace ariel{
class TrainedNinja:public Ninja{
        public:
        TrainedNinja (string name, Point location) ;
    };
}

#endif