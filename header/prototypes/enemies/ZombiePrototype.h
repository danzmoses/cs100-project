#ifndef __ZOMBIE_PROTOTYPE__
#define __ZOMBIE_PROTOTYPE__

#include "EnemyPrototype.h"

class ZombiePrototype : public EnemyPrototype 
{
    public:
        ZombiePrototype() : EnemyPrototype() { 
	    setName("Zombie");
	    baseStats->HP = 5; 
	    baseStats->maxHP = 5;
	    baseStats->ATK = 3; 
	    baseStats->DEF = 2;
	    combatStats-> HP = 5;
	    combatStats->maxHP = 5;
	    combatStats->ATK = 3;
	    combatStats->DEF = 2;
            setDescription("brains...");
        }
        ZombiePrototype(std::string name) : EnemyPrototype(name) {}
        virtual EnemyPrototype* Clone() { return this; }
};

#endif // __ZOMBIE_PROTOTYPE__
