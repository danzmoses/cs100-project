#ifndef __ZOMBIE_PROTOTYPE__
#define __ZOMBIE_PROTOTYPE__

#include "EnemyPrototype.h"

class ZombiePrototype : public EnemyPrototype 
{
    public:
        ZombiePrototype() : EnemyPrototype() { 
			setName("Zombie");
			setLevel(1);
			setDescription("brains...");
			setEXPMult(2);
			setGold(20);
			baseStats->HP = 5; 
			baseStats->maxHP = 5;
			baseStats->ATK = 3; 
			baseStats->DEF = 2;
			combatStats-> HP = 5;
			combatStats->maxHP = 5;
			combatStats->ATK = 3;
			combatStats->DEF = 2;
        }
        ZombiePrototype(std::string name) : EnemyPrototype(name) {}
        virtual EnemyPrototype* Clone() { return new ZombiePrototype(); }
};

#endif // __ZOMBIE_PROTOTYPE__
