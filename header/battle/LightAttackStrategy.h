#ifndef LIGHT_ATTACK_STRATEGY_H
#define LIGHT_ATTACK_STRATEGY_H

#include "AttackStrategy.h"

class LightAttackStrategy : public AttackStrategy
{
    private:
    public:
        LightAttackStrategy() {};
        void attack(Entity* attacker, Entity* defender)
        {
            // light attack: player ATK multiplier is 1 (base ATK)
            int damageDone = attacker->getATK() - defender->getDEF();
            defender->setHP(defender->getHP() - damageDone);
        }
};

#endif // LIGHT_ATTACK_STRATEGY_H