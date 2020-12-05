#ifndef __ENTITY__
#define __ENTITY__

#include <iostream>
#include <string>
#include "Stats.h"
#include "Inventory.h"

class Entity {
    private:
        std::string name;
        int level;
        Inventory* inventory;
        Inventory* equipped;


    public:
	Stats *baseStats = new Stats();
	Stats *combatStats = new Stats();
    Entity(){
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

    Entity(std::string name){
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
        
    std::string getName() { return this->name; }
    int getLevel() { return this->level; }
    Inventory* getInventory() { this->inventory; }
    Inventory* getEquipped() { this->equipped; }

    void setName(std::string name) { this->name = name; }
    void setLevel(int level){ this->level = level; }
    void restoreHP() { combatStats->HP = combatStats->maxHP; }
    void addWeaponToInventory(std::string name, ItemFactory* wf) { this->inventory->addWeapon(wf->createItem(name)); }
    void addArmorToInventory(std::string name, ItemFactory* af) { this->inventory->addArmor(af->createItem(name)); }

    void equipWeapon(std::string name)
    {
        for (int i = 0; i < this->inventory->getWeapons().size(); ++i)
        {
            if (this->inventory->getWeapons().at(i)->getName() == name)
            {
                if (this->equipped->getWeapons().size() >= 1)
                {
                    this->equipped->getWeapons().clear();
                    this->equipped->getWeapons().push_back(this->inventory->getWeapons().at(i));
                    return;
                }
            }
		}
        std::invalid_argument ia("Invalid argument. Unable to find \"" + name + "\" inside of this inventory.");
        throw ia;
	}


};

#endif // __ENTITY__
