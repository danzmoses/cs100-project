#ifndef ATTACK_STRATEGY_H
#define ATTACK_STRATEGY_H

#include "../Entity.h"

class AttackStrategy
{
    private:
        
    public:
        AttackStrategy() {};

        // returns total damage done to the defender after calculation
        virtual int attack(Entity* attacker, Entity* defender) = 0;
};

#endif // ATTACK_STRATEGY_H