#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <string>

class Entity 
{
    private:
        std::string name;
        int health;

    public:
        Entity() {};
        Entity(std::string name) : name(name) {};
    
        virtual std::string getName() { return this->name; };
        virtual int getHealth() { return this->health; };

        virtual void setName(std::string name) { this->name = name; };
        virtual void setHealth(int health) { this->health = health; };
};

#endif // __ENTITY_H__