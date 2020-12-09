#ifndef __BLUE_SLIME_PROTOTYPE__
#define __BLUE_SLIME_PROTOTYPE__

#include "SlimePrototype.h"

class BlueSlimePrototype : public SlimePrototype 
{
    public:
        BlueSlimePrototype() : SlimePrototype() { 
	        setName("Blue Slime"); 
            setLevel(1);
            setDescription(getDescription() + "It looks defensive."); 
            baseStats->HP += 0;
            baseStats->maxHP += + 0;
            combatStats->HP += 0;
            combatStats->maxHP += 0;
            baseStats->DEF += 1;
            combatStats->DEF += 1;
        }
        BlueSlimePrototype(std::string name) : SlimePrototype(name) {}
        virtual EnemyPrototype* Clone() { return new BlueSlimePrototype(); }
};

#endif //__BLUE_SLIME_PROTOTYPE__