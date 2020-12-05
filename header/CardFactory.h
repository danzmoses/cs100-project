#ifndef __CARD_FACTORY_H__
#define __CARD_FACTORY_H__

#include "Card.h"
//#include "prototypes/cards/EnhanceATKPrototype.h"
//#include "prototypes/cards/EnhanceDEFPrototype.h"
//#include "prototypes/cards/SmallHealPrototype.h"
#include <vector>
#include <stdexcept>

class CardFactory{
	private:
		std::vector<CardPrototype*> cardPrototypes;
	public:
		CardFactory(){
			this->cardPrototypes.push_back(new EnhanceATKPrototype());
			this->cardPrototypes.push_back(new EnhanceDEFPrototype());
			this->cardPrototypes.push_back(new SmallHealPrototype()); 
		}

		CardPrototype* createCard(std::string name){
			
		}
};

#endif //__CARD_FACTORY_H__
