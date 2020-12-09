#ifndef __ENHANCE_ATK_STRATEGY_H__
#define __ENHANCE_ATK_STRATEGY_H__

#include "CardStrategy.h"

class EnhanceATKStrategy : public CardStrategy{
	public:
		EnhanceATKStrategy() {};

		virtual void use(Entity *attacker, Entity *defender){
			attacker->combatStats->ATK += 1;
		}
};

#endif //__ENHANCE_ATK_STRATEGY_H__
