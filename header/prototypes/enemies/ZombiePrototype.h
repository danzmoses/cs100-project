#ifndef __ZOMBIE_PROTOTYPE__
#define __ZOMBIE_PROTOTYPE__

#include "EnemyPrototype.h"

class ZombiePrototype : public EnemyPrototype 
{
    public:
        ZombiePrototype() : EnemyPrototype() { setName("Zombie"); setHP(5); }
        ZombiePrototype(std::string name) : EnemyPrototype(name) {}
        virtual EnemyPrototype* Clone() { return this; }
};

#endif // __ZOMBIE_PROTOTYPE__
