#ifndef __RED_SLIME_PROTOTYPE__
#define __RED_SLIME_PROTOTYPE__

#include "SlimePrototype.h"

class RedSlimePrototype : public SlimePrototype 
{
    public:
        RedSlimePrototype() : SlimePrototype() { 
            setName("Red Slime");
            setLevel(1);
            setDescription(getDescription() + "It looks aggressive."); 
            baseStats->HP += 1;
            baseStats->maxHP = baseStats->HP + 1;
            combatStats->HP += 1;
            combatStats->maxHP = combatStats->HP + 1;
        }
        RedSlimePrototype(std::string name) : SlimePrototype(name) {}
        virtual EnemyPrototype* Clone() { return new RedSlimePrototype(); }
};

#endif //__RED_SLIME_PROTOTYPE__
