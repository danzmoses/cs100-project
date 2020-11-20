#ifndef ENEMY_ATTACK_STRATEGY_H
#define ENEMY_ATTACK_STRATEGY_H

#include "AttackStrategy.h"

class EnemyAttackStrategy : public AttackStrategy
{
    private:
    public:
        EnemyAttackStrategy() {};
        void attack(Entity* attacker, Entity* defender)
        {
            defender->setHP(defender->getHP() - (attacker->getATK() - defender->getDEF()));
        }
};

#endif // ENEMY_ATTACK_STRATEGY_H