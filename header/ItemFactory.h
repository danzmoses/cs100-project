#ifndef __ITEM_FACTORY_H__
#define __ITEM_FACTORY_H__
#include "Item.h"

class ItemFactory{
	public:
		ItemFactory() {};
		virtual Item* createItem(std::string name) = 0;
};

#endif //__ITEM_FACTORY_H__
