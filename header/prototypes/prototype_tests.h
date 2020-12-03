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
    Item* ironArmor = af->createItem("Iron Armor");


    EXPECT_EQ(ironArmor->baseStats->ATK, 0);
    EXPECT_EQ(ironArmor->baseStats->DEF, 2);
    EXPECT_EQ(ironArmor->baseStats->HP, 0);
    EXPECT_EQ(ironArmor->baseStats->maxHP, 0);
    EXPECT_EQ(ironArmor->combatStats->ATK, 0);
    EXPECT_EQ(ironArmor->combatStats->DEF, 2);
    EXPECT_EQ(ironArmor->combatStats->HP, 0);
    EXPECT_EQ(ironArmor->combatStats->maxHP, 0);
    
    EXPECT_EQ(ironArmor->getCost(), 450);
    EXPECT_EQ(ironArmor->getName(), "Iron Armor");

    ironArmor->setCost(9999);
    ironArmor->setName("Super cool Iron Armor");

    EXPECT_EQ(ironArmor->getCost(), 9999);
    EXPECT_EQ(ironArmor->getName(), "Super cool Iron Armor");
    
}

#endif // __PROTOTYPE_TESTS_H__