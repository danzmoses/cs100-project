#ifndef __SLIME_PROTOTYPE__
#define __SLIME_PROTOTYPE__

#include "EnemyPrototype.h"

class SlimePrototype : public EnemyPrototype 
{
    public:
        SlimePrototype() : EnemyPrototype() {
			setLevel(1);
			setDescription("A bouncing blob of goo. "); 
			baseStats->HP = 2; 
			baseStats->maxHP = 2;
			baseStats->ATK = 1;
			baseStats->DEF = 1;
			combatStats->HP = 2;
			combatStats->maxHP = 2;
			combatStats->ATK = 1;
			combatStats->DEF = 1;
        }
        SlimePrototype(std::string name) : EnemyPrototype(name) {}
        virtual EnemyPrototype* Clone() = 0;
};

#endif //__SLIME_PROTOTYPE__
