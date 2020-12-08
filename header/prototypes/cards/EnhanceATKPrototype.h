#ifndef __ENHANCE_ATK_PROTOTYPE_H__
#define __ENHANCE_ATK_PROTOTYPE_H__

#include "CardPrototype.h"

class EnhanceATKPrototype : public CardPrototype{
	public:
		EnhanceATKPrototype() : CardPrototype(){
			this->setName("Enhance ATK");
			this->setCost(75);
			this->setDescription("This card enhances ATK by 1");
		}

		EnhanceATKPrototype(std::string name) : CardPrototype(name){
			this->setCost(75);
			this->setDescription("This card enhances ATK by 1");
		}

		virtual CardPrototype* Clone(){
			return new EnhanceATKPrototype();
		}

		
};

#endif //__ENHANCE_ATK_PROTOTYPE_H__
