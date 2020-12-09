#ifndef __ENTITY__
#define __ENTITY__

#include <iostream>
#include <string>
#include "Stats.h"
#include "Inventory.h"
#include "ItemFactory.h"
#include "CardFactory.h"

class Entity 
{
    private:
        std::string name;
        int level;
        int gold;
        Inventory inventory;
        Inventory equipped;

    public:
        Stats *baseStats = new Stats();
        Stats *combatStats = new Stats();
        Entity()
        {
            this->name = "Entity";
            this->level = 1;
            baseStats->HP = 5;
            baseStats->maxHP = 5;
            baseStats->ATK = 1;
            baseStats->DEF = 1;
            combatStats->HP = 5;
            combatStats->maxHP = 5;
            combatStats->ATK = 1;
            combatStats->DEF = 1;
        }

        Entity(std::string name)
        {
            this->name = name;
            this->level = 1;
            baseStats->HP = 5;
            baseStats->maxHP = 5;
            baseStats->ATK = 1;
            baseStats->DEF = 1;
            combatStats->HP = 5;
            combatStats->maxHP = 5;
            combatStats->ATK = 1;
            combatStats->DEF = 1;
        }

        // __GETTERS__
        std::string getName() { return this->name; }
        int getLevel() { return this->level; }
        int getGold() { return this->gold; }
        Inventory getInventory() { return this->inventory; }
        Inventory getEquipped() { return this->equipped; }

        // __SETTERS__
        void setName(std::string name) { this->name = name; }
        void setLevel(int level) { this->level = level; }
        void setGold(int gold) { this->gold = gold; }

        // __PUBLIC_FUNCTIONS__
        void restoreHP() { combatStats->HP = combatStats->maxHP; }
        void addWeaponToInventory(std::string name, ItemFactory* wf) { this->inventory.addWeapon(wf->createItem(name)); }
        void addArmorToInventory(std::string name, ItemFactory* af) { this->inventory.addArmor(af->createItem(name)); }
        void addCardToInventory(std::string name, CardFactory* cf) { this->inventory.addCard(cf->createCard(name)); }

        void updateCombatStats()
        {
            this->combatStats->ATK = this->baseStats->ATK;
            this->combatStats->DEF = this->baseStats->DEF;
            this->combatStats->HP = this->baseStats->HP;
            this->combatStats->maxHP = this->baseStats->maxHP;

            for (int i = 0; i < this->equipped.getWeapons().size(); ++i) // add equipped weapon combat stats to player combat stats
            {
                this->combatStats->ATK += this->equipped.getWeapons().at(i)->combatStats->ATK;
                this->combatStats->DEF += this->equipped.getWeapons().at(i)->combatStats->DEF;
                this->combatStats->HP += this->equipped.getWeapons().at(i)->combatStats->HP;
                this->combatStats->maxHP += this->equipped.getWeapons().at(i)->combatStats->maxHP;
            }

            for (int i = 0; i < this->equipped.getArmor().size(); ++i) // add all armor combat stats to player's combat stats
            {
                this->combatStats->ATK += this->equipped.getArmor().at(i)->combatStats->ATK;
                this->combatStats->DEF += this->equipped.getArmor().at(i)->combatStats->DEF;
                this->combatStats->HP += this->equipped.getArmor().at(i)->combatStats->HP;
                this->combatStats->maxHP += this->equipped.getArmor().at(i)->combatStats->maxHP;
            }
        }

        void equipWeapon(std::string name)
        {
            for (int i = 0; i < this->equipped.getWeapons().size(); ++i)
            {
                if (this->equipped.getWeapons().at(i)->getName() == name)
                {
                    std::invalid_argument ia("Invalid argument. This item is already equipped.");
                    throw ia;
                }
            }

            for (int i = 0; i < this->inventory.getWeapons().size(); ++i)
            {
                if (this->inventory.getWeapons().at(i)->getName() == name)
                {
                    if (this->equipped.getWeapons().size() >= 1)
                        this->equipped.modifyWeaponItem(0, this->inventory.getWeapons().at(i));
                    else
                        this->equipped.addWeapon(this->inventory.getWeapons().at(i));
                    // call updateCombatStats helper function
                    updateCombatStats();
                    return;
                }
            }
            std::invalid_argument ia("Invalid argument. Unable to find a weapon named \"" + name + "\" inside of this inventory.");
            throw ia;
        }
        
        void equipArmor(std::string name)
        {
            for (int i = 0; i < this->equipped.getArmor().size(); ++i)
            {
                if (this->equipped.getArmor().at(i)->getName() == name)
                {
                    std::invalid_argument ia("Invalid argument. This item is already equipped.");
                    throw ia;
                }
            }

            for (int i = 0; i < this->inventory.getArmor().size(); ++i)
            {
                if (this->inventory.getArmor().at(i)->getName() == name)
                {
                    if (this->equipped.getArmor().size() >= 1)
                        this->equipped.modifyArmorItem(0, this->inventory.getArmor().at(i));
                    else
                        this->equipped.addArmor(this->inventory.getArmor().at(i));
                    // call updateCombatStats helper function
                    updateCombatStats();
                    return;
                }
            }
            std::invalid_argument ia("Invalid argument. Unable to find armor named \"" + name + "\" inside of this inventory.");
            throw ia;
        }

        void equipCard(std::string name)
        {
            for (int i = 0; i < this->equipped.getCards().size(); ++i)
            {
                if (this->equipped.getCards().at(i)->getName() == name)
                {
                    std::invalid_argument ia("Invalid argument. This card is already equipped.");
                    throw ia;
                }
            }
            
            for (int i = 0; i < this->inventory.getCards().size(); ++i)
            {
                if (this->inventory.getCards().at(i)->getName() == name)
                {
                    if (this->equipped.getCards().size() >= 4)
                    {
                        std::invalid_argument ia("Invalid argument. This inventory already has the max number of Cards (4).");
                        throw ia;
                    }
                    this->equipped.addCard(this->inventory.getCards().at(i));
                    return;
                }
            }
            std::invalid_argument ia("Invalid argument. Unable to find armor named \"" + name + "\" inside of this inventory.");
            throw ia;
        }
        
        void removeItemFromInventory(std::string name) // if name of Item* is in equipped, this removes that Item* as well
        {
            this->inventory.removeItem(name);

            if (!this->equipped.getArmor().empty())
                if (this->equipped.getArmor().at(0)->getName() == name)
                {
                    this->equipped.removeItem(name);
                    updateCombatStats();
                }
            
            if (!this->equipped.getWeapons().empty())
                if (this->equipped.getWeapons().at(0)->getName() == name)
                {
                    this->equipped.removeItem(name);
                    updateCombatStats();
                }

            if (!this->equipped.getCards().empty())
            {
                for (int i = 0; i < this->equipped.getCards().size(); ++i)
                    if (this->equipped.getCards().at(i)->getName() == name)
                        this->equipped.removeItem(name);
            }
        }
};

#endif // __ENTITY__
