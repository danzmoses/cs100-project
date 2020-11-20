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

    public:
        Battle();
        void getRoll();  
};