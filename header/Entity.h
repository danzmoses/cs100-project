#ifndef __ENTITY__
#define __ENTITY__

#include <iostream>
#include <string>
#include "Stats.h"

class Entity : public Stats {
    private:
        std::string name;
        int level;

    public:
        Entity() : Stats(){
		this->name = "Entity";
		this->level = 1;
		this->HP = 10;
		this->maxHP = 10;
		this->ATK = 1;
		this->DEF = 1;
	}

        Entity(std::string name) : Stats(){
		this->name= name; 
		this->level = 1; 
		this->HP = 10; 
		this->maxHP = 10;
		this->ATK = 1; 
		this->DEF = 1;
	}
        
        std::string getName() { return this->name; }
        int getLevel() { return this->level; }

        void setName(std::string name) { this->name = name; }
        void setLevel(int level){ this->level = level; }
        void restoreHP() { this->HP = this->maxHP; }
};

#endif // __ENTITY__
