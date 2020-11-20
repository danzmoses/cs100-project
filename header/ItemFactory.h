#ifndef __ITEM_FACTORY_H__
#define __ITEM_FACTORY_H__
#include "AbstractFactory.h"
#include "Item.h"


class ItemFactory : public AbstractFactory{
	public:
		ItemFactory() : AbstractFactory {};
		virtual Item* createItem(std::string name) = 0;
};

#endif //__ITEM_FACTORY_H__
