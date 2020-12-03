#ifndef __PROTOTYPE_TESTS_H__
#define __PROTOTYPE_TESTS_H__

#include "gtest/gtest.h"
#include "../Player.h"
#include "../EnemyFactory.h"
#include "../ArmorFactory.h"
#include "../WeaponFactory.h"

TEST(PrototypeTests, IronArmorPrototypeTest)
{
    ItemFactory* af = new ArmorFactory();
    Item* armor = af->createItem("Iron Armor");


    EXPECT_EQ(armor->baseStats->ATK, 0);
    EXPECT_EQ(armor->baseStats->DEF, 2);
    EXPECT_EQ(armor->baseStats->HP, 0);
    EXPECT_EQ(armor->baseStats->maxHP, 0);
    EXPECT_EQ(armor->combatStats->ATK, 0);
    EXPECT_EQ(armor->combatStats->DEF, 2);
    EXPECT_EQ(armor->combatStats->HP, 0);
    EXPECT_EQ(armor->combatStats->maxHP, 0);
    
    EXPECT_EQ(armor->getCost(), 450);
    EXPECT_EQ(armor->getName(), "Iron Armor");

    armor->setCost(9999);
    armor->setName("Super cool Iron Armor");

    EXPECT_EQ(armor->getCost(), 9999);
    EXPECT_EQ(armor->getName(), "Super cool Iron Armor");
    
}

TEST(PrototypeTests, LeatherArmorPrototypeTest)
{
    ItemFactory* af = new ArmorFactory();
    Item* armor = af->createItem("Leather Armor");


    EXPECT_EQ(armor->baseStats->ATK, 0);
    EXPECT_EQ(armor->baseStats->DEF, 1);
    EXPECT_EQ(armor->baseStats->HP, 0);
    EXPECT_EQ(armor->baseStats->maxHP, 0);
    EXPECT_EQ(armor->combatStats->ATK, 0);
    EXPECT_EQ(armor->combatStats->DEF, 1);
    EXPECT_EQ(armor->combatStats->HP, 0);
    EXPECT_EQ(armor->combatStats->maxHP, 0);
    
    EXPECT_EQ(armor->getCost(), 50);
    EXPECT_EQ(armor->getName(), "Leather Armor");

    armor->setCost(9999);
    armor->setName("Super cool Leather Armor");

    EXPECT_EQ(armor->getCost(), 9999);
    EXPECT_EQ(armor->getName(), "Super cool Leather Armor");
    
}

#endif // __PROTOTYPE_TESTS_H__