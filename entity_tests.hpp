#ifndef __ENTITY_TESTS__
#define __ENTITY_TESTS__

#include "gtest/gtest.h"
#include "header/Player.h"
#include "header/EnemyFactory.h"

TEST(PlayerTests, DefaultConstructorTest)
{
    Player* player = new Player();

    EXPECT_EQ(player->getHP(), 10);
}

#endif // __ENTITY_TESTS__