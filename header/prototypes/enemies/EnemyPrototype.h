#ifndef __ENEMY_PROTOTYPE__
#define __ENEMY_PROTOTYPE__

#include "../../Enemy.h"

class EnemyPrototype : public Enemy
{
    public:
        EnemyPrototype() : Enemy() {}
        EnemyPrototype(std::string name) : Enemy(name) {}
        virtual EnemyPrototype* Clone() = 0;
};

#endif // __ENEMY_PROTOTYPE__