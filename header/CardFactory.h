#ifndef __CARD_FACTORY_H__
#define __CARD_FACTORY_H__

#include "Card.h"
#include "prototypes/cards/EnhanceATKPrototype.h"
#include "prototypes/cards/EnhanceDEFPrototype.h"
#include "prototypes/cards/SmallHealPrototype.h"
#include "prototypes/cards/BigHealPrototype.h"
#include "prototypes/cards/DealDamagePrototype.h"
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
			this->cardPrototypes.push_back(new BigHealPrototype());
			this->cardPrototypes.push_back(new DealDamagePrototype());
		}

		Card* createCard(std::string name){
			for(int i = 0; i < cardPrototypes.size(); i++){
				if(cardPrototypes.at(i)->getName() == name){
					return cardPrototypes.at(i)->Clone();
				}
			}
			std::invalid_argument ia("Invalid argument. Couldn't find \"" + name + '\"' );
			throw ia;	
		}

        std::vector<Card*> getPrototypes()
        {
            std::vector<Card*> cards;
            for (int i = 0; i < cardPrototypes.size(); ++i)
                cards.push_back(cardPrototypes.at(i));
            return cards;
        }
};

#endif //__CARD_FACTORY_H__
