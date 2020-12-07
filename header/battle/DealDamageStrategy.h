#ifndef __DEAL_DAMAGE_STRATEGY_H__
#define __DEAL_DAMAGE_STRATEGY_H__

#include "CardStrategy.h"

class DealDamageStrategy : public CardStrategy{
	public:
		DealDamageStrategy() {};

		virtual void use(Entity *attacker, Entity *defender){
			defender->combatStats->HP -= 1; 
		}
};

#endif //__DEAL_DAMAGE_STRATEGY_H__
