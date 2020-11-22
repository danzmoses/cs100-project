#ifndef __RED_SLIME_PROTOTYPE__
#define __RED_SLIME_PROTOTYPE__

#include "SlimePrototype.h"

class RedSlimePrototype : public SlimePrototype 
{
    public:
        RedSlimePrototype() : SlimePrototype() { setName("Red Slime"); setHP(getHP() + 1); setDescription(getDescription() + "It looks aggressive."); }
        RedSlimePrototype(std::string name) : SlimePrototype(name) {}
        virtual EnemyPrototype* Clone() { return this; }
};

#endif //__RED_SLIME_PROTOTYPE__