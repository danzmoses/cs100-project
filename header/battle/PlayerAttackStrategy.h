#ifndef PLAYER_ATTACK_STRATEGY_H
#define PLAYER_ATTACK_STRATEGY_H

#include "AttackStrategy.h"

class PlayerAttackStrategy : public AttackStrategy
{
    private:
    public:
        PlayerAttackStrategy() {};
        void attack(Entity* attacker, Entity* defender)
        {
            defender->setHP(defender->getHP() - (attacker->getATK() - defender->getDEF()));
        }
};

#endif // PLAYER_ATTACK_STRATEGY_H