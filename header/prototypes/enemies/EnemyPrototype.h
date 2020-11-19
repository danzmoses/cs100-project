#ifndef __ENEMY_PROTOTYPE__
#define __ENEMY_PROTOTYPE__

#include "../Entity.h"

class EnemyPrototype : public Entity 
{
    public:
        EnemyPrototype();
        virtual void Clone() = 0;
};

#endif