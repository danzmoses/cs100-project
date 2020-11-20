#ifndef __ENEMY_FACTORY__
#define __ENEMY_FACTORY__

#include "EntityFactory.h"
#include "prototypes/enemies/EnemyPrototype.h"
#include "prototypes/enemies/GoblinPrototype.h"
#include "prototypes/enemies/GreenSlimePrototype.h"
#include "prototypes/enemies/RedSlimePrototype.h"
#include <vector>

class EnemyFactory : public EntityFactory
{
    private:
        EnemyPrototype* enemy;
        std::vector<EnemyPrototype*> enemyPrototypes;

    public:
        EnemyFactory() : EntityFactory() 
        {
            this->enemyPrototypes.push_back(new GoblinPrototype());
            this->enemyPrototypes.push_back(new GreenSlimePrototype());
            this->enemyPrototypes.push_back(new RedSlimePrototype());
        }
        virtual Entity* createEntity(std::string name) 
        { 
            for (int i = 0; i < enemyPrototypes.size(); ++i)
            {
                if (enemyPrototypes.at(i)->getName() == name)
                {
                    enemy = enemyPrototypes.at(i);
                    enemy->Clone();
                    return enemy;
                }
            }
            std::invalid_argument ia("Invalid argument. Unable to find \"" + name + '\"' );
            throw ia;
        }; // search through dict: then set the prototype if it exists: then call clone on the prototype and return. throw ia if unable to find
};

#endif // __ENEMY_FACTORY__