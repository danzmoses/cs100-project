#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Entity.h"

class Player : public Entity{

	public:
	Player(){
	}

	Player(std::string name){
		this->setName(name);
		//stats for player inherited from entity
	}	

	//addWeapon(std::string name, ItemFactory* WF){
	//	inventory.push_back(item_factory->createItem(name));
	//}

	//addArmor(std::string name, ItemFactory* AF){
	//	inventory.push_back(item_factory->createItem(name));
	//}
};

#endif //__PLAYER_H__
