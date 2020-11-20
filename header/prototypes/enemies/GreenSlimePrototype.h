#ifndef __GREEN_SLIME_PROTOTYPE__
#define __GREEN_SLIME_PROTOTYPE__

#include "EnemyPrototype.h"

class GreenSlimePrototype : public EnemyPrototype 
{
    public:
        GreenSlimePrototype() : EnemyPrototype() { setName("Green Slime"); setHealth(2); }
        GreenSlimePrototype(std::string name) : EnemyPrototype(name) {}
        virtual EnemyPrototype* Clone() { return this; }
};

#endif //__GREEN_SLIME_PROTOTYPE__