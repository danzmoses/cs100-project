#ifndef __PLAYER__
#define __PLAYER__

#include <string>
#include "Entity.h"

class Player : public Entity
{
    private:
        int gold;

    public:
        Player() : Entity() {}
        Player(std::string name) : Entity(name), gold(50) {}
        
        int getGold() { return this->gold; }

        void setGold(int gold) { this->gold = gold; }

};

#endif // __PLAYER_FACTORY__