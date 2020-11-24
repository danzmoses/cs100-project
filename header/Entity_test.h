#ifndef __ENTITY_TEST_H__
#define __ENTITY_TEST_H__

#include "gtest/gtest.h"

#include "Player.h"
#include "EnemyFactory.h"
#include "Item.h"
#include "ArmorFactory.h"
#include "WeaponFactory.h" 

TEST(PlayerTests, DefaultConstructorTest){
	//testing default constructor
	Player *p = new Player();
	
	//inherited Entity member variables
	//testing getters
	EXPECT_EQ(p->getHP(), 10);
	EXPECT_EQ(p->getMaxHP(), 10);
	EXPECT_EQ(p->getATK(), 1);
	EXPECT_EQ(p->getDEF(), 1);		
	
	//Player member variables
	//testing getters
	EXPECT_EQ(p->getGold(), 50);
	EXPECT_EQ(p->getLevel(), 1);
	EXPECT_EQ(p->getEXP(), 0);

	//testing setters from Entity
	p->setName("newName");
	p->setHP(5);
	p->setMaxHP(9);
	p->setATK(3);
	p->setDEF(3);

	//testing setters from Player
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

	//testing restoreHP() from Entity
	p->restoreHP();
	EXPECT_EQ(p->getHP(), 9); //maxHP is no longer 10 because it was set to 9 when setMaxHP() was tested above
}

TEST(PlayerTests, nameConstructorTest){
	//testing name constructor
	Player* p = new Player("First Name");
	
	//Entity member variables
	//testing getters
	EXPECT_EQ(p->getName(), "First Name");	
	EXPECT_EQ(p->getHP(), 10);
	EXPECT_EQ(p->getMaxHP(), 10);
	EXPECT_EQ(p->getATK(), 1);
	EXPECT_EQ(p->getDEF(), 1);
	
	//Player member variables
	//testing getters
	EXPECT_EQ(p->getGold(), 50);
	EXPECT_EQ(p->getEXP(), 0);
	EXPECT_EQ(p->getLevel(), 1);
	
	//testing setters from Entity and Player
	p->setName("Second Name");
	p->setHP(5);
	p->setMaxHP(15);
	p->setATK(5);
	p->setDEF(6);
	
	p->setGold(150);
	p->setEXP(4);
	p->setLevel(4);
	
	EXPECT_EQ(p->getName(), "Second Name");
	EXPECT_EQ(p->getHP(), 5);
	EXPECT_EQ(p->getMaxHP(), 15);
	EXPECT_EQ(p->getATK(), 5);
	EXPECT_EQ(p->getDEF(), 6);

	EXPECT_EQ(p->getGold(), 150);
	EXPECT_EQ(p->getEXP(), 4);
	EXPECT_EQ(p->getLevel(), 4);	

	//testing restoreHP() from Entity
	p->restoreHP();
	EXPECT_EQ(p->getHP(), 15);
} 

//add test for player->levelUp();

//add tests for enemies
TEST(EnemyTests, GoblinTest){
	EnemyFactory *ef = new EnemyFactory();
	Enemy *e = ef->createEnemy("Goblin");
	
	EXPECT_EQ(e->getName(), "Goblin");
	EXPECT_EQ(e->getHP(), 4);
	EXPECT_EQ(e->getMaxHP(), 4);
	EXPECT_EQ(e->getATK(), 3);
	EXPECT_EQ(e->getDEF(), 1);
	EXPECT_EQ(e->getDescription(), "Adventurous, greedy, and loot-heavy! Goblins tend to have a higher chance to drop items.");

	e->setName("New Goblin");
	e->setHP(15);
	e->setMaxHP(100);
	e->setATK(10);
	e->setDEF(10);
	e->setDescription("New Goblin Description");

	EXPECT_EQ(e->getName(), "New Goblin");
	EXPECT_EQ(e->getHP(), 15);
	EXPECT_EQ(e->getMaxHP(), 100);
	EXPECT_EQ(e->getATK(), 10);
	EXPECT_EQ(e->getDEF(), 10);
	EXPECT_EQ(e->getDescription(), "New Goblin Description");	
}

#endif //__ENTITY_TEST_H__
