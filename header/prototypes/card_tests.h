#ifndef __CARD_TESTS_H__
#define __CARD_TESTS_H__

#include "gtest/gtest.h"
#include <stdexcept>
#include "../CardFactory.h"

TEST(CardPrototypeTest, SmallHealPrototype){
	CardFactory *cf = new CardFactory();
	Card *c = cf->createCard("Small Heal");

	EXPECT_EQ(c->getName(), "Small Heal");
	EXPECT_EQ(c->getCost(), 65);
	EXPECT_EQ(c->getDescription(), "This card raises HP by 40% the user's current HP"); 

	c->setName("New card name");
	c->setCost(165);
	c->setDescription("New card description");

	EXPECT_EQ(c->getName(), "New card name");
	EXPECT_EQ(c->getCost(), 165);
	EXPECT_EQ(c->getDescription(), "New card description"); 			
}

TEST(CardPrototypeTest, DealDamagePrototype){
	CardFactory *cf = new CardFactory();
	Card *c = cf->createCard("Deal Damage");

	EXPECT_EQ(c->getName(), "Deal Damage");
	EXPECT_EQ(c->getCost(), 85);
	EXPECT_EQ(c->getDescription(), "This card decreases the enemy's HP by 1");

	c->setName("New card name");
	c->setCost(185);
	c->setDescription("New card description");

	EXPECT_EQ(c->getName(), "New card name");
	EXPECT_EQ(c->getCost(), 185);
	EXPECT_EQ(c->getDescription(), "New card description");
}

TEST(CardPrototypeTest, EnhanceATKPrototype){
	CardFactory *cf = new CardFactory();
	Card *c = cf->createCard("Enhance ATK");

	EXPECT_EQ(c->getName(), "Enhance ATK");
	EXPECT_EQ(c->getCost(), 75);
	EXPECT_EQ(c->getDescription(), "This card enhances ATK by 1");

	c->setName("New card name");
	c->setCost(175);
	c->setDescription("New card description");

	EXPECT_EQ(c->getName(), "New card name");
	EXPECT_EQ(c->getCost(), 175);
	EXPECT_EQ(c->getDescription(), "New card description");
}

TEST(CardPrototypeTest, EnhanceDEFPrototype){
	CardFactory *cf = new CardFactory();
	Card *c = cf->createCard("Enhance DEF");

	EXPECT_EQ(c->getName(), "Enhance DEF");
	EXPECT_EQ(c->getCost(), 75);
	EXPECT_EQ(c->getDescription(), "This card enhances DEF by 1");

	c->setName("New card name");
	c->setCost(175);
	c->setDescription("New card description");

	EXPECT_EQ(c->getName(), "New card name");
	EXPECT_EQ(c->getCost(), 175);
	EXPECT_EQ(c->getDescription(), "New card description");
}

TEST(CardPrototypeTest, InvalidName){
	CardFactory *cf = new CardFactory();

	EXPECT_THROW(
        try {
            cf->createCard("small damage");
        }
        catch (std::invalid_argument& ia) {
            EXPECT_STREQ("Invalid argument. Couldn't find \"small damage\"", ia.what());
            throw;
        }, std::invalid_argument);	
}

#endif //__CARD_TESTS_H__
