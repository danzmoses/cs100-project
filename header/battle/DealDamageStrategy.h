#ifndef __DEAL_DAMAGE_STRATEGY_H__
#define __DEAL_DAMAGE_STRATEGY_H__

#include "CardStrategy.h"
#include <cmath>

class DealDamageStrategy : public CardStrategy{
	public:
		DealDamageStrategy() {};

		virtual void use(Entity *attacker, Entity *defender){
			//defender->combatStats->HP -= 1;
			//defenders lose 30% of their current health, rounded to nearest number
			double thirtyPercentHP = (3.0/10) * defender->combatStats->HP;
                        if(defender->combatStats->HP - round(thirtyPercentHP) > 0){
                                defender->combatStats->HP -= round(thirtyPercentHP);
                        }
                        else if(attacker->combatStats->HP - round(fourtyPercentHP) <= 0){
                                defender->combatStats->HP = 0;
                        }
		}
};

#endif //__DEAL_DAMAGE_STRATEGY_H__
