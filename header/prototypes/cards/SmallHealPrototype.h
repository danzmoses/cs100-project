#ifndef __SMALL_HEAL_PROTOTYPE_H__
#define __SMALL_HEAL_PROTOTYPE_H__

#include "CardPrototype.h"

class SmallHealPrototype : public CardPrototype{
	public:
		SmallHealPrototype() : CardPrototype(){
			this->setName("Small Heal"); 
			this->setCost(65);
			this->setDescription("This card raises HP by 2");
		}
};

#endif //__SMALL_HEAL_PROTOTYPES_H__
