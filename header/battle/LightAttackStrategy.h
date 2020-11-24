#ifndef LIGHT_ATTACK_STRATEGY_H
#define LIGHT_ATTACK_STRATEGY_H

#include "AttackStrategy.h"

class LightAttackStrategy : public AttackStrategy
{
    private:
    public:
        LightAttackStrategy() {};
        int attack(Entity* attacker, Entity* defender)
        {
            // light attack: player ATK multiplier is 1 (base ATK)
            // return 0 if damage done is less than or equal to 0
            int damageDone = attacker->getATK() - defender->getDEF();
            return damageDone > 0 ? damageDone : 0;
        }
};

#endif // LIGHT_ATTACK_STRATEGY_H