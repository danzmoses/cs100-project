#ifndef __SMALL_HEAL_PROTOTYPE_H__
#define __SMALL_HEAL_PROTOTYPE_H__

#include "CardPrototype.h"

class SmallHealPrototype : public CardPrototype{
	public:
		SmallHealPrototype() : CardPrototype(){
			this->setName("Small Heal"); 
			this->setCost(65);
			this->setDescription("This card raises HP by 40% the user's current HP");
		}

		SmallHealPrototype(std::string name) : CardPrototype(name){
			this->setCost(65);
			this->setDescription("This card raises HP by 40% the user's current HP"); 
		}

		virtual CardPrototype* Clone(){
			return new SmallHealPrototype();
		} 
};

#endif //__SMALL_HEAL_PROTOTYPES_H__
