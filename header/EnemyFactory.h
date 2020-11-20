#ifndef __ENEMY_FACTORY__
#define __ENEMY_FACTORY__

#include "EntityFactory.h"

class EnemyFactory : public EntityFactory
{
    public:
        EnemyFactory() : EntityFactory() {};
        virtual void createEntity(std::string name) { };

};

#endif // __ENEMY_FACTORY__