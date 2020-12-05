#ifndef __CARD_TESTS_H__
#define __CARD_TESTS_H__

#include "gtest/gtest.h"
#include <stdexcept>
#include "../CardFactory.h"

TEST(CardPrototypeTest, SmallHealPrototype){
	CardFactory *cf = new CardFactory();
	Card* c = cf->createCard("Small Heal");

	EXPECT_EQ(c->getName(), "Small Heal");
	EXPECT_EQ(c->getCost(), 65);
	EXPECT_EQ(c->getDescription(), "This card raises HP by 2"); 

	c->setName("New card name");
	c->setCost(165);
	c->setDescription("New card description");

	EXPECT_EQ(c->getName(), "New card name");
	EXPECT_EQ(c->getCost(), 165);
	EXPECT_EQ(c->getDescription(), "New card description"); 			
}


#endif //__CARD_TESTS_H__
