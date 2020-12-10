#ifndef __SKELETON_PROTOTYPE__
#define __SKELETON_PROTOTYPE__

#include "EnemyPrototype.h"

class SkeletonPrototype : public EnemyPrototype 
{
    public:
        SkeletonPrototype() : EnemyPrototype() { 
	        setName("Skeleton"); 
            setLevel(1);
            setDescription("An undead humanoid made up of bones."); 
            setEXPMult(2);
            setGold(14);
            baseStats->HP = 5; 
            baseStats->maxHP = 5;
            baseStats->ATK = 2;
            baseStats->DEF = 2;
            combatStats->HP = 5;
            combatStats->maxHP = 5;
            combatStats->ATK = 2;
            combatStats->DEF = 2;
        }
        SkeletonPrototype(std::string name) : EnemyPrototype(name) {}
        virtual EnemyPrototype* Clone() { return new SkeletonPrototype(); }
};

#endif // __SKELETON_PROTOTYPE__
