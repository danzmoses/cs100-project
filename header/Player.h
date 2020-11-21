#ifndef __PLAYER__
#define __PLAYER__

class Player
{
    private:
        std::string name;
        int health;
        int maxHP;
        int gold;

    public:
        Player() {}
        Player(std::string name) {}
        
        std::string getName() { return this->name; }
        int getHealth() { return this->health; }
        int getMaxHP() { return this->maxHP; }
        int getGold() { return this->gold; }


        void setName(std::string name) { this->name = name; }
        void setHealth(int health) { this->health = health; }
        void setGold(int gold) { this->gold = gold; }
        void setMaxHP(int maxHP) { this->maxHP = maxHP; }
};

#endif // __PLAYER_FACTORY__