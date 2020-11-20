#ifndef __GREEN_SLIME_PROTOTYPE__
#define __GREEN_SLIME_PROTOTYPE__

#include "EnemyPrototype.h"

class GreenSlimePrototype : public EnemyPrototype 
{
    public:
        GreenSlimePrototype() : EnemyPrototype() {};
        GreenSlimePrototype(std::string name) : EnemyPrototype(name) {};
        virtual void Clone() { setName("Green Slime"); setHealth(10); };
};

#endif //__GREEN_SLIME_PROTOTYPE__