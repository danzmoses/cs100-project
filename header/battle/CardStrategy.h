#ifndef __CARD_STRATEGY_H__
#define __CARD_STRATEGY_H__

#include "../Entity.h"

class CardStrategy{
	CardStrategy(){};

	virtual void use(Entity *attacker, Entity *defender) = 0;


};

#endif //__CARD_STRATEGY_H__
