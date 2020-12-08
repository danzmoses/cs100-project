#ifndef __BIG_HEAL_PROTOTYPE_H__
#define __BIG_HEAL_PROTOTYPE_H__

#include "CardPrototype.h"

class BigHealPrototype : public CardPrototype{
        public:
                BigHealPrototype() : CardPrototype(){
                        this->setName("Big Heal");
                        this->setCost(75);
                        this->setDescription("This card raises the card user's HP by 60% their current HP (rounded to the nearest whole number)");
                }

                BigHealPrototype(std::string name) : CardPrototype(name){
                        this->setCost(75);
                        this->setDescription("This card raises the card user's HP by 60% their current HP (rounded to the nearest whole number)");
                }

                virtual CardPrototype* Clone(){
                        return new BigHealPrototype();
                }
};

#endif //__BIG_HEAL_PROTOTYPES_H__
