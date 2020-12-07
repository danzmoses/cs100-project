#ifndef __SMALL_HEAL_PROTOTYPE_H__
#define __SMALL_HEAL_PROTOTYPE_H__

#include "CardPrototype.h"

class SmallHealPrototype : public CardPrototype{
	public:
		SmallHealPrototype() : CardPrototype(){
			this->setName("Small Heal"); 
			this->setCost(65);
			this->setDescription("This card raises the card user's HP by 40% their current HP (rounded to the nearest whole number)");
		}

		SmallHealPrototype(std::string name) : CardPrototype(name){
			this->setCost(65);
			this->setDescription("This card raises the card user's HP by 40% their current HP (rounded to the nearest whole number)"); 
		}

		virtual CardPrototype* Clone(){
			return new SmallHealPrototype();
		} 
};

#endif //__SMALL_HEAL_PROTOTYPES_H__
