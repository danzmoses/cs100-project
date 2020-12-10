#ifndef BATTLE_H
#define BATTLE_H

#include "../Entity.h"
#include "../Player.h"
#include "../Enemy.h"

#include "LightAttackStrategy.h"
#include "NormalAttackStrategy.h"
#include "HeavyAttackStrategy.h"

#include "DealDamageStrategy.h"
#include "EnhanceATKStrategy.h"
#include "EnhanceDEFStrategy.h"
#include "BigHealStrategy.h"
#include "SmallHealStrategy.h"

#include <random>

class Battle
{
    private:
        Player* player;
        Enemy* enemy;
        Entity* attacker;
        Entity* defender;
        AttackStrategy* attackStrategy;
        CardStrategy* cardStrategy;
        int damageDone;
        int playerRoll;
        int enemyRoll;
        bool playerWonRoll;
        void getRoll()
        {
            playerRoll = std::rand() % 10 + 1;
            enemyRoll = std::rand() % 10 + 1;
            if (playerRoll >= enemyRoll)
            {
                
                attacker = player;
                defender = enemy;
                playerWonRoll = true;
                setAttackStrategy(playerRoll - enemyRoll);
            }
            else
            {
                attacker = enemy;
                defender = player;
                playerWonRoll = false;
                setAttackStrategy(enemyRoll - playerRoll);
            }
        }
        void setAttackStrategy(int diffBetweenRolls)
        {
            if (diffBetweenRolls >= 7)
                attackStrategy = new HeavyAttackStrategy();
            else if (diffBetweenRolls >= 4)
                attackStrategy = new NormalAttackStrategy();
            else
                attackStrategy = new LightAttackStrategy();
        }
        void setCardStrategy(std::string cardName)
        {
            if (cardName == "Deal Damage")
                cardStrategy = new DealDamageStrategy;
            else if (cardName == "Enhance ATK")
                cardStrategy = new EnhanceATKStrategy;
            else if (cardName == "Enhance DEF")
                cardStrategy = new EnhanceDEFStrategy;
            else if (cardName == "Big Heal")
                cardStrategy = new BigHealStrategy;
            else if (cardName == "Small Heal")
                cardStrategy = new SmallHealStrategy;
        }

    public:
        Battle();
        Battle(Player* player, Enemy* enemy): player(player), enemy(enemy) {}
        void nextTurn()
        {
            getRoll();
            damageDone = attackStrategy->attack(attacker, defender);
            defender->combatStats->HP -= damageDone;
        }

        void useCard(Entity* attacker, Entity* defender, std::string cardName)
        {
            setCardStrategy(cardName);
            cardStrategy->use(attacker, defender);
            attacker->unequip(cardName);
        }

        void endBattle()
        {
            if (player->combatStats->HP > 0) // else: nothing happens
            {
                int baseEXP = enemy->baseStats->HP / 5;
                if (baseEXP <= 0)
                    baseEXP = 1; 
                player->setEXP(player->getEXP() + enemy->getEXPMult() * baseEXP);
                player->setGold(player->getGold() + enemy->getGold());
            }
        }
        int getPlayerRoll() { return playerRoll; }
        int getEnemyRoll() { return enemyRoll; }
        int getDamageDone() { return damageDone; }
        bool getPlayerWonRoll() { return playerWonRoll; }
};

#endif // BATTLE_H
