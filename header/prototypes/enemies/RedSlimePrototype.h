#ifndef __RED_SLIME_PROTOTYPE__
#define __RED_SLIME_PROTOTYPE__

#include "EnemyPrototype.h"

class RedSlimePrototype : public EnemyPrototype 
{
    public:
        RedSlimePrototype() : EnemyPrototype() { setName("Red Slime"); setHealth(5); }
        RedSlimePrototype(std::string name) : EnemyPrototype(name) {}
        virtual EnemyPrototype* Clone() { return this; }
};

#endif //__RED_SLIME_PROTOTYPE__