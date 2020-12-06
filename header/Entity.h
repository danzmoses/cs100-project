#ifndef __ENTITY__
#define __ENTITY__

#include <iostream>
#include <string>
#include "Stats.h"
#include "Inventory.h"
#include "ItemFactory.h"

class Entity 
{
    private:
        std::string name;
        int level;
        Inventory inventory;
        Inventory equipped;


    public:
        Stats *baseStats = new Stats();
        Stats *combatStats = new Stats();

        Entity()
        {
            this->name = "Entity";
            this->level = 1;
            baseStats->HP = 10;
            baseStats->maxHP = 10;
            baseStats->ATK = 1;
            baseStats->DEF = 1;
            combatStats->HP = 10;
            combatStats->maxHP = 10;
            combatStats->ATK = 1;
            combatStats->DEF = 1;
        }

        Entity(std::string name)
        {
            this->name= name;
            this->level = 1;
            baseStats->HP = 10;
            baseStats->maxHP = 10;
            baseStats->ATK = 1;
            baseStats->DEF = 1;
            combatStats->HP = 10;
            combatStats->maxHP = 10;
            combatStats->ATK = 1;
            combatStats->DEF = 1;
        }
        
        // __GETTERS__
        std::string getName() { return this->name; }
        int getLevel() { return this->level; }
        Inventory getInventory() { return this->inventory; }
        Inventory getEquipped() { return this->equipped; }

        // __SETTERS__
        void setName(std::string name) { this->name = name; }
        void setLevel(int level){ this->level = level; }

        // __PUBLIC_FUNCTIONS__
        void restoreHP() { combatStats->HP = combatStats->maxHP; }
        void addWeaponToInventory(std::string name, ItemFactory* wf) { this->inventory.addWeapon(wf->createItem(name)); }
        void addArmorToInventory(std::string name, ItemFactory* af) { this->inventory.addArmor(af->createItem(name)); }
        
        void removeItemFromInventory(std::string name) // if name of Item* is in equipped, this removes that Item* as well
        {
            this->inventory.removeItem(name);

            if (!this->equipped.getArmor().empty())
                if (this->equipped.getArmor().at(0)->getName() == name)
                    this->equipped.removeItem(name);

            if (!this->equipped.getWeapons().empty())
                if (this->equipped.getWeapons().at(0)->getName() == name)
                    this->equipped.removeItem(name);
        }

        void equipWeapon(std::string name)
        {
            for (int i = 0; i < this->inventory.getWeapons().size(); ++i)
            {
                if (this->inventory.getWeapons().at(i)->getName() == name)
                {
                    if (this->equipped.getWeapons().size() >= 1)
                        this->equipped.modifyWeaponItem(0, this->inventory.getWeapons().at(i));
                    else
                        this->equipped.addWeapon(this->inventory.getWeapons().at(i));
                    return;
                }
            }
            std::invalid_argument ia("Invalid argument. Unable to find a weapon named \"" + name + "\" inside of this inventory.");
            throw ia;
        }
        
        void equipArmor(std::string name)
        {
            for (int i = 0; i < this->inventory.getArmor().size(); ++i)
            {
                if (this->inventory.getArmor().at(i)->getName() == name)
                {
                    if (this->equipped.getArmor().size() >= 1)
                        this->equipped.modifyArmorItem(0, this->inventory.getArmor().at(i));
                        // this->equipped.getArmor().at(0) = this->inventory.getArmor().at(i);
                    else
                        this->equipped.addArmor(this->inventory.getArmor().at(i));
                    return;
                }
            }
            std::invalid_argument ia("Invalid argument. Unable to find armor named \"" + name + "\" inside of this inventory.");
            throw ia;
        }
        
};

#endif // __ENTITY__
