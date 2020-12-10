#ifndef __ENHANCE_DEF_PROTOTYPE_H__
#define __ENHANCE_DEF_PROTOTYPE_H__

#include "CardPrototype.h"

class EnhanceDEFPrototype : public CardPrototype{
	public:
		EnhanceDEFPrototype() : CardPrototype(){
			this->setName("Enhance DEF");
			this->setCost(75);
			this->setDescription("This card enhances DEF by 1");
		}

		EnhanceDEFPrototype(std::string name) : CardPrototype(name){
			this->setCost(75);
			this->setDescription("This card enhances DEF by 1");
		}

		virtual CardPrototype* Clone(){
			return new EnhanceDEFPrototype();
		}
};

#endif //__ENHANCE_DEF_PROTOTYPE_H__
