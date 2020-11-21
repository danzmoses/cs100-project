#ifndef __GOBLIN_PROTOTYPE__
#define __GOBLIN_PROTOTYPE__

#include "EnemyPrototype.h"

class GoblinPrototype : public EnemyPrototype 
{
    public:
        GoblinPrototype() : EnemyPrototype() { setName("Goblin"); setHP(5); }
        GoblinPrototype(std::string name) : EnemyPrototype(name) {}
        virtual EnemyPrototype* Clone() { return this; }
};

#endif // __GOBLIN_PROTOTYPE__