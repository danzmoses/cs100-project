#ifndef __SMALL_HEAL_STRATEGY_H__
#define __SMALL_HEAL_STRATEGY_H__

#include "CardStrategy.h"

class SmallHealStrategy : public CardStrategy{
	public:
		SmallHealStrategy(){};

		virtual void use(Entity *attacker, Entity *defender){
			attacker->combatStats->HP += 2;
		}
};

#endif //__SMALL_HEAL_STRATEGY_H__
