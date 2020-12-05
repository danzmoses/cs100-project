#ifndef __ATTACK_STRATEGY_TESTS_H__ 
#define __ATTACK_STRATEGY_TESTS_H__

#include "gtest/gtest.h"
#include "LightAttackStrategy.h"
#include "NormalAttackStrategy.h"
#include "HeavyAttackStrategy.h"
#include "../Player.h"
#include "../EnemyFactory.h"

TEST(AttackStrategyTests, LightAttackStrategyPlayerDealsDamage)
{
    Entity* player = new Player;
    EnemyFactory ef;
    Entity* enemy = ef.createEnemy("Green Slime");

    player->combatStats->HP = 5;        // player HP = 5
    player->combatStats->ATK = 1;       // player ATK = 1
    player->combatStats->DEF = 1;       // player DEF = 1

    enemy->combatStats->HP = 5;         // enemy HP = 5
    enemy->combatStats->ATK = 1;        // enemy ATK = 1
    enemy->combatStats->DEF = 0;        // enemy DEF = 0

    // LightAttackStrategy: damage_done = attacker->ATK - defender->DEF = 1 - 0 = 1
    AttackStrategy* strategy = new LightAttackStrategy();
    int damage_done = strategy->attack(player, enemy);
    EXPECT_EQ(damage_done, 1);
    // When applied to enemy, enemy->HP -= damage_done = 5 - 1 = 4
    enemy->combatStats->HP -= damage_done;
    EXPECT_EQ(enemy->combatStats->HP, 4);
}

TEST(AttackStrategyTests, LightAttackStrategyPlayerDealsNoDamage)
{
    Entity* player = new Player;
    EnemyFactory ef;
    Entity* enemy = ef.createEnemy("Green Slime");

    player->combatStats->HP = 5;        // player HP = 5
    player->combatStats->ATK = 1;       // player ATK = 1
    player->combatStats->DEF = 1;       // player DEF = 1

    enemy->combatStats->HP = 5;         // enemy HP = 5
    enemy->combatStats->ATK = 1;        // enemy ATK = 1
    enemy->combatStats->DEF = 1;        // enemy DEF = 1

    // LightAttackStrategy: damage_done = attacker->ATK - defender->DEF = 1 - 1 = 0
    AttackStrategy* strategy = new LightAttackStrategy();
    int damage_done = strategy->attack(player, enemy);
    EXPECT_EQ(damage_done, 0);
    // When applied to enemy, enemy->HP -= damage_done = 5 - 0 = 5
    enemy->combatStats->HP -= damage_done;
    EXPECT_EQ(enemy->combatStats->HP, 5);
}

TEST(AttackStrategyTests, LightAttackStrategyPlayerNegativeDamageDone)
{
    Entity* player = new Player;
    EnemyFactory ef;
    Entity* enemy = ef.createEnemy("Green Slime");

    player->combatStats->HP = 5;        // player HP = 5
    player->combatStats->ATK = 1;       // player ATK = 1
    player->combatStats->DEF = 1;       // player DEF = 1

    enemy->combatStats->HP = 5;         // enemy HP = 5
    enemy->combatStats->ATK = 1;        // enemy ATK = 1
    enemy->combatStats->DEF = 5;        // enemy DEF = 5

    // LightAttackStrategy: damage_done = attacker->ATK - defender->DEF = 1 - 5 = -4 (if negative, damage = 0)
    AttackStrategy* strategy = new LightAttackStrategy();
    int damage_done = strategy->attack(player, enemy);
    EXPECT_EQ(damage_done, 0);
    // When applied to enemy, enemy->HP -= damage_done = 5 - 0 = 5
    enemy->combatStats->HP -= damage_done;
    EXPECT_EQ(enemy->combatStats->HP, 5);
}

TEST(AttackStrategyTests, LightAttackStrategyEnemyDealsDamage)
{
    Entity* player = new Player;
    EnemyFactory ef;
    Entity* enemy = ef.createEnemy("Green Slime");

    player->combatStats->HP = 5;        // player HP = 5
    player->combatStats->ATK = 1;       // player ATK = 1
    player->combatStats->DEF = 1;       // player DEF = 1

    enemy->combatStats->HP = 5;         // enemy HP = 5
    enemy->combatStats->ATK = 3;        // enemy ATK = 3
    enemy->combatStats->DEF = 5;        // enemy DEF = 5

    // LightAttackStrategy: damage_done = attacker->ATK - defender->DEF = 3 - 1 = 2 (if negative, damage = 0)
    AttackStrategy* strategy = new LightAttackStrategy();
    int damage_done = strategy->attack(enemy, player);
    EXPECT_EQ(damage_done, 2);
    player->combatStats->HP -= damage_done;
    EXPECT_EQ(player->combatStats->HP, 3);
}

TEST(AttackStrategyTests, LightAttackStrategyEnemyNoDamage)
{
    Entity* player = new Player;
    EnemyFactory ef;
    Entity* enemy = ef.createEnemy("Green Slime");

    player->combatStats->HP = 5;        // player HP = 5
    player->combatStats->ATK = 1;       // player ATK = 1
    player->combatStats->DEF = 3;       // player DEF = 3

    enemy->combatStats->HP = 5;         // enemy HP = 5
    enemy->combatStats->ATK = 3;        // enemy ATK = 3
    enemy->combatStats->DEF = 5;        // enemy DEF = 5

    // LightAttackStrategy: damage_done = attacker->ATK - defender->DEF = 3 - 3 = 0 (if negative, damage = 0)
    AttackStrategy* strategy = new LightAttackStrategy();
    int damage_done = strategy->attack(enemy, player);
    EXPECT_EQ(damage_done, 0);
    player->combatStats->HP -= damage_done;
    EXPECT_EQ(player->combatStats->HP, 5);
}

TEST(AttackStrategyTests, LightAttackStrategyEnemyNegativeDamage)
{
    Entity* player = new Player;
    EnemyFactory ef;
    Entity* enemy = ef.createEnemy("Green Slime");

    player->combatStats->HP = 5;        // player HP = 5
    player->combatStats->ATK = 1;       // player ATK = 1
    player->combatStats->DEF = 5;       // player DEF = 5

    enemy->combatStats->HP = 5;         // enemy HP = 5
    enemy->combatStats->ATK = 1;        // enemy ATK = 1
    enemy->combatStats->DEF = 5;        // enemy DEF = 5

    // LightAttackStrategy: damage_done = attacker->ATK - defender->DEF = 1 - 5 = -4 (if negative, damage = 0)
    AttackStrategy* strategy = new LightAttackStrategy();
    int damage_done = strategy->attack(enemy, player);
    EXPECT_EQ(damage_done, 0);
    player->combatStats->HP -= damage_done;
    EXPECT_EQ(player->combatStats->HP, 5);
}

TEST(AttackStrategyTests, NormalAttackStrategyPlayerDealsDamage)
{
    Entity* player = new Player;
    EnemyFactory ef;
    Entity* enemy = ef.createEnemy("Green Slime");

    player->combatStats->HP = 5;        // player HP = 5
    player->combatStats->ATK = 1;       // player ATK = 1
    player->combatStats->DEF = 1;       // player DEF = 1

    enemy->combatStats->HP = 5;         // enemy HP = 5
    enemy->combatStats->ATK = 1;        // enemy ATK = 1
    enemy->combatStats->DEF = 0;        // enemy DEF = 0

    // NormalAttackStrategy: damage_done = (attacker->ATK*2) - defender->DEF = 1*2 - 0 = 2
    AttackStrategy* strategy = new NormalAttackStrategy();
    int damage_done = strategy->attack(player, enemy);
    EXPECT_EQ(damage_done, 2);
    enemy->combatStats->HP -= damage_done;
    EXPECT_EQ(enemy->combatStats->HP, 3);
}

TEST(AttackStrategyTests, NormalAttackStrategyEnemyDealsDamage)
{
    Entity* player = new Player;
    EnemyFactory ef;
    Entity* enemy = ef.createEnemy("Green Slime");

    player->combatStats->HP = 5;        // player HP = 5
    player->combatStats->ATK = 1;       // player ATK = 1
    player->combatStats->DEF = 1;       // player DEF = 1

    enemy->combatStats->HP = 5;         // enemy HP = 5
    enemy->combatStats->ATK = 2;        // enemy ATK = 1
    enemy->combatStats->DEF = 0;        // enemy DEF = 0

    // NormalAttackStrategy: damage_done = (attacker->ATK*2) - defender->DEF = 2*2 - 1 = 3
    AttackStrategy* strategy = new NormalAttackStrategy();
    int damage_done = strategy->attack(enemy, player);
    EXPECT_EQ(damage_done, 3);
    player->combatStats->HP -= damage_done;
    EXPECT_EQ(player->combatStats->HP, 2);
}

TEST(AttackStrategyTests, HeavyAttackStrategyPlayerDealsDamage)
{
    Entity* player = new Player;
    EnemyFactory ef;
    Entity* enemy = ef.createEnemy("Green Slime");

    player->combatStats->HP = 5;        // player HP = 5
    player->combatStats->ATK = 1;       // player ATK = 1
    player->combatStats->DEF = 1;       // player DEF = 1

    enemy->combatStats->HP = 5;         // enemy HP = 5
    enemy->combatStats->ATK = 1;        // enemy ATK = 1
    enemy->combatStats->DEF = 0;        // enemy DEF = 0

    // HeavyAttackStrategy: damage_done = (attacker->ATK*3) - defender->DEF = 1*3 - 0 = 3
    AttackStrategy* strategy = new HeavyAttackStrategy();
    int damage_done = strategy->attack(player, enemy);
    EXPECT_EQ(damage_done, 3);
    enemy->combatStats->HP -= damage_done;
    EXPECT_EQ(enemy->combatStats->HP, 2);
}

TEST(AttackStrategyTests, HeavyAttackStrategyEnemyDealsDamage)
{
    Entity* player = new Player;
    EnemyFactory ef;
    Entity* enemy = ef.createEnemy("Green Slime");

    player->combatStats->HP = 5;        // player HP = 5
    player->combatStats->ATK = 1;       // player ATK = 1
    player->combatStats->DEF = 2;       // player DEF = 1

    enemy->combatStats->HP = 5;         // enemy HP = 5
    enemy->combatStats->ATK = 2;        // enemy ATK = 1
    enemy->combatStats->DEF = 0;        // enemy DEF = 0

    // HeavyAttackStrategy: damage_done = (attacker->ATK*3) - defender->DEF = 2*3 - 2 = 4
    AttackStrategy* strategy = new HeavyAttackStrategy();
    int damage_done = strategy->attack(enemy, player);
    EXPECT_EQ(damage_done, 4);
    player->combatStats->HP -= damage_done;
    EXPECT_EQ(player->combatStats->HP, 1);
}

#endif // __ATTACK_STRATEGY_TESTS_H__