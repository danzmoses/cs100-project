#include "../Entity.h"
#include "../Player.h"
#include "../Enemy.h"
#include "AttackStrategy.h"
#include "LightAttackStrategy.h"
#include "NormalAttackStrategy.h"
#include "HeavyAttackStrategy.h"

#include <random>

class Battle
{
    private:
        Player* player;
        Enemy* enemy;
        Entity* attacker;
        Entity* defender;
        AttackStrategy* attackStrategy;
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

    public:
        Battle();
        Battle(Player* player, Enemy* enemy): player(player), enemy(enemy) {}
        void nextTurn()
        {
            getRoll();
            damageDone = attackStrategy->attack(attacker, defender);
            defender->combatStats->HP -= damageDone;
        }
        int getPlayerRoll() { return playerRoll; }
        int getEnemyRoll() { return enemyRoll; }
        int getDamageDone() { return damageDone; }
        bool getPlayerWonRoll() { return playerWonRoll; }
};
