#ifndef __GREEN_SLIME_PROTOTYPE__
#define __GREEN_SLIME_PROTOTYPE__

#include "SlimePrototype.h"

class GreenSlimePrototype : public SlimePrototype 
{
    public:
        GreenSlimePrototype() : SlimePrototype() { setName("Green Slime"); setHealth(this->getHealth() + 0); }
        GreenSlimePrototype(std::string name) : SlimePrototype(name) {}
        virtual EnemyPrototype* Clone() { return this; }
};

#endif //__GREEN_SLIME_PROTOTYPE__