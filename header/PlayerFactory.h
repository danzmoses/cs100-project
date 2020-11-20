#ifndef __PLAYER_FACTORY_H__
#define __PLAYER_FACTORY_H__
#include "EntityFactory.h"
#include "Player.h"

class PlayerFactory : public EntityFactory{
	public:
		PlayerFactory() : EntityFactory(){};  
		virtual Entity* createEntity(std::string name){
			Player* p = new Player(name);
			return p;
		}
};

#endif //__PLAYER_FACTORY_H__
