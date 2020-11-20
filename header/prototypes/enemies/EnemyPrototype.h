#ifndef __ENEMY_PROTOTYPE__
#define __ENEMY_PROTOTYPE__

#include "../../Entity.h"

class EnemyPrototype : public Entity 
{
    public:
        EnemyPrototype() : Entity() {};
        EnemyPrototype(std::string name) : Entity(name) {};
        virtual EnemyPrototype* Clone() = 0;
};

#endif // __ENEMY_PROTOTYPE__