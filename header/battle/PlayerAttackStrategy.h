#include "AttackStrategy.h"

class PlayerAttackStrategy : public AttackStrategy
{
    private:
    public:
        PlayerAttackStrategy();
        void attack(Entity* attacker, Entity* defender);
};