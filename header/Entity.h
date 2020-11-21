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
        int level;
        int ATK;
        int DEF;

    public:
        Entity() : HP(100) {}
        Entity(std::string name) : name(name), HP(100), maxHP(100) {}
        
        std::string getName() { return this->name; }
        int getHP() { return this->HP; }
        int getMaxHP() { return this->maxHP; }
        int getLevel() { return this->level; }
        int getATK() { return this->ATK; }
        int getDEF() { return this->DEF; }

        void setName(std::string name) { this->name = name; }
        void setHP(int HP) { this->HP = HP; }
        void setMaxHP(int maxHP) { this->maxHP = maxHP; }
        void setLevel(int level) { this->level = level; }
        void setATK(int ATK) { this->ATK = ATK; }
        void setDEF(int DEF) { this->DEF = DEF; }
        
};

#endif // __ENTITY__