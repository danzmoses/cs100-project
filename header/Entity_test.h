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
 	EXPECT_EQ(p->baseStats->HP, 10);
        EXPECT_EQ(p->baseStats->maxHP, 10);
        EXPECT_EQ(p->baseStats->ATK, 1);
        EXPECT_EQ(p->baseStats->DEF, 1);
 	EXPECT_EQ(p->combatStats->HP, 10);
 	EXPECT_EQ(p->combatStats->maxHP, 10);
 	EXPECT_EQ(p->combatStats->ATK, 1);
 	EXPECT_EQ(p->combatStats->DEF, 1);		
	
 	//Player member variables
 	//testing getters
 	EXPECT_EQ(p->getGold(), 50);
 	EXPECT_EQ(p->getLevel(), 1);
 	EXPECT_EQ(p->getEXP(), 0);

 	//testing setters from Entity
 	p->setName("newName");
	p->baseStats->HP = 5;
        p->baseStats->maxHP= 9;
        p->baseStats->ATK = 3;
        p->baseStats->DEF = 3;
 	p->combatStats->HP = 5;
 	p->combatStats->maxHP= 9;
 	p->combatStats->ATK = 3;
 	p->combatStats->DEF = 3;

 	//testing setters from Player
 	p->setGold(100);
 	p->setLevel(2);
 	p->setEXP(2);

 	EXPECT_EQ(p->getName(), "newName");
	EXPECT_EQ(p->baseStats->HP, 5);
        EXPECT_EQ(p->baseStats->maxHP, 9);
         EXPECT_EQ(p->baseStats->ATK, 3);
         EXPECT_EQ(p->baseStats->DEF, 3);	
        EXPECT_EQ(p->combatStats->HP, 5);
 	EXPECT_EQ(p->combatStats->maxHP, 9);
         EXPECT_EQ(p->combatStats->ATK, 3);
         EXPECT_EQ(p->combatStats->DEF, 3);

         EXPECT_EQ(p->getGold(), 100);
         EXPECT_EQ(p->getLevel(), 2);
 	EXPECT_EQ(p->getEXP(), 2);

 	//testing restoreHP() from Entity
 	p->restoreHP();
 	EXPECT_EQ(p->combatStats->HP, 9); //maxHP is no longer 10 because it was set to 9 when setMaxHP() was tested above
}

TEST(PlayerTests, nameConstructorTest){
 	//testing name constructor
 	Player* p = new Player("First Name");
	
 	//Entity member variables
 	//testing getters
 	EXPECT_EQ(p->getName(), "First Name");
	EXPECT_EQ(p->baseStats->HP, 10);
        EXPECT_EQ(p->baseStats->maxHP, 10);
        EXPECT_EQ(p->baseStats->ATK, 1);
        EXPECT_EQ(p->baseStats->DEF, 1);	
 	EXPECT_EQ(p->combatStats->HP, 10);
 	EXPECT_EQ(p->combatStats->maxHP, 10);
 	EXPECT_EQ(p->combatStats->ATK, 1);
 	EXPECT_EQ(p->combatStats->DEF, 1);
	
 	//Player member variables
 	//testing getters
 	EXPECT_EQ(p->getGold(), 50);
 	EXPECT_EQ(p->getEXP(), 0);
 	EXPECT_EQ(p->getLevel(), 1);
	
 	//testing setters from Entity and Player
 	p->setName("Second Name");
	p->baseStats->HP = 5;
        p->baseStats->maxHP = 15;
	p->baseStats->ATK = 5;
	p->baseStats->DEF = 6;
 	p->combatStats->HP = 5;
 	p->combatStats->maxHP = 15;
 	p->combatStats->ATK = 5;
 	p->combatStats->DEF = 6;
	
 	p->setGold(150);
 	p->setEXP(4);
 	p->setLevel(4);
	
 	EXPECT_EQ(p->getName(), "Second Name");
	EXPECT_EQ(p->baseStats->HP, 5);
        EXPECT_EQ(p->baseStats->maxHP, 15);
        EXPECT_EQ(p->baseStats->ATK, 5);
        EXPECT_EQ(p->baseStats->DEF, 6);
 	EXPECT_EQ(p->combatStats->HP, 5);
 	EXPECT_EQ(p->combatStats->maxHP, 15);
 	EXPECT_EQ(p->combatStats->ATK, 5);
 	EXPECT_EQ(p->combatStats->DEF, 6);

 	EXPECT_EQ(p->getGold(), 150);
 	EXPECT_EQ(p->getEXP(), 4);
 	EXPECT_EQ(p->getLevel(), 4);	

 	//testing restoreHP() from Entity
 	p->restoreHP();
 	EXPECT_EQ(p->combatStats->HP, 15);
} 

TEST(PlayerTests, levelUpTest){
 	Player *p = new Player("Linda");
 	p->setLevel(1);
	p->baseStats->ATK = 1;
        p->baseStats->DEF = 1;
 	p->combatStats->ATK = 1;
 	p->combatStats->DEF = 1;
 	p->setMaxEXP(5);
 	p->setEXP(14);
	p->baseStats->maxHP = 5;
 	p->combatStats->maxHP = 5;

 	EXPECT_EQ(p->getLevel(), 1);
	EXPECT_EQ(p->baseStats->ATK, 1);
        EXPECT_EQ(p->baseStats->DEF, 1);
 	EXPECT_EQ(p->combatStats->ATK, 1);
 	EXPECT_EQ(p->combatStats->DEF, 1);
 	EXPECT_EQ(p->getMaxEXP(), 5);
 	EXPECT_EQ(p->getEXP(), 14);
	EXPECT_EQ(p->baseStats->maxHP, 5);
 	EXPECT_EQ(p->combatStats->maxHP, 5);	

 	p->levelUp();
	
 	EXPECT_EQ(p->getLevel(), 3);
 	EXPECT_EQ(p->getEXP(), 4);
 	EXPECT_EQ(p->getMaxEXP(), 5);
	EXPECT_EQ(p->baseStats->ATK, 2);
        EXPECT_EQ(p->baseStats->DEF, 2);
        EXPECT_EQ(p->baseStats->maxHP, 10);
 	EXPECT_EQ(p->combatStats->ATK, 2);
 	EXPECT_EQ(p->combatStats->DEF, 2);
 	EXPECT_EQ(p->combatStats->maxHP, 10);	
}

// //add tests for enemies
TEST(EnemyTests, GoblinTest){
 	EnemyFactory *ef = new EnemyFactory();
	Enemy *e = ef->createEnemy("Goblin");
	
 	EXPECT_EQ(e->getName(), "Goblin");
 	EXPECT_EQ(e->combatStats->HP, 4);
 	EXPECT_EQ(e->combatStats->maxHP, 4);
 	EXPECT_EQ(e->combatStats->ATK, 3);
 	EXPECT_EQ(e->combatStats->DEF, 1);
 	EXPECT_EQ(e->getDescription(), "Adventurous, greedy, and loot-heavy! Goblins tend to have a higher chance to drop items.");

 	e->setName("New Goblin");
 	e->combatStats->HP = 15; 
 	e->combatStats->maxHP = 100;
 	e->combatStats->ATK = 10;
 	e->combatStats->DEF = 10;
 	e->setDescription("New Goblin Description");

 	EXPECT_EQ(e->getName(), "New Goblin");
 	EXPECT_EQ(e->combatStats->HP, 15);
 	EXPECT_EQ(e->combatStats->maxHP, 100);
 	EXPECT_EQ(e->combatStats->ATK, 10);
 	EXPECT_EQ(e->combatStats->DEF, 10);
 	EXPECT_EQ(e->getDescription(), "New Goblin Description");	
}

TEST(EnemyTests, GreenSlimeTest){
 	EnemyFactory *ef = new EnemyFactory();
 	Enemy *e = ef->createEnemy("Green Slime");

 	EXPECT_EQ(e->getName(), "Green Slime");
 	EXPECT_EQ(e->combatStats->HP, 2);
 	EXPECT_EQ(e->combatStats->maxHP, 2);
 	EXPECT_EQ(e->combatStats->ATK, 1);
 	EXPECT_EQ(e->combatStats->DEF, 1);
 	EXPECT_EQ(e->getDescription(), "A bouncing blob of goo. It looks harmless.");

 	e->setName("New Green Slime");
 	e->combatStats->HP = 5;
 	e->combatStats->maxHP = 10;
 	e->combatStats->ATK = 2;
 	e->combatStats->DEF = 2;
 	e->setDescription("New Green Slime Description");

 	EXPECT_EQ(e->getName(), "New Green Slime");
 	EXPECT_EQ(e->combatStats->HP, 5);
 	EXPECT_EQ(e->combatStats->maxHP, 10);
 	EXPECT_EQ(e->combatStats->ATK, 2);
 	EXPECT_EQ(e->combatStats->DEF, 2);
 	EXPECT_EQ(e->getDescription(), "New Green Slime Description");
}

TEST(EnemyTests, RedSlimeTest){
 	EnemyFactory *ef = new EnemyFactory();
 	Enemy *e = ef->createEnemy("Red Slime");
	
 	EXPECT_EQ(e->getName(), "Red Slime");
 	EXPECT_EQ(e->combatStats->HP, 3);
 	EXPECT_EQ(e->combatStats->maxHP, 3);
 	EXPECT_EQ(e->combatStats->ATK, 1);
 	EXPECT_EQ(e->combatStats->DEF, 1);
 	EXPECT_EQ(e->getDescription(), "A bouncing blob of goo. It looks aggressive.");
	
 	e->setName("New Red Slime");
 	e->combatStats->HP = 6;
 	e->combatStats->maxHP = 6;
 	e->combatStats->ATK = 3;;
 	e->combatStats->DEF = 3;
 	e->setDescription("New Red Slime Description");

 	EXPECT_EQ(e->getName(), "New Red Slime");
 	EXPECT_EQ(e->combatStats->HP, 6);
 	EXPECT_EQ(e->combatStats->maxHP, 6);
 	EXPECT_EQ(e->combatStats->ATK, 3);
 	EXPECT_EQ(e->combatStats->DEF, 3);
 	EXPECT_EQ(e->getDescription(), "New Red Slime Description");
}

TEST(EnemyTests, SkeletonTest){
 	//exception thrown in EnemyPrototype.h also works (took out skeleton prototype from enemyPrototypes vector)
 	EnemyFactory *ef = new EnemyFactory();
 	Enemy *e = ef->createEnemy("Skeleton");

 	EXPECT_EQ(e->getName(), "Skeleton");
 	EXPECT_EQ(e->combatStats->HP, 5);
 	EXPECT_EQ(e->combatStats->maxHP, 5);
 	EXPECT_EQ(e->combatStats->ATK, 2);
 	EXPECT_EQ(e->combatStats->DEF, 2);
 	EXPECT_EQ(e->getDescription(), "An undead humanoid made up of bones.");

 	e->setName("New Skeleton");
 	e->combatStats->HP = 10;;
 	e->combatStats->maxHP = 10;
 	e->combatStats->ATK = 4;
 	e->combatStats->DEF = 4;
 	e->setDescription("New Skeleton Description");

 	EXPECT_EQ(e->getName(), "New Skeleton");
 	EXPECT_EQ(e->combatStats->HP, 10);
 	EXPECT_EQ(e->combatStats->maxHP, 10);
 	EXPECT_EQ(e->combatStats->ATK, 4);
 	EXPECT_EQ(e->combatStats->DEF, 4);
 	EXPECT_EQ(e->getDescription(), "New Skeleton Description");
}

TEST(EnemyTests, ZombieTest){
 	EnemyFactory *ef = new EnemyFactory();
 	Enemy *e = ef->createEnemy("Zombie");

 	EXPECT_EQ(e->getName(), "Zombie");
 	EXPECT_EQ(e->combatStats->HP, 5);
 	EXPECT_EQ(e->combatStats->maxHP, 5);
 	EXPECT_EQ(e->combatStats->ATK, 3);
 	EXPECT_EQ(e->combatStats->DEF, 2);
 	EXPECT_EQ(e->getDescription(), "brains...");

 	e->setName("New Zombie");
 	e->combatStats->HP = 10;
 	e->combatStats->maxHP = 10;
 	e->combatStats->ATK = 6;
 	e->combatStats->DEF = 4;
 	e->setDescription("New Zombie Description");

 	EXPECT_EQ(e->getName(), "New Zombie");
 	EXPECT_EQ(e->combatStats->HP, 10);
 	EXPECT_EQ(e->combatStats->maxHP, 10);
 	EXPECT_EQ(e->combatStats->ATK, 6);
 	EXPECT_EQ(e->combatStats->DEF, 4);
 	EXPECT_EQ(e->getDescription(), "New Zombie Description");
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

#endif //__ENTITY_TEST_H__
