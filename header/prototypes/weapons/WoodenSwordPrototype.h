#ifndef __WOODENSWORD_PROTOTYPE__
#define __WOODENSWORD_PROTOTYPE__

#include "SwordPrototype.h"

class WoodenSwordPrototype : public SwordPrototype 
{
    public:
        WoodenSwordPrototype() : SwordPrototype() { this->setName("Wooden" + this->getName()); this->setCost(25); }
        WoodenSwordPrototype(std::string name) : SwordPrototype(name) {}
        virtual WeaponPrototype* Clone() { return new WoodenSwordPrototype(); }
};

#endif // __WOODENSWORD_PROTOTYPE__
