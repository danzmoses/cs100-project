#ifndef __PLAYER__
#define __PLAYER__

#include <string>
#include "Entity.h"

class Player : public Entity
{
    private:
        int gold;
        int EXP;

    public:
        Player() : Entity(), gold(50), EXP(0) {}
        Player(std::string name) : Entity(name), gold(50), EXP(0) {}
        
        int getGold() { return this->gold; }
        int getEXP() { return this->EXP; }

        void setGold(int gold) { this->gold = gold; }
        void setEXP(int EXP) { this->EXP = EXP; }
};

#endif // __PLAYER__