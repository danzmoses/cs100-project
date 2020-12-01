#ifndef __SLIME_PROTOTYPE__
#define __SLIME_PROTOTYPE__

#include "EnemyPrototype.h"

class SlimePrototype : public EnemyPrototype 
{
    public:
        SlimePrototype() : EnemyPrototype() { 
	    HP = 2; 
	    maxHP = 2;
	    ATK = 1;
	    DEF = 1;
            setDescription("A bouncing blob of goo. "); 
        }
        SlimePrototype(std::string name) : EnemyPrototype(name) {}
        virtual EnemyPrototype* Clone() = 0;
};

#endif //__SLIME_PROTOTYPE__
