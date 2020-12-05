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

        Item* findItem(std::string name)
        {
            for (int i = 0; i < this->weapons.size(); ++i)
                if (this->weapons.at(i)->getName() == name)
                    return this->weapons.at(i);

            for (int i = 0; i < this->armor.size(); ++i)
                if (this->armor.at(i)->getName() == name)
                    return this->armor.at(i);
            
            std::invalid_argument ia("Invalid argument. Unable to find item named \"" + name + "\" inside of this inventory.");
            throw ia;
        }
        
};


#endif // __INVENTORY_H__