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
        int ATK;
        int DEF;

    public:
        Entity() : name("Entity"), HP(10), maxHP(10), ATK(1), DEF(1) {}
        Entity(std::string name) : name(name), HP(10), maxHP(10), ATK(1), DEF(1) {}
        
        std::string getName() { return this->name; }
        int getHP() { return this->HP; }
        int getMaxHP() { return this->maxHP; }
        int getATK() { return this->ATK; }
        int getDEF() { return this->DEF; }

        void setName(std::string name) { this->name = name; }
        void setHP(int HP) { this->HP = HP; }
        void setMaxHP(int maxHP) { this->maxHP = maxHP; }
        void setATK(int ATK) { this->ATK = ATK; }
        void setDEF(int DEF) { this->DEF = DEF; }
        void restoreHP() { this->HP = this->maxHP; }
};

#endif // __ENTITY__