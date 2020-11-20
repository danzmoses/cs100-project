#ifndef __ENTITY_TEST_H__
#define __ENTITY_TEST_H__

#include "gtest/gtest.h"

#include "Entity.h"

TEST(EntityTest, LevelTest){
	Entity* e = new Entity("name");
	EXPECT_EQ(e->getLevel(), 1);
	e->setLevel(5);
	EXPECT_EQ(e->getLevel(), 5);
}

TEST(EntityTest, HealthTest){
	Entity* e = new Entity("name");
	EXPECT_EQ(e->getHealth(), 5);
	e->setHealth(3);
	EXPECT_EQ(e->getHealth(), 3);
}

TEST(EntityTest, ExpTest){
	Entity* e = new Entity("name");
	EXPECT_EQ(e->getExp(), 0);
	e->setExp(2);
	EXPECT_EQ(e->getExp(), 2);
}

TEST(EntityTest, NameTest){
	Entity* e = new Entity("name");
	EXPECT_EQ(e->getName(), "name");
	e->setName("newName");
	EXPECT_EQ(e->getName(), "newName");
}

TEST(EntityTest, ATKTest){
	Entity* e = new Entity("name");
	EXPECT_EQ(e->getATK(), 1);
	e->setATK(3);
	EXPECT_EQ(e->getATK(), 3);
}

TEST(EntityTest, DEFTest){
	Entity* e = new Entity("name");
	EXPECT_EQ(e->getDEF(), 1);
	e->setDEF(3);
	EXPECT_EQ(e->getDEF(), 3);
}

#endif //__ENTITY_TEST_H__
