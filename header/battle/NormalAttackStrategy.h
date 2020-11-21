#ifndef NORMAL_ATTACK_STRATEGY_H
#define NORMAL_ATTACK_STRATEGY_H

#include "AttackStrategy.h"

class NormalAttackStrategy : public AttackStrategy
{
    private:
    public:
        NormalAttackStrategy() {};
        int attack(Entity* attacker, Entity* defender)
        {
            // normal attack: player ATK multiplier is 2 (base ATK * 2)
            // return 0 if damage done is less than or equal to 0
            int damageDone = (attacker->getATK() * 2) - defender->getDEF();
            return damageDone > 0 ? damageDone : 0;
        }
};

#endif // NORMAL_ATTACK_STRATEGY_H