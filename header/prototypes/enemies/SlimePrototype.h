#ifndef __SLIME_PROTOTYPE__
#define __SLIME_PROTOTYPE__

#include "EnemyPrototype.h"

class SlimePrototype : public EnemyPrototype 
{
    public:
        SlimePrototype() : EnemyPrototype() { setHP(2); }
        SlimePrototype(std::string name) : EnemyPrototype(name) {}
        virtual EnemyPrototype* Clone() = 0;
};

#endif //__SLIME_PROTOTYPE__
