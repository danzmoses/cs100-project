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

	EXPECT_EQ(player->combatStats->HP, 10);
	EXPECT_EQ(player->combatStats->maxHP, 10);

	player->combatStats->HP = 7;

	EXPECT_EQ(player->combatStats->HP, 7);

	CardStrategy *cs = new SmallHealStrategy();

	cs->use(player, enemy);

	EXPECT_EQ(player->combatStats->HP, 10);
	EXPECT_EQ(player->combatStats->maxHP, 10);
}

TEST(CardStrategyTests, GreaterThanMaxHPSmallHealStrategy){
        Player *player = new Player("Hero");

        EnemyFactory *ef = new EnemyFactory();
        Enemy *enemy = ef->createEnemy("Green Slime");

        EXPECT_EQ(player->combatStats->HP, 10);
	EXPECT_EQ(player->combatStats->maxHP, 10);

        player->combatStats->HP = 9;

	EXPECT_EQ(player->combatStats->HP, 9);

	CardStrategy *cs = new SmallHealStrategy();

	cs->use(player, enemy);

	EXPECT_EQ(player->combatStats->HP, 10);
	EXPECT_EQ(player->combatStats->maxHP, 10);
} 

TEST(CardStrategyTests, SmallerThanMaxHPSmallHealStrategy){
	Player *player = new Player("Hero");

	EnemyFactory *ef = new EnemyFactory();
	Enemy *enemy = ef->createEnemy("Green Slime");

	EXPECT_EQ(player->combatStats->HP, 10);

	player->combatStats->HP = 6;

	EXPECT_EQ(player->combatStats->HP, 6);

	CardStrategy *cs = new SmallHealStrategy();

	cs->use(player, enemy);

	EXPECT_EQ(player->combatStats->HP, 8);
	EXPECT_EQ(player->combatStats->maxHP, 10);
}

TEST(CardStrategyTests, MaxHPChangesSmallHealStrategy){
	Player *player = new Player("Hero");

	EnemyFactory *ef = new EnemyFactory();
	Enemy *enemy = ef->createEnemy("Green Slime");

	EXPECT_EQ(player->combatStats->HP, 10);
	EXPECT_EQ(player->combatStats->maxHP, 10);

	player->combatStats->maxHP = 13;
	
	EXPECT_EQ(player->combatStats->maxHP, 13);

	CardStrategy *cs = new SmallHealStrategy();

	cs->use(player, enemy);

	EXPECT_EQ(player->combatStats->HP, 13);
	EXPECT_EQ(player->combatStats->maxHP, 13);
}

TEST(CardStrategyTests, EqualToMaxHPBigHealStrategy){
        Player *player = new Player("Hero");

        EnemyFactory *ef = new EnemyFactory();
        Enemy *enemy = ef->createEnemy("Green Slime");

        EXPECT_EQ(player->combatStats->HP, 10);
        EXPECT_EQ(player->combatStats->maxHP, 10);

        player->combatStats->HP = 6;

        EXPECT_EQ(player->combatStats->HP, 6);

        CardStrategy *cs = new BigHealStrategy();

        cs->use(player, enemy);

        EXPECT_EQ(player->combatStats->HP, 10);
        EXPECT_EQ(player->combatStats->maxHP, 10);
}

TEST(CardStrategyTests, GreaterThanMaxHPBigHealStrategy){
        Player *player = new Player("Hero");

        EnemyFactory *ef = new EnemyFactory();
        Enemy *enemy = ef->createEnemy("Green Slime");

        EXPECT_EQ(player->combatStats->HP, 10);
        EXPECT_EQ(player->combatStats->maxHP, 10);

        player->combatStats->HP = 9;

        EXPECT_EQ(player->combatStats->HP, 9);

        CardStrategy *cs = new BigHealStrategy();

        cs->use(player, enemy);

        EXPECT_EQ(player->combatStats->HP, 10);
        EXPECT_EQ(player->combatStats->maxHP, 10);
}

TEST(CardStrategyTests, SmallerThanMaxHPBigHealStrategy){
        Player *player = new Player("Hero");

        EnemyFactory *ef = new EnemyFactory();
        Enemy *enemy = ef->createEnemy("Green Slime");

        EXPECT_EQ(player->combatStats->HP, 10);

        player->combatStats->HP = 4;

        EXPECT_EQ(player->combatStats->HP, 4);

        CardStrategy *cs = new BigHealStrategy();

        cs->use(player, enemy);

        EXPECT_EQ(player->combatStats->HP, 6);
        EXPECT_EQ(player->combatStats->maxHP, 10);
}

TEST(CardStrategyTests, MaxHPChangesBigHealStrategy){
        Player *player = new Player("Hero");

        EnemyFactory *ef = new EnemyFactory();
        Enemy *enemy = ef->createEnemy("Green Slime");
                                                                                                                                EXPECT_EQ(player->combatStats->HP, 10);
        EXPECT_EQ(player->combatStats->maxHP, 10);

        player->combatStats->maxHP = 17;

        EXPECT_EQ(player->combatStats->maxHP, 17);

        CardStrategy *cs = new BigHealStrategy();
                                                                     
        cs->use(player, enemy);
                                                                                         
        EXPECT_EQ(player->combatStats->HP, 16);
	EXPECT_EQ(player->combatStats->maxHP, 17);
}

TEST(CardStrategyTests, MaxHPChangesBigHealStrategyTest2){
        Player *player = new Player("Hero");

        EnemyFactory *ef = new EnemyFactory();
        Enemy *enemy = ef->createEnemy("Green Slime");

        EXPECT_EQ(player->combatStats->HP, 10);
        EXPECT_EQ(player->combatStats->maxHP, 10);

        player->combatStats->maxHP = 15;

        EXPECT_EQ(player->combatStats->maxHP, 15);

        CardStrategy *cs = new BigHealStrategy();

        cs->use(player, enemy);

        EXPECT_EQ(player->combatStats->HP, 15);
	EXPECT_EQ(player->combatStats->maxHP, 15);
}

TEST(CardStrategyTests, MaxHPChangesBigHealStrategyTest3){
        Player *player = new Player("Hero");

        EnemyFactory *ef = new EnemyFactory();
        Enemy *enemy = ef->createEnemy("Green Slime");

        EXPECT_EQ(player->combatStats->HP, 10);
        EXPECT_EQ(player->combatStats->maxHP, 10);

        player->combatStats->maxHP = 16;

        EXPECT_EQ(player->combatStats->maxHP, 16);

        CardStrategy *cs = new BigHealStrategy();

        cs->use(player, enemy);

        EXPECT_EQ(player->combatStats->HP, 16);
	EXPECT_EQ(player->combatStats->maxHP, 16);
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
