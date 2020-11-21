#ifndef __ENEMY__
#define __ENEMY__

#include <string>
#include "Entity.h"

class Enemy : public Entity
{
    private:
        std::string description;
        
    public:
        Enemy() : Entity() {}
        Enemy(std::string name) : Entity(name), description("rawr") {}

        std::string getDescription() { return description; }

        void setDescription(std::string description) { this->description = description; }
};

#endif // __ENEMY__