#ifndef __IRONSWORD_PROTOTYPE__
#define __IRONSWORD_PROTOTYPE__

#include "SwordPrototype.h"

class IronSwordPrototype : public SwordPrototype 
{
    public:
        IronSwordPrototype() : SwordPrototype() { 
            this->setName("Iron" + this->getName()); 
            this->setCost(500); 
            baseStats->ATK = 3;
            baseStats->DEF = 0;
            baseStats->HP = 0;
            baseStats->maxHP = 0;
            combatStats->ATK = 3;
            combatStats->DEF = 0;
            combatStats->HP = 0;
            combatStats->maxHP = 0;
        }
        IronSwordPrototype(std::string name) : SwordPrototype(name) {}
        virtual WeaponPrototype* Clone() { return new IronSwordPrototype(); }
};

#endif // __IronSWORD_PROTOTYPE__
