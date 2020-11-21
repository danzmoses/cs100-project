#ifndef __ENTITY__
#define __ENTITY__

#include <iostream>
#include <string>

class Entity 
{
    private:
        std::string name;
        int HP;
        int maxHP;

    public:
        Entity() : HP(100) {}
        Entity(std::string name) : name(name), HP(100), maxHP(100) {}
        
        std::string getName() { return this->name; }
        int getHP() { return this->HP; }
        int getMaxHP() { return this->maxHP; }

        void setName(std::string name) { this->name = name; }
        void setHP(int HP) { this->HP = HP; }
        void setMaxHP(int maxHP) { this->maxHP = maxHP; }
};

#endif // __PLAYER_FACTORY__