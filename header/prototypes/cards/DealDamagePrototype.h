#ifndef __DEAL_DAMAGE_PROTOTYPE_H__
#define __DEAL_DAMAGE_PROTOTYPE_H__

#include "CardPrototype.h"

class DealDamagePrototype : public CardPrototype{
	public:
		DealDamagePrototype() : CardPrototype(){
			this->setName("Deal Damage");
			this->setCost(85);
			this->setDescription("This card decreases the enemy's HP by 1");
		}

		DealDamagePrototype(std::string name) : CardPrototype(name){
			this->setCost(85);
			this->setDescription("This card decreases the enemy's HP by 1");
		}

		virtual CardPrototype* Clone(){
			return new DealDamagePrototype(); 
		}
};

#endif //__DEAL_DAMAGE_PROTOTYPE_H__
