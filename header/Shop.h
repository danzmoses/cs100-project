#ifndef SHOP_H
#define SHOP_H

#include "Player.h"
#include "Enemy.h"
#include "Inventory.h"
#include "WeaponFactory.h"
#include "ArmorFactory.h"

class Shop
{
    private:
        Inventory itemsForSale;
        WeaponFactory weaponFactory;
        ArmorFactory armorFactory;   

    public:
        Shop()
        {
            std::vector<Item*> weapons = weaponFactory.getPrototypes();
            for (unsigned i = 0; i < weapons.size(); ++i)
                itemsForSale.addWeapon(weapons[i]);
            std::vector<Item*> armor = armorFactory.getPrototypes();
            for (unsigned i = 0; i < armor.size(); ++i)
                itemsForSale.addArmor(armor[i]);            
        };
};

#endif // SHOP_H