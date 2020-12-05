#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include "Item.h"
#include <vector>

class Inventory 
{
    private:
        std::vector<Item*> weapons;
        std::vector<Item*> armor;
};

#endif // __INVENTORY_H__