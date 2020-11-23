#ifndef __STONESWORD_PROTOTYPE__
#define __STONESWORD_PROTOTYPE__

#include "SwordPrototype.h"

class StoneSwordPrototype : public SwordPrototype 
{
    public:
        StoneSwordPrototype() : SwordPrototype() { this->setName("Stone" + this->getName()); this->setCost(100); }
        StoneSwordPrototype(std::string name) : SwordPrototype(name) {}
        virtual WeaponPrototype* Clone() { return this; }
};

#endif // __STONESWORD_PROTOTYPE__