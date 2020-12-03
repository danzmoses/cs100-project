#ifndef __GREEN_SLIME_PROTOTYPE__
#define __GREEN_SLIME_PROTOTYPE__

#include "SlimePrototype.h"

class GreenSlimePrototype : public SlimePrototype 
{
    public:
        GreenSlimePrototype() : SlimePrototype() { 
	        setName("Green Slime"); 
            setLevel(1);
            setDescription(getDescription() + "It looks harmless."); 
            baseStats->HP += 0;
            baseStats->maxHP += + 0;
            combatStats->HP += 0;
            combatStats->maxHP += 0;
        }
        GreenSlimePrototype(std::string name) : SlimePrototype(name) {}
        virtual EnemyPrototype* Clone() { return new GreenSlimePrototype(); }
};

#endif //__GREEN_SLIME_PROTOTYPE__

