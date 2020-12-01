#ifndef __GOBLIN_PROTOTYPE_H__
#define __GOBLIN_PROTOTYPE_H__

#include "EnemyPrototype.h"

class GoblinPrototype : public EnemyPrototype 
{
    public:
        GoblinPrototype() : EnemyPrototype() { 
	    setName("Goblin"); 
	    baseStats->HP = 4;
	    baseStats->maxHP = 4;
	    baseStats->ATK = 3;
	    baseStats->DEF = 1;
	    combatStats->HP = 4;
	    combatStats->maxHP = 4;
	    combatStats->ATK = 3;
	    combatStats->DEF = 1;
            setDescription("Adventurous, greedy, and loot-heavy! Goblins tend to have a higher chance to drop items."); 
        }
        GoblinPrototype(std::string name) : EnemyPrototype(name) {}
        virtual EnemyPrototype* Clone() { return this; }
};

#endif // __GOBLIN_PROTOTYPE_H__
