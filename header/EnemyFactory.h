#ifndef __ENEMY_FACTORY_H__
#define __ENEMY_FACTORY_H__
#include "EntityFactory.h"

class EnemyFactory : public EntityFactory{
	private:
		EnemyPrototype* enemy; 
	public:
		EnemyFactory() : EntityFactory() {};
		virtual Entity* createEntity(std::string name);
		
};

#endif //__ENEMY_FACTORY_H__

