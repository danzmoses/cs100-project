#ifndef __INVENTORY_TESTS_H__
#define __INVENTORY_TESTS_H__

#include "gtest/gtest.h"
#include <stdexcept>
#include <string>
#include "Player.h"
#include "EnemyFactory.h"
#include "ArmorFactory.h"
#include "WeaponFactory.h"
#include "CardFactory.h"

TEST(InventoryTests, RemoveInvalidItemTest)
{
    Player* player = new Player("Player");
    ItemFactory* wf = new WeaponFactory();

    player->addArmorToInventory("Stone Sword", wf);

    EXPECT_THROW(
    try {
        player->getInventory().getItem("STONE sword item");
    }
    catch (std::invalid_argument& ia) {
        EXPECT_STREQ("Invalid argument. Unable to find item named \"STONE sword item\" inside of this inventory.", ia.what());
        throw;
    }, std::invalid_argument);
}

TEST(InventoryTests, GetInvalidItemTest)
{
    Player* player = new Player("Player");
    ItemFactory* af = new ArmorFactory();

    player->addArmorToInventory("Iron Armor", af);

    EXPECT_THROW(
    try {
        player->getInventory().getItem("invalid item");
    }
    catch (std::invalid_argument& ia) {
        EXPECT_STREQ("Invalid argument. Unable to find item named \"invalid item\" inside of this inventory.", ia.what());
        throw;
    }, std::invalid_argument);
}

TEST(InventoryTests, EquipInvalidArmorTest)
{
    Player* player = new Player("Player");
    ItemFactory* af = new ArmorFactory();

    player->addArmorToInventory("Leather Armor", af);

    EXPECT_THROW(
    try {
        player->equipArmor("LeAtHeR aRmOr");
    }
    catch (std::invalid_argument& ia) {
        EXPECT_STREQ("Invalid argument. Unable to find armor named \"LeAtHeR aRmOr\" inside of this inventory.", ia.what());
        throw;
    }, std::invalid_argument);
}

TEST(InventoryTests, EquipInvalidWeaponTest)
{
    Player* player = new Player("Player");
    ItemFactory* wf = new WeaponFactory();

    player->addWeaponToInventory("Wooden Sword", wf);

    EXPECT_THROW(
    try {
        player->equipWeapon("wOOdenSWORD");
    }
    catch (std::invalid_argument& ia) {
        EXPECT_STREQ("Invalid argument. Unable to find a weapon named \"wOOdenSWORD\" inside of this inventory.", ia.what());
        throw;
    }, std::invalid_argument);
}

TEST(InventoryTests, AddInvalidArmorTest)
{
    Player* player = new Player("Player");
    ItemFactory* af = new ArmorFactory();

    EXPECT_THROW(
    try {
        player->addArmorToInventory("LeAtHeR aRmOr", af);
    }
    catch (std::invalid_argument& ia) {
        EXPECT_STREQ("Invalid argument. Unable to find \"LeAtHeR aRmOr\"", ia.what());
        throw;
    }, std::invalid_argument);
}

TEST(InventoryTests, AddInvalidWeaponTest)
{
    Player* player = new Player("Player");
    ItemFactory* wf = new WeaponFactory();

    EXPECT_THROW(
    try {
        player->addWeaponToInventory("IronSWORD", wf);
    }
    catch (std::invalid_argument& ia) {
        EXPECT_STREQ("Invalid argument. Unable to find \"IronSWORD\"", ia.what());
        throw;
    }, std::invalid_argument);
}

TEST(InventoryTests, LeatherArmorTest)
{
    Player* player = new Player("Player");
    ItemFactory* af = new ArmorFactory();

    EXPECT_EQ(player->getInventory().getArmor().size(), 0);

    player->addArmorToInventory("Leather Armor", af);

    EXPECT_EQ(player->getInventory().getArmor().size(), 1);
    EXPECT_EQ(player->getInventory().getItem("Leather Armor")->getName(), "Leather Armor");
    EXPECT_EQ(player->getInventory().getItem("Leather Armor")->getCost(), 50);
    EXPECT_EQ(player->getInventory().getItem("Leather Armor")->baseStats->DEF, 1);
    // Check player's combat stats
    EXPECT_EQ(player->combatStats->ATK, 1);
    EXPECT_EQ(player->combatStats->DEF, 1);
    EXPECT_EQ(player->combatStats->HP, 5);
    EXPECT_EQ(player->combatStats->maxHP, 5);
    
    EXPECT_EQ(player->getEquipped().getArmor().size(), 0);

    player->equipArmor("Leather Armor");
    
    EXPECT_EQ(player->getEquipped().getArmor().size(), 1);
    EXPECT_EQ(player->getEquipped().getItem("Leather Armor")->getName(), "Leather Armor");
    EXPECT_EQ(player->getEquipped().getItem("Leather Armor")->getCost(), 50);
    EXPECT_EQ(player->getEquipped().getItem("Leather Armor")->baseStats->DEF, 1);
    // Check player's combat stats
    EXPECT_EQ(player->combatStats->ATK, 1);
    EXPECT_EQ(player->combatStats->DEF, 2);
    EXPECT_EQ(player->combatStats->HP, 5);
    EXPECT_EQ(player->combatStats->maxHP, 5);

    player->removeItemFromInventory("Leather Armor");

    EXPECT_EQ(player->getInventory().getArmor().size(), 0);
    EXPECT_EQ(player->getEquipped().getArmor().size(), 0);

    // Check player's combat stats
    EXPECT_EQ(player->combatStats->ATK, 1);
    EXPECT_EQ(player->combatStats->DEF, 1);
    EXPECT_EQ(player->combatStats->HP, 5);
    EXPECT_EQ(player->combatStats->maxHP, 5);
}

TEST(InventoryTests, IronArmorTest)
{
    Player* player = new Player("Player");
    ItemFactory* af = new ArmorFactory();

    EXPECT_EQ(player->getInventory().getArmor().size(), 0);

    player->addArmorToInventory("Iron Armor", af);

    EXPECT_EQ(player->getInventory().getArmor().size(), 1);
    EXPECT_EQ(player->getInventory().getItem("Iron Armor")->getName(), "Iron Armor");
    EXPECT_EQ(player->getInventory().getItem("Iron Armor")->getCost(), 450);
    EXPECT_EQ(player->getInventory().getItem("Iron Armor")->baseStats->DEF, 2);
    // Check player's combat stats
    EXPECT_EQ(player->combatStats->ATK, 1);
    EXPECT_EQ(player->combatStats->DEF, 1);
    EXPECT_EQ(player->combatStats->HP, 5);
    EXPECT_EQ(player->combatStats->maxHP, 5);
    
    EXPECT_EQ(player->getEquipped().getArmor().size(), 0);

    player->equipArmor("Iron Armor");
    
    EXPECT_EQ(player->getEquipped().getArmor().size(), 1);
    EXPECT_EQ(player->getEquipped().getItem("Iron Armor")->getName(), "Iron Armor");
    EXPECT_EQ(player->getEquipped().getItem("Iron Armor")->getCost(), 450);
    EXPECT_EQ(player->getEquipped().getItem("Iron Armor")->baseStats->DEF, 2);
    // Check player's combat stats
    EXPECT_EQ(player->combatStats->ATK, 1);
    EXPECT_EQ(player->combatStats->DEF, 3);
    EXPECT_EQ(player->combatStats->HP, 5);
    EXPECT_EQ(player->combatStats->maxHP, 5);

    player->removeItemFromInventory("Iron Armor");

    EXPECT_EQ(player->getInventory().getArmor().size(), 0);
    EXPECT_EQ(player->getEquipped().getArmor().size(), 0);
    // Check player's combat stats
    EXPECT_EQ(player->combatStats->ATK, 1);
    EXPECT_EQ(player->combatStats->DEF, 1);
    EXPECT_EQ(player->combatStats->HP, 5);
    EXPECT_EQ(player->combatStats->maxHP, 5);
}

TEST(InventoryTests, WoodenSwordTest)
{
    Player* player = new Player("Player");
    ItemFactory* wf = new WeaponFactory();

    EXPECT_EQ(player->getInventory().getWeapons().size(), 0);

    player->addWeaponToInventory("Wooden Sword", wf);

    EXPECT_EQ(player->getInventory().getWeapons().size(), 1);
    EXPECT_EQ(player->getInventory().getItem("Wooden Sword")->getName(), "Wooden Sword");
    EXPECT_EQ(player->getInventory().getItem("Wooden Sword")->getCost(), 25);
    EXPECT_EQ(player->getInventory().getItem("Wooden Sword")->baseStats->ATK, 1);
    // Check player's combat stats
    EXPECT_EQ(player->combatStats->ATK, 1);
    EXPECT_EQ(player->combatStats->DEF, 1);
    EXPECT_EQ(player->combatStats->HP, 5);
    EXPECT_EQ(player->combatStats->maxHP, 5);
    
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 0);

    player->equipWeapon("Wooden Sword");
    
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 1);
    EXPECT_EQ(player->getEquipped().getItem("Wooden Sword")->getName(), "Wooden Sword");
    EXPECT_EQ(player->getEquipped().getItem("Wooden Sword")->getCost(), 25);
    EXPECT_EQ(player->getEquipped().getItem("Wooden Sword")->baseStats->ATK, 1);
    // Check player's combat stats
    EXPECT_EQ(player->combatStats->ATK, 2);
    EXPECT_EQ(player->combatStats->DEF, 1);
    EXPECT_EQ(player->combatStats->HP, 5);
    EXPECT_EQ(player->combatStats->maxHP, 5);

    player->removeItemFromInventory("Wooden Sword");

    EXPECT_EQ(player->getInventory().getWeapons().size(), 0);
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 0);
    // Check player's combat stats
    EXPECT_EQ(player->combatStats->ATK, 1);
    EXPECT_EQ(player->combatStats->DEF, 1);
    EXPECT_EQ(player->combatStats->HP, 5);
    EXPECT_EQ(player->combatStats->maxHP, 5);
}

TEST(InventoryTests, StoneSwordTest)
{
    Player* player = new Player("Player");
    ItemFactory* wf = new WeaponFactory();

    EXPECT_EQ(player->getInventory().getWeapons().size(), 0);

    player->addWeaponToInventory("Stone Sword", wf);

    EXPECT_EQ(player->getInventory().getWeapons().size(), 1);
    EXPECT_EQ(player->getInventory().getItem("Stone Sword")->getName(), "Stone Sword");
    EXPECT_EQ(player->getInventory().getItem("Stone Sword")->getCost(), 100);
    EXPECT_EQ(player->getInventory().getItem("Stone Sword")->baseStats->ATK, 2);
    // Check player's combat stats
    EXPECT_EQ(player->combatStats->ATK, 1);
    EXPECT_EQ(player->combatStats->DEF, 1);
    EXPECT_EQ(player->combatStats->HP, 5);
    EXPECT_EQ(player->combatStats->maxHP, 5);
    
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 0);

    player->equipWeapon("Stone Sword");
    
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 1);
    EXPECT_EQ(player->getEquipped().getItem("Stone Sword")->getName(), "Stone Sword");
    EXPECT_EQ(player->getEquipped().getItem("Stone Sword")->getCost(), 100);
    EXPECT_EQ(player->getEquipped().getItem("Stone Sword")->baseStats->ATK, 2);
    // Check player's combat stats
    EXPECT_EQ(player->combatStats->ATK, 3);
    EXPECT_EQ(player->combatStats->DEF, 1);
    EXPECT_EQ(player->combatStats->HP, 5);
    EXPECT_EQ(player->combatStats->maxHP, 5);

    player->removeItemFromInventory("Stone Sword");

    EXPECT_EQ(player->getInventory().getWeapons().size(), 0);
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 0);
    // Check player's combat stats
    EXPECT_EQ(player->combatStats->ATK, 1);
    EXPECT_EQ(player->combatStats->DEF, 1);
    EXPECT_EQ(player->combatStats->HP, 5);
    EXPECT_EQ(player->combatStats->maxHP, 5);
}

TEST(InventoryTests, IronSwordTest)
{
    Player* player = new Player("Player");
    ItemFactory* wf = new WeaponFactory();

    EXPECT_EQ(player->getInventory().getWeapons().size(), 0);

    player->addWeaponToInventory("Iron Sword", wf);

    EXPECT_EQ(player->getInventory().getWeapons().size(), 1);
    EXPECT_EQ(player->getInventory().getItem("Iron Sword")->getName(), "Iron Sword");
    EXPECT_EQ(player->getInventory().getItem("Iron Sword")->getCost(), 500);
    EXPECT_EQ(player->getInventory().getItem("Iron Sword")->baseStats->ATK, 3);
    // Check player's combat stats
    EXPECT_EQ(player->combatStats->ATK, 1);
    EXPECT_EQ(player->combatStats->DEF, 1);
    EXPECT_EQ(player->combatStats->HP, 5);
    EXPECT_EQ(player->combatStats->maxHP, 5);
    
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 0);

    player->equipWeapon("Iron Sword");
    
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 1);
    EXPECT_EQ(player->getEquipped().getItem("Iron Sword")->getName(), "Iron Sword");
    EXPECT_EQ(player->getEquipped().getItem("Iron Sword")->getCost(), 500);
    EXPECT_EQ(player->getEquipped().getItem("Iron Sword")->baseStats->ATK, 3);
    // Check player's combat stats
    EXPECT_EQ(player->combatStats->ATK, 4);
    EXPECT_EQ(player->combatStats->DEF, 1);
    EXPECT_EQ(player->combatStats->HP, 5);
    EXPECT_EQ(player->combatStats->maxHP, 5);

    player->removeItemFromInventory("Iron Sword");

    EXPECT_EQ(player->getInventory().getWeapons().size(), 0);
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 0);
    // Check player's combat stats
    EXPECT_EQ(player->combatStats->ATK, 1);
    EXPECT_EQ(player->combatStats->DEF, 1);
    EXPECT_EQ(player->combatStats->HP, 5);
    EXPECT_EQ(player->combatStats->maxHP, 5);
}

TEST(InventoryTests, TwoArmorTest)
{
    Player* player = new Player("Player");
    ItemFactory* af = new ArmorFactory();

    EXPECT_EQ(player->getInventory().getArmor().size(), 0);

    player->addArmorToInventory("Leather Armor", af);

    EXPECT_EQ(player->getInventory().getArmor().size(), 1);
    EXPECT_EQ(player->getInventory().getItem("Leather Armor")->getName(), "Leather Armor");
    EXPECT_EQ(player->getInventory().getItem("Leather Armor")->getCost(), 50);
    EXPECT_EQ(player->getInventory().getItem("Leather Armor")->baseStats->DEF, 1);
    
    EXPECT_EQ(player->getEquipped().getArmor().size(), 0);

    player->equipArmor("Leather Armor");
    
    EXPECT_EQ(player->getEquipped().getArmor().size(), 1);
    EXPECT_EQ(player->getEquipped().getItem("Leather Armor")->getName(), "Leather Armor");
    EXPECT_EQ(player->getEquipped().getItem("Leather Armor")->getCost(), 50);
    EXPECT_EQ(player->getEquipped().getItem("Leather Armor")->baseStats->DEF, 1);

    player->addArmorToInventory("Iron Armor", af);

    EXPECT_EQ(player->getInventory().getArmor().size(), 2);
    EXPECT_EQ(player->getInventory().getItem("Iron Armor")->getName(), "Iron Armor");
    EXPECT_EQ(player->getInventory().getItem("Iron Armor")->getCost(), 450);
    EXPECT_EQ(player->getInventory().getItem("Iron Armor")->baseStats->DEF, 2);
    
    EXPECT_EQ(player->getEquipped().getArmor().size(), 1);

    player->equipArmor("Iron Armor");
    
    EXPECT_EQ(player->getEquipped().getArmor().size(), 1);
    EXPECT_EQ(player->getEquipped().getItem("Iron Armor")->getName(), "Iron Armor");
    EXPECT_EQ(player->getEquipped().getItem("Iron Armor")->getCost(), 450);
    EXPECT_EQ(player->getEquipped().getItem("Iron Armor")->baseStats->DEF, 2);

    player->removeItemFromInventory("Leather Armor");

    EXPECT_EQ(player->getInventory().getArmor().size(), 1);
    EXPECT_EQ(player->getEquipped().getArmor().size(), 1);

    player->removeItemFromInventory("Iron Armor");

    EXPECT_EQ(player->getInventory().getArmor().size(), 0);
    EXPECT_EQ(player->getEquipped().getArmor().size(), 0);
}


TEST(InventoryTests, TripleWeaponTest)
{
    Player* player = new Player("Player");
    ItemFactory* wf = new WeaponFactory();

    EXPECT_EQ(player->getInventory().getWeapons().size(), 0);

    player->addWeaponToInventory("Wooden Sword", wf);

    EXPECT_EQ(player->getInventory().getWeapons().size(), 1);
    EXPECT_EQ(player->getInventory().getItem("Wooden Sword")->getName(), "Wooden Sword");
    EXPECT_EQ(player->getInventory().getItem("Wooden Sword")->getCost(), 25);
    EXPECT_EQ(player->getInventory().getItem("Wooden Sword")->baseStats->ATK, 1);
    
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 0);

    player->equipWeapon("Wooden Sword");
    
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 1);
    EXPECT_EQ(player->getEquipped().getItem("Wooden Sword")->getName(), "Wooden Sword");
    EXPECT_EQ(player->getEquipped().getItem("Wooden Sword")->getCost(), 25);
    EXPECT_EQ(player->getEquipped().getItem("Wooden Sword")->baseStats->ATK, 1);

    player->addWeaponToInventory("Stone Sword", wf);

    EXPECT_EQ(player->getInventory().getWeapons().size(), 2);
    EXPECT_EQ(player->getInventory().getItem("Stone Sword")->getName(), "Stone Sword");
    EXPECT_EQ(player->getInventory().getItem("Stone Sword")->getCost(), 100);
    EXPECT_EQ(player->getInventory().getItem("Stone Sword")->baseStats->ATK, 2);
    
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 1);

    player->equipWeapon("Stone Sword");
    
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 1);
    EXPECT_EQ(player->getEquipped().getItem("Stone Sword")->getName(), "Stone Sword");
    EXPECT_EQ(player->getEquipped().getItem("Stone Sword")->getCost(), 100);
    EXPECT_EQ(player->getEquipped().getItem("Stone Sword")->baseStats->ATK, 2);

    player->addWeaponToInventory("Iron Sword", wf);

    EXPECT_EQ(player->getInventory().getWeapons().size(), 3);
    EXPECT_EQ(player->getInventory().getItem("Iron Sword")->getName(), "Iron Sword");
    EXPECT_EQ(player->getInventory().getItem("Iron Sword")->getCost(), 500);
    EXPECT_EQ(player->getInventory().getItem("Iron Sword")->baseStats->ATK, 3);
    
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 1);

    player->equipWeapon("Iron Sword");
    
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 1);
    EXPECT_EQ(player->getEquipped().getItem("Iron Sword")->getName(), "Iron Sword");
    EXPECT_EQ(player->getEquipped().getItem("Iron Sword")->getCost(), 500);
    EXPECT_EQ(player->getEquipped().getItem("Iron Sword")->baseStats->ATK, 3);

    /////////////
    
    player->removeItemFromInventory("Iron Sword"); // Remove Iron Sword (currently equipped) so that getEquipped().getWeapons.size() == 0 (diff. from TwoArmorTest)
    EXPECT_EQ(player->getInventory().getWeapons().size(), 2);
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 0);

    player->removeItemFromInventory("Wooden Sword");
    EXPECT_EQ(player->getInventory().getWeapons().size(), 1);
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 0);
   
    player->removeItemFromInventory("Stone Sword");
    EXPECT_EQ(player->getInventory().getWeapons().size(), 0);
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 0);
}

TEST(InventoryTests, OverloadedCardsTest)
{
    Player* player = new Player("Player");
    CardFactory* cf = new CardFactory();

    EXPECT_EQ(player->getInventory().getCards().size(), 0);

    // Add "Deal Damage" card

    player->addCardToInventory("Deal Damage", cf);
    EXPECT_EQ(player->getInventory().getCards().size(), 1);
    EXPECT_EQ(player->getInventory().getCard("Deal Damage")->getName(), "Deal Damage");
    EXPECT_EQ(player->getInventory().getCard("Deal Damage")->getCost(), 85);
    
    EXPECT_EQ(player->getEquipped().getCards().size(), 0);

    player->equipCard("Deal Damage");
    EXPECT_EQ(player->getEquipped().getCards().size(), 1);
    EXPECT_EQ(player->getEquipped().getCard("Deal Damage")->getName(), "Deal Damage");
    EXPECT_EQ(player->getEquipped().getCard("Deal Damage")->getCost(), 85);

    // Add "Enhance ATK" card

    player->addCardToInventory("Enhance ATK", cf);
    EXPECT_EQ(player->getInventory().getCards().size(), 2);
    EXPECT_EQ(player->getInventory().getCard("Enhance ATK")->getName(), "Enhance ATK");
    EXPECT_EQ(player->getInventory().getCard("Enhance ATK")->getCost(), 75);
    
    EXPECT_EQ(player->getEquipped().getCards().size(), 1);

    player->equipCard("Enhance ATK");
    EXPECT_EQ(player->getEquipped().getCards().size(), 2);
    EXPECT_EQ(player->getEquipped().getCard("Enhance ATK")->getName(), "Enhance ATK");
    EXPECT_EQ(player->getEquipped().getCard("Enhance ATK")->getCost(), 75);

    // Add "Enhance DEF" card

    player->addCardToInventory("Enhance DEF", cf);
    EXPECT_EQ(player->getInventory().getCards().size(), 3);
    EXPECT_EQ(player->getInventory().getCard("Enhance DEF")->getName(), "Enhance DEF");
    EXPECT_EQ(player->getInventory().getCard("Enhance DEF")->getCost(), 75);
    
    EXPECT_EQ(player->getEquipped().getCards().size(), 2);

    player->equipCard("Enhance DEF");
    EXPECT_EQ(player->getEquipped().getCards().size(), 3);
    EXPECT_EQ(player->getEquipped().getCard("Enhance DEF")->getName(), "Enhance DEF");
    EXPECT_EQ(player->getEquipped().getCard("Enhance DEF")->getCost(), 75);

    // Add "Small Heal" card

    player->addCardToInventory("Small Heal", cf);
    EXPECT_EQ(player->getInventory().getCards().size(), 4);
    EXPECT_EQ(player->getInventory().getCard("Small Heal")->getName(), "Small Heal");
    EXPECT_EQ(player->getInventory().getCard("Small Heal")->getCost(), 65);
    
    EXPECT_EQ(player->getEquipped().getCards().size(), 3);

    player->equipCard("Small Heal");
    EXPECT_EQ(player->getEquipped().getCards().size(), 4);
    EXPECT_EQ(player->getEquipped().getCard("Small Heal")->getName(), "Small Heal");
    EXPECT_EQ(player->getEquipped().getCard("Small Heal")->getCost(), 65);

    // Add ANOTHER "Small Heal" card
    // N: Expect throw if the user tries to EQUIP the card when they already have 4 cards equipped.

    player->addCardToInventory("Big Heal", cf);
    EXPECT_EQ(player->getInventory().getCards().size(), 5);
    EXPECT_EQ(player->getInventory().getCard("Big Heal")->getName(), "Big Heal");
    EXPECT_EQ(player->getInventory().getCard("Big Heal")->getCost(), 75);
    
    EXPECT_EQ(player->getEquipped().getCards().size(), 4);

    EXPECT_THROW(
    try {
        player->equipCard("Big Heal");
    }
    catch (std::invalid_argument& ia) {
        EXPECT_STREQ("Invalid argument. This inventory already has the max number of Cards (4).", ia.what());
        throw;
    }, std::invalid_argument);

    EXPECT_THROW(
    try {
        player->equipCard("Small Heal");
    }
    catch (std::invalid_argument& ia) {
        EXPECT_STREQ("Invalid argument. This card is already equipped.", ia.what());
        throw;
    }, std::invalid_argument);
}

TEST(InventoryTests, EquipCardTwice)
{
    Player* player = new Player("Player");
    CardFactory* cf = new CardFactory();

    // Add "Deal Damage" card

    player->addCardToInventory("Deal Damage", cf);
    EXPECT_EQ(player->getInventory().getCards().size(), 1);
    EXPECT_EQ(player->getInventory().getCard("Deal Damage")->getName(), "Deal Damage");
    EXPECT_EQ(player->getInventory().getCard("Deal Damage")->getCost(), 85);
    
    EXPECT_EQ(player->getEquipped().getCards().size(), 0);

    player->equipCard("Deal Damage");
    EXPECT_EQ(player->getEquipped().getCards().size(), 1);
    EXPECT_EQ(player->getEquipped().getCard("Deal Damage")->getName(), "Deal Damage");
    EXPECT_EQ(player->getEquipped().getCard("Deal Damage")->getCost(), 85);

    // Attempt to equip "Deal Damage" card again.

    EXPECT_THROW(
    try {
        player->equipCard("Deal Damage");
    }
    catch (std::invalid_argument& ia) {
        EXPECT_STREQ("Invalid argument. This card is already equipped.", ia.what());
        throw;
    }, std::invalid_argument);

}

TEST(InventoryTests, EquipWeaponTwice)
{
    Player* player = new Player("Player");
    ItemFactory* wf = new WeaponFactory();

    // Add Wooden Sword

    player->addWeaponToInventory("Wooden Sword", wf);
    EXPECT_EQ(player->getInventory().getWeapons().size(), 1);
    EXPECT_EQ(player->getInventory().getItem("Wooden Sword")->getName(), "Wooden Sword");
    EXPECT_EQ(player->getInventory().getItem("Wooden Sword")->getCost(), 25);
    
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 0);

    player->equipWeapon("Wooden Sword");
    EXPECT_EQ(player->getEquipped().getWeapons().size(), 1);
    EXPECT_EQ(player->getEquipped().getItem("Wooden Sword")->getName(), "Wooden Sword");
    EXPECT_EQ(player->getEquipped().getItem("Wooden Sword")->getCost(), 25);

    // Attempt to equip Wooden Sword again.

    EXPECT_THROW(
    try {
        player->equipWeapon("Wooden Sword");
    }
    catch (std::invalid_argument& ia) {
        EXPECT_STREQ("Invalid argument. This item is already equipped.", ia.what());
        throw;
    }, std::invalid_argument);

}

TEST(InventoryTests, EquipArmorTwice)
{
    Player* player = new Player("Player");
    ItemFactory* af = new ArmorFactory();

    // Add Leather Armor

    player->addArmorToInventory("Leather Armor", af);
    EXPECT_EQ(player->getInventory().getArmor().size(), 1);
    EXPECT_EQ(player->getInventory().getItem("Leather Armor")->getName(), "Leather Armor");
    EXPECT_EQ(player->getInventory().getItem("Leather Armor")->getCost(), 50);
    
    EXPECT_EQ(player->getEquipped().getArmor().size(), 0);

    player->equipArmor("Leather Armor");
    EXPECT_EQ(player->getEquipped().getArmor().size(), 1);
    EXPECT_EQ(player->getEquipped().getItem("Leather Armor")->getName(), "Leather Armor");
    EXPECT_EQ(player->getEquipped().getItem("Leather Armor")->getCost(), 50);

    // Attempt to equip Leather Armor again.

    EXPECT_THROW(
    try {
        player->equipArmor("Leather Armor");
    }
    catch (std::invalid_argument& ia) {
        EXPECT_STREQ("Invalid argument. This item is already equipped.", ia.what());
        throw;
    }, std::invalid_argument);

}

#endif // __INVENTORY_TESTS_H__