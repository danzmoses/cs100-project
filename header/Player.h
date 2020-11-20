#ifndef __PLAYER__
#define __PLAYER__

#include "EntityFactory.h"
#include "Player.h"

class Player : public Entity
{
    private:
        int gold;
    public:
        Player() : Entity() {}
        int getGold() { return this->gold; }
        void addGold(int gold) { this->gold += gold; }

};

#endif // __PLAYER_FACTORY__