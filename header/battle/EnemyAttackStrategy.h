#include "AttackStrategy.h"

class EnemyAttackStrategy : public AttackStrategy
{
    private:
    public:
        EnemyAttackStrategy();
        void attack(Entity* attacker, Entity* defender)
        {
            defender->setHP(attacker->getATK() - defender->getDEF());
        }
};