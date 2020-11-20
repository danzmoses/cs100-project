#include "../Entity.h"
#include <random>
#include <time.h>
#include "AttackStrategy.h"
#include "PlayerAttackStrategy.h"
#include "EnemyAttackStrategy.h"

class Battle
{
    private:
        Entity* player;
        Entity* enemy;
        Entity* attacker;
        Entity* defender;
        AttackStrategy* attackStrategy;
        bool playerWonRoll;
        void getRoll()
        {
            if (std::rand() % 2 == 0)
            {
                attackStrategy = new PlayerAttackStrategy();
                attacker = player;
                defender = enemy;
                playerWonRoll = true;
            }
            else
            {
                attackStrategy = new EnemyAttackStrategy();
                attacker = enemy;
                defender = player;
                playerWonRoll = false;
            } 
        }

    public:
        Battle();
        Battle(Entity* player, Entity* enemy): player(player), enemy(enemy) {};
        void nextTurn()
        {
            getRoll();
            attackStrategy->attack(attacker, defender);
        }
        bool getPlayerWonRoll() { return playerWonRoll; }
};