#ifndef __RED_SLIME_PROTOTYPE__
#define __RED_SLIME_PROTOTYPE__

#include "EnemyPrototype.h"

class RedSlimePrototype : public EnemyPrototype 
{
    public:
        RedSlimePrototype() : EnemyPrototype() {};
        RedSlimePrototype(std::string name) : EnemyPrototype(name) {};
        virtual void Clone() { setName("Red Slime"); setHealth(10); };
};

#endif //__RED_SLIME_PROTOTYPE__