#ifndef __ENTITY_TESTS__
#define __ENTITY_TESTS__

#include "gtest/gtest.h"
#include "header/Player.h"
#include "header/EnemyFactory.h"

TEST(PlayerTests, DefaultConstructorTest)
{
    Player* player = new Player();

    EXPECT_EQ(player->getATK(), 1);
    EXPECT_EQ(player->getDEF(), 1);
    EXPECT_EQ(player->getEXP(), 0);
    EXPECT_EQ(player->getGold(), 50);
    EXPECT_EQ(player->getHP(), 10);
    EXPECT_EQ(player->getLevel(), 1);
    EXPECT_EQ(player->getMaxHP(), 10);
    EXPECT_EQ(player->getName(), "Entity");
}

TEST(PlayerTests, NameConstructorTest)
{
    Player* player = new Player("Bob");

    EXPECT_EQ(player->getATK(), 1);
    EXPECT_EQ(player->getDEF(), 1);
    EXPECT_EQ(player->getEXP(), 0);
    EXPECT_EQ(player->getGold(), 50);
    EXPECT_EQ(player->getHP(), 10);
    EXPECT_EQ(player->getLevel(), 1);
    EXPECT_EQ(player->getMaxHP(), 10);
    EXPECT_EQ(player->getName(), "Bob");
}


TEST(PlayerTests, setATKTest)
{
    Player* player = new Player();

    EXPECT_EQ(player->getATK(), 1);
    player->setATK(2);
    EXPECT_EQ(player->getATK(), 2);
    player->setATK(-2);
    EXPECT_EQ(player->getATK(), -2);
}


TEST(PlayerTests, setDEFTest)
{
    Player* player = new Player();

    EXPECT_EQ(player->getDEF(), 1);
    player->setDEF(2);
    EXPECT_EQ(player->getDEF(), 2);
    player->setDEF(-2);
    EXPECT_EQ(player->getDEF(), -2);
}

TEST(PlayerTests, setEXPTest)
{
    Player* player = new Player();

    EXPECT_EQ(player->getEXP(), 0);
    player->setEXP(2);
    EXPECT_EQ(player->getEXP(), 2);
    
    EXPECT_THROW(
        try 
        {
            player->setEXP(-1);    
        }
        catch (std::invalid_argument& ia)
        {
            EXPECT_STREQ(ia.what(), "Invalid argument. EXP cannot be negative.");
            throw;
        }
        , std::invalid_argument);
}


#endif // __ENTITY_TESTS__