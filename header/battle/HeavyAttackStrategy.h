#ifndef HEAVY_ATTACK_STRATEGY_H
#define HEAVY_ATTACK_STRATEGY_H

#include "AttackStrategy.h"

class HeavyAttackStrategy : public AttackStrategy
{
    private:
    public:
        HeavyAttackStrategy() {};
        int attack(Entity* attacker, Entity* defender)
        {
            // heavy attack: player ATK multiplier is 3 (base ATK * 3)
            // return 0 if damage done is less than or equal to 0
            int damageDone = (attacker->getATK() * 3) - defender->getDEF();
            return damageDone > 0 ? damageDone : 0;
        }
};

#endif // HEAVY_ATTACK_STRATEGY_H