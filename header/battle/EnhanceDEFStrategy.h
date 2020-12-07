#ifndef __ENHANCE_DEF_STRATEGY_H__
#define __ENHANCE_DEF_STRATEGY_H__

#include "CardStrategy.h"

class EnhanceDEFStrategy : public CardStrategy{
	public:
		virtual void use(Entity *attacker, Entity *defender){
			attacker->combatStats->DEF += 1;
		}
};

#endif //__ENHANCE_DEF_STRATEGY_H__
