#ifndef __ENEMY_FACTORY__
#define __ENEMY_FACTORY__

#include "EntityFactory.h"
#include "prototypes/enemies/EnemyPrototype.h"
#include "prototypes/enemies/GoblinPrototype.h"

class EnemyFactory : public EntityFactory
{
    private:
        EnemyPrototype* enemy;
    public:
        EnemyFactory() : EntityFactory() {};
        virtual Entity* createEntity(std::string name) 
        { 
            this->enemy = new GoblinPrototype(); 
            enemy->Clone();
            return enemy;
        }; // search through dict: then set the prototype if it exists: then call clone on the prototype

};

#endif // __ENEMY_FACTORY__