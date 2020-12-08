#ifndef SHOP_H
#define SHOP_H

#include "Entity.h"
#include "Inventory.h"
#include "WeaponFactory.h"
#include "ArmorFactory.h"

class Shop
{
    private:
        Inventory shopInventory;
        WeaponFactory* weaponFactory;
        ArmorFactory* armorFactory;

    public:
        Shop()
        {
            weaponFactory = new WeaponFactory;
            armorFactory = new ArmorFactory;
            std::vector<Item*> weapons = weaponFactory->getPrototypes();
            for (unsigned i = 0; i < weapons.size(); ++i)
                shopInventory.addWeapon(weapons[i]);
            std::vector<Item*> armor = armorFactory->getPrototypes();
            for (unsigned i = 0; i < armor.size(); ++i)
                shopInventory.addArmor(armor[i]);            
        };
        Inventory getShopInventory() { return shopInventory; }
        bool buyWeapon(Entity* player, std::string weapon)
        {
            Item* item = nullptr;
            try {
                item = shopInventory.getItem(weapon);
            } catch(const std::invalid_argument &ia) {
                return false;
            }

            if (player->getGold() < item->getCost())
                return false;
            player->setGold(player->getGold() - item->getCost());
            player->addWeaponToInventory(weapon, weaponFactory);
            shopInventory.removeItem(weapon);
            return true;
        }
        bool buyArmor(Entity* player, std::string armor)
        {
            Item* item = nullptr;
            try {
                item = shopInventory.getItem(armor);
            } catch(const std::invalid_argument &ia) {
                return false;
            }

            if (player->getGold() < item->getCost())
                return false;
            player->setGold(player->getGold() - item->getCost());
            player->addArmorToInventory(armor, armorFactory);
            shopInventory.removeItem(armor);
            return true;
        }        
};

#endif // SHOP_H