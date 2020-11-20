#include "AttackStrategy.h"

class PlayerAttackStrategy : public AttackStrategy
{
    private:
    public:
        PlayerAttackStrategy();
        void attack(Entity* attacker, Entity* defender)
        {
            defender->setHP(attacker->getATK() - defender->getDEF());
        }
};