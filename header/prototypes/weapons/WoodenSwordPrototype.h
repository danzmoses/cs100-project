#ifndef __WOODENSWORD_PROTOTYPE__
#define __WOODENSWORD_PROTOTYPE__

#include "SwordPrototype.h"

class WoodenSwordPrototype : public SwordPrototype 
{
    public:
        WoodenSwordPrototype() : SwordPrototype() { 
            this->setName("Wooden" + this->getName()); 
            this->setCost(25); 
            baseStats->ATK = 1;
            baseStats->DEF = 0;
            baseStats->HP = 0;
            baseStats->maxHP = 0;
            combatStats->ATK = 1;
            combatStats->DEF = 0;
            combatStats->HP = 0;
            combatStats->maxHP = 0;
        }
        WoodenSwordPrototype(std::string name) : SwordPrototype(name) {}
        virtual WeaponPrototype* Clone() { return new WoodenSwordPrototype(); }
};

#endif // __WOODENSWORD_PROTOTYPE__
