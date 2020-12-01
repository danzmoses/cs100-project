#ifndef __GREEN_SLIME_PROTOTYPE__
#define __GREEN_SLIME_PROTOTYPE__

#include "SlimePrototype.h"

class GreenSlimePrototype : public SlimePrototype 
{
    public:
        GreenSlimePrototype() : SlimePrototype() { 
	    setName("Green Slime"); 
            HP += 0;
	    maxHP = HP + 0;
            setDescription(getDescription() + "It looks harmless."); 
        }
        GreenSlimePrototype(std::string name) : SlimePrototype(name) {}
        virtual EnemyPrototype* Clone() { return this; }
};

#endif //__GREEN_SLIME_PROTOTYPE__

