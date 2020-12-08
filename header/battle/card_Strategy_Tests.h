#ifndef __CARD_STRATEGY_TESTS_H__
#define __CARD_STRATEGY_TESTS_H__

#include "gtest/gtest.h"
#include "../Player.h"
#include "../EnemyFactory.h"
#include "SmallHealStrategy.h"
#include "BigHealStrategy.h"
#include "EnhanceDEFStrategy.h"
#include "EnhanceATKStrategy.h"
#include "DealDamageStrategy.h"

TEST(CardStrategyTests, EqualToMaxHPSmallHealStrategy){
	Player *player = new Player("Hero");

	EnemyFactory *ef = new EnemyFactory();
	Enemy *enemy = ef->createEnemy("Green Slime");

	EXPECT_EQ(player->combatStats->HP, 5);
	EXPECT_EQ(player->combatStats->maxHP, 5);

	player->combatStats->HP = 7;
	player->combatStats->maxHP = 10;

	EXPECT_EQ(player->combatStats->HP, 7);
	EXPECT_EQ(player->combatStats->maxHP, 10);

	CardStrategy *cs = new SmallHealStrategy();

	cs->use(player, enemy);

	EXPECT_EQ(player->combatStats->HP, 10);
	EXPECT_EQ(player->combatStats->maxHP, 10);
}

TEST(CardStrategyTests, GreaterThanMaxHPSmallHealStrategy){
        Player *player = new Player("Hero");

        EnemyFactory *ef = new EnemyFactory();
        Enemy *enemy = ef->createEnemy("Green Slime");

        EXPECT_EQ(player->combatStats->HP, 5);
	EXPECT_EQ(player->combatStats->maxHP, 5);

        player->combatStats->HP = 4;

	EXPECT_EQ(player->combatStats->HP, 4);

	CardStrategy *cs = new SmallHealStrategy();

	cs->use(player, enemy);

	EXPECT_EQ(player->combatStats->HP, 5);
	EXPECT_EQ(player->combatStats->maxHP, 5);
} 

TEST(CardStrategyTests, SmallerThanMaxHPSmallHealStrategy){
	Player *player = new Player("Hero");

	EnemyFactory *ef = new EnemyFactory();
	Enemy *enemy = ef->createEnemy("Green Slime");

	EXPECT_EQ(player->combatStats->HP, 5);
	EXPECT_EQ(player->combatStats->maxHP, 5);

	player->combatStats->HP = 2;

	EXPECT_EQ(player->combatStats->HP, 2);
	EXPECT_EQ(player->combatStats->maxHP, 5);

	CardStrategy *cs = new SmallHealStrategy();

	cs->use(player, enemy);

	EXPECT_EQ(player->combatStats->HP, 3);
	EXPECT_EQ(player->combatStats->maxHP, 5);
}

TEST(CardStrategyTests, MaxHPChangesSmallHealStrategy){
	Player *player = new Player("Hero");

	EnemyFactory *ef = new EnemyFactory();
	Enemy *enemy = ef->createEnemy("Green Slime");

	EXPECT_EQ(player->combatStats->HP, 5);
	EXPECT_EQ(player->combatStats->maxHP, 5);

	player->combatStats->maxHP = 8;

	EXPECT_EQ(player->combatStats->maxHP, 8);

	CardStrategy *cs = new SmallHealStrategy();

	cs->use(player, enemy);

	EXPECT_EQ(player->combatStats->HP, 7);
	EXPECT_EQ(player->combatStats->maxHP, 8);		
}

TEST(CardStrategyTests, MaxHPChangesSmallHealStrategy2){
	Player *player = new Player("Hero");

	EnemyFactory *ef = new EnemyFactory();
	Enemy *enemy = ef->createEnemy("Green Slime");

	EXPECT_EQ(player->combatStats->HP, 5);
	EXPECT_EQ(player->combatStats->maxHP, 5);

	player->combatStats->maxHP = 6;
	
	EXPECT_EQ(player->combatStats->maxHP, 6);

	CardStrategy *cs = new SmallHealStrategy();

	cs->use(player, enemy);

	EXPECT_EQ(player->combatStats->HP, 6);
	EXPECT_EQ(player->combatStats->maxHP, 6);
}

TEST(CardStrategyTests, MaxHPChangesSmallHealStrategy3){
	Player *player = new Player("Hero");

	EnemyFactory *ef = new EnemyFactory();
	Enemy *enemy = ef->createEnemy("Green Slime");

	EXPECT_EQ(player->combatStats->HP, 5);
	EXPECT_EQ(player->combatStats->maxHP, 5);

	player->combatStats->maxHP = 7;

	EXPECT_EQ(player->combatStats->maxHP, 7);

	CardStrategy *cs = new SmallHealStrategy();

	cs->use(player, enemy);

	EXPECT_EQ(player->combatStats->HP, 7);
	EXPECT_EQ(player->combatStats->maxHP, 7);
}

TEST(CardStrategyTests, EqualToMaxHPBigHealStrategy){
        Player *player = new Player("Hero");

        EnemyFactory *ef = new EnemyFactory();
        Enemy *enemy = ef->createEnemy("Green Slime");

        EXPECT_EQ(player->combatStats->HP, 5);
        EXPECT_EQ(player->combatStats->maxHP, 5);

        player->combatStats->HP = 3;

        EXPECT_EQ(player->combatStats->HP, 3);

        CardStrategy *cs = new BigHealStrategy();

        cs->use(player, enemy);

        EXPECT_EQ(player->combatStats->HP, 5);
        EXPECT_EQ(player->combatStats->maxHP, 5);
}

TEST(CardStrategyTests, GreaterThanMaxHPBigHealStrategy){
        Player *player = new Player("Hero");

        EnemyFactory *ef = new EnemyFactory();
        Enemy *enemy = ef->createEnemy("Green Slime");

        EXPECT_EQ(player->combatStats->HP, 5);
        EXPECT_EQ(player->combatStats->maxHP, 5);

        player->combatStats->HP = 4;

        EXPECT_EQ(player->combatStats->HP, 4);

        CardStrategy *cs = new BigHealStrategy();

        cs->use(player, enemy);

        EXPECT_EQ(player->combatStats->HP, 5);
        EXPECT_EQ(player->combatStats->maxHP, 5);
}

TEST(CardStrategyTests, SmallerThanMaxHPBigHealStrategy){
        Player *player = new Player("Hero");

        EnemyFactory *ef = new EnemyFactory();
        Enemy *enemy = ef->createEnemy("Green Slime");

        EXPECT_EQ(player->combatStats->HP, 5);
	EXPECT_EQ(player->combatStats->maxHP, 5);

        player->combatStats->HP = 2;

        EXPECT_EQ(player->combatStats->HP, 2);

        CardStrategy *cs = new BigHealStrategy();

        cs->use(player, enemy);

        EXPECT_EQ(player->combatStats->HP, 3);
        EXPECT_EQ(player->combatStats->maxHP, 5);
}

TEST(CardStrategyTests, MaxHPChangesBigHealStrategy){
        Player *player = new Player("Hero");

        EnemyFactory *ef = new EnemyFactory();
        Enemy *enemy = ef->createEnemy("Green Slime");
        
	EXPECT_EQ(player->combatStats->HP, 5);
	EXPECT_EQ(player->combatStats->maxHP, 5);

        player->combatStats->maxHP = 9;

        EXPECT_EQ(player->combatStats->maxHP, 9);

        CardStrategy *cs = new BigHealStrategy();
                                                                     
        cs->use(player, enemy);
                                                                                         
        EXPECT_EQ(player->combatStats->HP, 8);
	EXPECT_EQ(player->combatStats->maxHP, 9);
}

TEST(CardStrategyTests, MaxHPChangesBigHealStrategyTest2){
        Player *player = new Player("Hero");

        EnemyFactory *ef = new EnemyFactory();
        Enemy *enemy = ef->createEnemy("Green Slime");

        EXPECT_EQ(player->combatStats->HP, 5);
        EXPECT_EQ(player->combatStats->maxHP, 5);

        player->combatStats->maxHP = 7;

        EXPECT_EQ(player->combatStats->maxHP, 7);

        CardStrategy *cs = new BigHealStrategy();

        cs->use(player, enemy);

        EXPECT_EQ(player->combatStats->HP, 7);
	EXPECT_EQ(player->combatStats->maxHP, 7);
}

TEST(CardStrategyTests, MaxHPChangesBigHealStrategyTest3){
        Player *player = new Player("Hero");

        EnemyFactory *ef = new EnemyFactory();
        Enemy *enemy = ef->createEnemy("Green Slime");

        EXPECT_EQ(player->combatStats->HP, 5);
        EXPECT_EQ(player->combatStats->maxHP, 5);

        player->combatStats->maxHP = 8;

        EXPECT_EQ(player->combatStats->maxHP, 8);

        CardStrategy *cs = new BigHealStrategy();

        cs->use(player, enemy);

        EXPECT_EQ(player->combatStats->HP, 8);
	EXPECT_EQ(player->combatStats->maxHP, 8);
}

TEST(CardStrategyTests, EnhanceDEFStrategy){
	Player *player = new Player("Hero");

	EnemyFactory *ef = new EnemyFactory();
	Enemy *enemy = ef->createEnemy("Goblin");

	EXPECT_EQ(player->combatStats->DEF, 1);

	CardStrategy *cs = new EnhanceDEFStrategy();

	cs->use(player, enemy);

	EXPECT_EQ(player->combatStats->DEF, 2);	
}

TEST(CardStrategyTests, EnhanceATKStrategy){
	Player *player = new Player("Hero");

	EnemyFactory *ef = new EnemyFactory();
	Enemy *enemy = ef->createEnemy("Red Slime");

	EXPECT_EQ(player->combatStats->ATK, 1);

	CardStrategy *cs = new EnhanceATKStrategy();

	cs->use(player, enemy);

	EXPECT_EQ(player->combatStats->ATK, 2);
}

TEST(CardStrategyTests, HPGreaterThanZeroDealDamageStrategy){
	Player *player = new Player("Hero");

	EnemyFactory *ef = new EnemyFactory();
	Enemy *enemy = ef->createEnemy("Skeleton");

	EXPECT_EQ(enemy->combatStats->HP, 5);

	CardStrategy *cs = new DealDamageStrategy();

	cs->use(player, enemy);

	EXPECT_EQ(enemy->combatStats->HP, 3);
}

TEST(CardStrategyTests, HPOf1DealDamageStrategy){
	Player *player = new Player("Hero");

	EnemyFactory *ef = new EnemyFactory();
	Enemy *enemy = ef->createEnemy("Green Slime");

	EXPECT_EQ(enemy->combatStats->HP, 2);
	enemy->combatStats->HP = 1;
	
	EXPECT_EQ(enemy->combatStats->HP, 1);

	CardStrategy *cs = new DealDamageStrategy();

	cs->use(player, enemy);

	EXPECT_EQ(enemy->combatStats->HP, 1); 
}

TEST(CardStrategyTests, HPEqualToZeroDealDamageStrategy){
	Player *player = new Player("Hero");
	
	EnemyFactory *ef = new EnemyFactory();
	Enemy *enemy = ef->createEnemy("Green Slime");

	EXPECT_EQ(enemy->combatStats->HP, 2);
	enemy->combatStats->HP = 0;

	EXPECT_EQ(enemy->combatStats->HP, 0);

	CardStrategy *cs = new DealDamageStrategy();

	cs->use(player, enemy);

	EXPECT_EQ(enemy->combatStats->HP, 0);

}

#endif //__CARD_STRATEGY_TESTS_H__
