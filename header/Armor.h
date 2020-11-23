#ifndef __ARMOR_H__
#define __ARMOR_H__

#include "Item.h"

class Armor : public Item
{
	public:
        Armor() : Item() {}
        Armor(std::string name) : Item(name) {}
};

#endif //__ARMOR_H__