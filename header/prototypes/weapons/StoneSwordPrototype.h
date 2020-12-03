#ifndef __STONESWORD_PROTOTYPE__
#define __STONESWORD_PROTOTYPE__

#include "SwordPrototype.h"

class StoneSwordPrototype : public SwordPrototype 
{
    public:
        StoneSwordPrototype() : SwordPrototype() { 
            this->setName("Stone" + this->getName()); 
            this->setCost(100); 
            baseStats->ATK = 2;
            baseStats->DEF = 0;
            baseStats->HP = 0;
            baseStats->maxHP = 0;
            combatStats->ATK = 2;
            combatStats->DEF = 0;
            combatStats->HP = 0;
            combatStats->maxHP = 0;
        }
        StoneSwordPrototype(std::string name) : SwordPrototype(name) {}
        virtual WeaponPrototype* Clone() { return new StoneSwordPrototype(); }
};

#endif // __STONESWORD_PROTOTYPE__
