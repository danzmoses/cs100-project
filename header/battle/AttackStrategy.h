#include "../Entity.h"

class AttackStrategy
{
    private:
        
    public:
        AttackStrategy();
        virtual void attack(Entity* attacker, Entity* defender) = 0;
};