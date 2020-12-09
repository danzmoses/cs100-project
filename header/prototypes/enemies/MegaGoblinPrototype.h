#ifndef __MEGAGOBLIN_PROTOTYPE__
#define __MEGAGOBLIN_PROTOTYPE__

#include "EnemyPrototype.h"

class MegaGoblinPrototype : public EnemyPrototype 
{
    public:
        MegaGoblinPrototype() : EnemyPrototype() { 
	        setName("Mega Goblin"); 
            setLevel(1);
            setDescription("Double your height, double your loot."); 
            setEXPMult(3);
            baseStats->HP = 15; 
            baseStats->maxHP = 15;
            baseStats->ATK = 2;
            baseStats->DEF = 2;
            combatStats->HP = 15;
            combatStats->maxHP = 15;
            combatStats->ATK = 2;
            combatStats->DEF = 2;
        }
        MegaGoblinPrototype(std::string name) : EnemyPrototype(name) {}
        virtual EnemyPrototype* Clone() { return new MegaGoblinPrototype(); }
};

#endif // __MEGAGOBLIN_PROTOTYPE__
