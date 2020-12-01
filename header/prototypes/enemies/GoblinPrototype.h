#ifndef __GOBLIN_PROTOTYPE_H__
#define __GOBLIN_PROTOTYPE_H__

#include "EnemyPrototype.h"

class GoblinPrototype : public EnemyPrototype 
{
    public:
        GoblinPrototype() : EnemyPrototype() { 
	    setName("Goblin"); 
	    HP = 4;
	    maxHP = 4;
	    ATK = 3;
	    DEF = 1;
            setDescription("Adventurous, greedy, and loot-heavy! Goblins tend to have a higher chance to drop items."); 
        }
        GoblinPrototype(std::string name) : EnemyPrototype(name) {}
        virtual EnemyPrototype* Clone() { return this; }
};

#endif // __GOBLIN_PROTOTYPE_H__
