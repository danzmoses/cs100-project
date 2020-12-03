#ifndef __LEATHERARMOR_PROTOTYPE__
#define __LEATHERARMOR_PROTOTYPE__

#include "ArmorPrototype.h"

class LeatherArmorPrototype : public ArmorPrototype 
{
    public:
        LeatherArmorPrototype() : ArmorPrototype() { 
            this->setName("Leather Armor"); 
            this->setCost(50); 
            baseStats->ATK = 0;
            baseStats->DEF = 1;
            baseStats->HP = 0;
            baseStats->maxHP = 0;
            combatStats->ATK = 0;
            combatStats->DEF = 1;
            combatStats->HP = 0;
            combatStats->maxHP = 0;
        }
        LeatherArmorPrototype(std::string name) : ArmorPrototype(name) {}
        virtual ArmorPrototype* Clone() { return new LeatherArmorPrototype(); }
};

#endif // __LEATHERARMOR_PROTOTYPE__
