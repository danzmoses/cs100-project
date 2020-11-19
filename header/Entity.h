#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <string>

class Entity 
{
    private:
        std::string name;
        int health;

    public:
        Entity();
        Entity(std::string name, int health) : name(name), health(health) {};
        virtual std::string getName() {};
        virtual int getHealth() {};

};

#endif // __ENTITY_H__