#ifndef __GOBLIN_PROTOTYPE_H__
#define __GOBLIN_PROTOTYPE_H__

#include "EnemyPrototype.h"

class GoblinPrototype : public EnemyPrototype 
{
    public:
        GoblinPrototype() : EnemyPrototype() { 
			setName("Goblin");
			setLevel(1);
			setDescription("Adventurous, greedy, and loot-heavy!");
			setEXPMult(1);
			setGold(11);
			baseStats->HP = 4;
			baseStats->maxHP = 4;
			baseStats->ATK = 3;
			baseStats->DEF = 1;
			combatStats->HP = 4;
			combatStats->maxHP = 4;
			combatStats->ATK = 3;
			combatStats->DEF = 1;
        }
        GoblinPrototype(std::string name) : EnemyPrototype(name) {}
        virtual EnemyPrototype* Clone() { return new GoblinPrototype(); }
};

#endif // __GOBLIN_PROTOTYPE_H__
