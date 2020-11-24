#ifndef __ITEM_TEST_H__
#define __ITEM_TEST_H__

#include "gtest/gtest.h"
#include "Item.h"
#include "WeaponFactory.h"
#include "ArmorFactory.h"

TEST(ItemTests, LeatherArmorTest){
	ItemFactory *AF = new ArmorFactory();
	Item *a = AF->createItem("Leather Armor");

	EXPECT_EQ(a->getName(), "Leather Armor");
	EXPECT_EQ(a->getCost(), 50); 
	EXPECT_EQ(a->getATK(), 0);
	EXPECT_EQ(a->getDEF(), 0);

	a->setName("New Leather Armor");
	a->setCost(200);
	a->setATK(2);
	a->setDEF(200);
	
	EXPECT_EQ(a->getName(), "New Leather Armor");
	EXPECT_EQ(a->getCost(), 200);
	EXPECT_EQ(a->getATK(), 2);
	EXPECT_EQ(a->getDEF(), 200);
}

TEST(ItemTests, IronArmorTest){
	ItemFactory *AF = new ArmorFactory();
	Item *a = AF->createItem("Iron Armor");
	
	EXPECT_EQ(a->getName(), "Iron Armor");
	EXPECT_EQ(a->getCost(), 450);
	EXPECT_EQ(a->getATK(), 0);
	EXPECT_EQ(a->getDEF(), 0);

	a->setName("New Iron Armor");
	a->setCost(1000);
	a->setATK(5);
	a->setDEF(500);
	
	EXPECT_EQ(a->getName(), "New Iron Armor");
	EXPECT_EQ(a->getCost(), 1000);
	EXPECT_EQ(a->getATK(), 5);
	EXPECT_EQ(a->getDEF(), 500)
}

TEST(ItemTests, WoodenSwordWeaponTest){
	ItemFactory *WF = new WeaponFactory();
	Item *w = WF->createItem("Wooden Sword");
	
	EXPECT_EQ(w->getName(), "Wooden Sword");
	EXPECT_EQ(w->getCost(), 25);
	EXPECT_EQ(w->getATK(), 0);
	EXPECT_EQ(w->getDEF(), 0);

	w->setName("New Wooden Sword");
	w->setCost(50);
	w->setATK(10);
	w->setDEF(2);

	EXPECT_EQ(w->getName(), "New Wooden Sword");
	EXPECT_EQ(w->getCost(), 50);
	EXPECT_EQ(w->getATK(), 10);
	EXPECT_EQ(w->getDEF(), 2);
}



#endif //__ITEM_TEST_H
