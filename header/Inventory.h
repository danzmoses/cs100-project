#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include "Item.h"
#include <vector>

class Inventory 
{
    private:
        std::vector<Item*> weapons;
        std::vector<Item*> armor;
    
    public:
        Inventory() {}
        void addWeapon(Item* w) { this->weapons.push_back(w); }
        void addArmor(Item* a) { this->armor.push_back(a); }

        std::vector<Item*> getWeapons() { return weapons; }
        std::vector<Item*> getArmor() { return armor; }
};

#endif // __INVENTORY_H__