#ifndef __SMALL_HEAL_STRATEGY_H__
#define __SMALL_HEAL_STRATEGY_H__

#include "CardStrategy.h"
#include <iostream> 
#include <cmath>

class SmallHealStrategy : public CardStrategy{
	public:
		SmallHealStrategy(){};

		virtual void use(Entity *attacker, Entity *defender){
			double fourtyPercentHP = (2.0/5) * attacker->combatStats->HP;
			if(attacker->combatStats->HP + round(fourtyPercentHP) < attacker->combatStats->maxHP){
				attacker->combatStats->HP += round(fourtyPercentHP);
			} 
			else if(attacker->combatStats->HP + round(fourtyPercentHP) >= attacker->combatStats->maxHP){
				attacker->combatStats->HP = attacker->combatStats->maxHP;
			} 
		}
};

#endif //__SMALL_HEAL_STRATEGY_H__
