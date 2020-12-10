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
 	EXPECT_EQ(a->combatStats->ATK, 0);
 	EXPECT_EQ(a->combatStats->DEF, 1);

 	a->setName("New Leather Armor");
 	a->setCost(200);
 	a->combatStats->ATK = 2;
 	a->combatStats->DEF = 200;
	
 	EXPECT_EQ(a->getName(), "New Leather Armor");
 	EXPECT_EQ(a->getCost(), 200);
 	EXPECT_EQ(a->combatStats->ATK, 2);
 	EXPECT_EQ(a->combatStats->DEF, 200);
}

TEST(ItemTests, IronArmorTest){
 	ItemFactory *AF = new ArmorFactory();
 	Item *a = AF->createItem("Iron Armor");
	
 	EXPECT_EQ(a->getName(), "Iron Armor");
 	EXPECT_EQ(a->getCost(), 450);
 	EXPECT_EQ(a->combatStats->ATK, 0);
 	EXPECT_EQ(a->combatStats->DEF, 2);

 	a->setName("New Iron Armor");
 	a->setCost(1000);
 	a->combatStats->ATK = 5;
 	a->combatStats->DEF = 500;
	
 	EXPECT_EQ(a->getName(), "New Iron Armor");
 	EXPECT_EQ(a->getCost(), 1000);
 	EXPECT_EQ(a->combatStats->ATK, 5);
 	EXPECT_EQ(a->combatStats->DEF, 500);
}

TEST(ItemTests, WoodenSwordWeaponTest){
 	ItemFactory *WF = new WeaponFactory();
 	Item *w = WF->createItem("Wooden Sword");
	
 	EXPECT_EQ(w->getName(), "Wooden Sword");
 	EXPECT_EQ(w->getCost(), 25);
 	EXPECT_EQ(w->combatStats->ATK, 1);
 	EXPECT_EQ(w->combatStats->DEF, 0);

 	w->setName("New Wooden Sword");
 	w->setCost(50);
 	w->combatStats->ATK = 10;
 	w->combatStats->DEF = 2;

 	EXPECT_EQ(w->getName(), "New Wooden Sword");
 	EXPECT_EQ(w->getCost(), 50);
 	EXPECT_EQ(w->combatStats->ATK, 10);
 	EXPECT_EQ(w->combatStats->DEF, 2);
}

TEST(ItemTests, StoneSwordWeaponTest){
 	ItemFactory *WF = new WeaponFactory();
 	Item *w = WF->createItem("Stone Sword");
	
 	EXPECT_EQ(w->getName(), "Stone Sword");
 	EXPECT_EQ(w->getCost(), 100); 
 	EXPECT_EQ(w->combatStats->ATK, 2);
 	EXPECT_EQ(w->combatStats->DEF, 0);

 	w->setName("New Stone Sword");
 	w->setCost(200);
 	w->combatStats->ATK = 15;
 	w->combatStats->DEF = 3;

 	EXPECT_EQ(w->getName(), "New Stone Sword");
 	EXPECT_EQ(w->getCost(), 200);
 	EXPECT_EQ(w->combatStats->ATK, 15);
 	EXPECT_EQ(w->combatStats->DEF, 3);
}

#endif //__ITEM_TEST_H
