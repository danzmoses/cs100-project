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