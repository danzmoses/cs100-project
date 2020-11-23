#ifndef __ENTITY_TEST_H__
#define __ENTITY_TEST_H__

#include "gtest/gtest.h"

#include "Player.h"
#include "EnemyFactory.h"

TEST(PlayerTests, DefaultConstructorTest){
	Player *p = new Player();
	EXPECT_EQ(p->getHP(), 10);
	EXPECT_EQ(p->getMaxHP(), 10);
	EXPECT_EQ(p->getATK(), 1);
	EXPECT_EQ(p->getDEF(), 1);		

	EXPECT_EQ(p->getGold(), 50);
	EXPECT_EQ(p->getLevel(), 1);
	EXPECT_EQ(p->getEXP(), 0);

	p->setName("newName");
	p->setHP(5);
	p->setMaxHP(9);
	p->setATK(3);
	p->setDEF(3);
	p->setGold(100);
	p->setLevel(2);
	p->setEXP(2);

	EXPECT_EQ(p->getName(), "newName");	
       	EXPECT_EQ(p->getHP(), 5);
	EXPECT_EQ(p->getMaxHP(), 9);
        EXPECT_EQ(p->getATK(), 3);
        EXPECT_EQ(p->getDEF(), 3);

        EXPECT_EQ(p->getGold(), 100);
        EXPECT_EQ(p->getLevel(), 2);
	EXPECT_EQ(p->getEXP(), 2);

	p->restoreHP();
	EXPECT_EQ(p->getHP(), 9); //maxHP is no longer 10 because it was set to 9 when setMaxHP() was tested above
}

//TEST(PlayerTests, nameConstructorTest){
//}

#endif //__ENTITY_TEST_H__
