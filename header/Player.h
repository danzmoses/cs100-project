#ifndef __PLAYER__
#define __PLAYER__

#include <string>
#include "Entity.h"

class Player : public Entity
{
    private:
        int gold;
        int level;
        int EXP;

    public:
        Player() : Entity(), gold(50), EXP(0) {}
        Player(std::string name) : Entity(name), gold(50), EXP(0) {}
        
        int getGold() { return this->gold; }
        int getEXP() { return this->EXP; }
        int getLevel() { return this->level; }

        void setGold(int gold) { this->gold = gold; }
        void setEXP(int EXP) { this->EXP = EXP; }
        void setLevel(int level) { this->level = level; }
};

#endif // __PLAYER__