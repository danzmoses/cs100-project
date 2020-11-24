#ifndef __PLAYER_FACTORY_H__
#define __PLAYER_FACTORY_H__
#include "EntityFactory.h"
#include "Player.h"

class PlayerFactory : public EntityFactory{
	public:
		PlayerFactory() : EntityFactory(){};  
		virtual Entity* createEntity(std::string name){
			return new Player(name);
		}
};

#endif //__PLAYER_FACTORY_H__
