#ifndef __SWORD_PROTOTYPE__
#define __SWORD_PROTOTYPE__

#include "WeaponPrototype.h"

class SwordPrototype : public WeaponPrototype 
{
    public:
        SwordPrototype() : WeaponPrototype() { this->setName(" Sword"); }
        SwordPrototype(std::string name) : WeaponPrototype(name) {}
        virtual WeaponPrototype* Clone() { return this; }
};

#endif // __SWORD_PROTOTYPE__