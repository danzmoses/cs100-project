#include "../Player.h"
#include "../Enemy.h"
#include <random>
#include <time.h>
#include "AttackStrategy.h"
#include "PlayerAttackStrategy.h"
#include "EnemyAttackStrategy.h"


class Battle
{
    private:
        Player* player;
        Enemy* enemy;
        Entity* attacker;
        Entity* defender;
        AttackStrategy* attackStrategy;
        void getRoll()
        {
            srand(time(0));
            if (std::rand() % 2 == 0)
            {
                attackStrategy = new PlayerAttackStrategy();
                attacker = player;
                defender = enemy;
            }
            else
            {
                attackStrategy = new EnemyAttackStrategy();
                attacker = enemy;
                defender = player;
            } 
        }

    public:
        Battle();
        void nextTurn();
};