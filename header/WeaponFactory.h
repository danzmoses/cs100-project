#ifndef __WEAPON_FACTORY_H__
#define __WEAPON_FACTORY_H__
#include "ItemFactory.h"

class WeaponFactory : public ItemFactory{
	public:
		WeaponFactory() : ItemFactory(){
		}
		virtual Item* createItem(std::string name){
		} 
};

#endif //__WEAPON_FACTORY_H__
