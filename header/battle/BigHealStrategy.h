#ifndef __BIG_HEAL_STRATEGY_H__
#define __BIG_HEAL_STRATEGY_H__

#include "CardStrategy.h"
#include <iostream>
#include <cmath>

class BigHealStrategy : public CardStrategy{
        public:
                BigHealStrategy(){}

                virtual void use(Entity *attacker, Entity *defender){
                        double sixtyPercentHP = (3.0/5) * attacker->combatStats->HP;
                        if(attacker->combatStats->HP + round(sixtyPercentHP) < attacker->combatStats->maxHP){
                                attacker->combatStats->HP += round(sixtyPercentHP);
                        }
                        else if(attacker->combatStats->HP + round(sixtyPercentHP) >= attacker->combatStats->maxHP){
                                attacker->combatStats->HP = attacker->combatStats->maxHP;
                        }
                }
};

#endif //__BIG_HEAL_STRATEGY_H__
