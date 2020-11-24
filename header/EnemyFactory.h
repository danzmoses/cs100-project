#ifndef __ENEMY_FACTORY_H__
#define __ENEMY_FACTORY_H__

#include "prototypes/enemies/EnemyPrototype.h"
#include "prototypes/enemies/GoblinPrototype.h"
#include "prototypes/enemies/GreenSlimePrototype.h"
#include "prototypes/enemies/RedSlimePrototype.h"
#include "prototypes/enemies/SkeletonPrototype.h"
#include "prototypes/enemies/ZombiePrototype.h"
#include <vector>

class EnemyFactory{
	private:
		std::vector <EnemyPrototype*> enemyPrototypes;
	public:
		EnemyFactory(){
			this->enemyPrototypes.push_back(new GoblinPrototype());
			this->enemyPrototypes.push_back(new GreenSlimePrototype());
			this->enemyPrototypes.push_back(new RedSlimePrototype());
			this->enemyPrototypes.push_back(new SkeletonPrototype());
			this->enemyPrototypes.push_back(new ZombiePrototype());
        	}
 
		virtual EnemyPrototype* createEnemy(std::string name){
			for(int i = 0; i < enemyPrototypes.size(); ++i){
				if(enemyPrototypes.at(i)->getName() == name){
					return enemyPrototypes.at(i)->Clone();
				}
			}
			std::invalid_argument ia("Invalid argument. Unable to find \"" + name + '\"');
			throw ia;
		}  
		// search through dict: then set the prototype if it exists: then call clone on the prototype and return. throw ia if unable to find
		
};

#endif //__ENEMY_FACTORY_H__

