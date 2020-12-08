#ifndef __CARD_PROTOTYPE_H__
#define __CARD_PROTOTYPE_H__

#include "../../Card.h"

class CardPrototype : public Card{
	public:
		CardPrototype() : Card(){
		}

		CardPrototype(std::string name) : Card(name){
		}

		virtual CardPrototype* Clone(){
			return this;
		}
};

#endif //__CARD_PROTOTYPE_H__
