#ifndef __PLAYER__
#define __PLAYER__

#include "EntityFactory.h"
#include "Player.h"

class Player : public Entity
{

    public:
        Player() : Entity() {}
        Player(std::string name) : Entity(name) {}
};

#endif // __PLAYER_FACTORY__