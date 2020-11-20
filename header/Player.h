#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Entity.h"
//#include "ItemFactory.h"
//#include "Item.h"
#include <vector>

class Player : public Entity{
	private:
		//ItemFactory* item_factory;
		//vector <Item*> inventory; //everything the player has bought/unlocked
		//vector <Item*> equipped; //only items from inventory player is curr using

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
