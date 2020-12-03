#ifndef __ENTITY__
#define __ENTITY__

#include <iostream>
#include <string>
#include "Stats.h"

class Entity {
    private:
        std::string name;
        int level;

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

    void setName(std::string name) { this->name = name; }
    void setLevel(int level){ this->level = level; }
    void restoreHP() { combatStats->HP = combatStats->maxHP; }
};

#endif // __ENTITY__
