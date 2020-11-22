#include <iostream>

#include "../header/Player.h"
#include "../header/EnemyFactory.h"

using namespace std;

int main()
{
    Player* player = new Player("Rice");

    cout << "Player Name: " << player->getName() << endl;
    cout << "Player HP: " << player->getHP() << endl;
    cout << "Player Gold: " << player->getGold() << endl;
    cout << "Player Level: " << player->getLevel() << endl;
    cout << "Player maxHP: " << player->getMaxHP() << endl;
    cout << "Player EXP: " << player->getEXP() << endl;
    cout << "Player ATK: " << player->getATK() << endl;
    cout << "Player DEF: " << player->getDEF() << endl << endl;

    player->setName("Fang");
    player->setHP(99);
    player->setGold(500);
    player->setLevel(2);
    player->setMaxHP(100);
    player->setEXP(1);
    player->setATK(2);
    player->setDEF(2);

    cout << "Player Name: " << player->getName() << endl;
    cout << "Player HP: " << player->getHP() << endl;
    cout << "Player maxHP: " << player->getMaxHP() << endl;
    cout << "Player Gold: " << player->getGold() << endl;
    cout << "Player Level: " << player->getLevel() << endl;
    cout << "Player EXP: " << player->getEXP() << endl;
    cout << "Player ATK: " << player->getATK() << endl;
    cout << "Player DEF: " << player->getDEF() << endl << endl;

    cout << "Restoring HP..." << endl;
    player->restoreHP();
    cout << "Player HP: " << player->getHP() << endl << endl;

    EnemyFactory* ef = new EnemyFactory(); // instantiate all enemy prototypes at once
    Enemy* enemy = ef->createEnemy("Goblin");

    cout << "Enemy Name: " << enemy->getName() << endl;
    cout << "Enemy HP: " << enemy->getHP() << endl;
    cout << "Enemy maxHP: " << enemy->getMaxHP() << endl;
    cout << "Enemy description: " << enemy->getDescription() << endl;
    cout << "Enemy ATK: " << enemy->getATK() << endl;
    cout << "Enemy DEF: " << enemy->getDEF() << endl << endl;

    enemy->setName("Mega Goblin");
    enemy->setHP(1000);
    enemy->setMaxHP(1001);
    enemy->setATK(50);
    enemy->setDEF(60);
    enemy->setDescription("It's a mega goblin... good luck, adventurer.");

    cout << "Enemy Name: " << enemy->getName() << endl;
    cout << "Enemy HP: " << enemy->getHP() << endl;
    cout << "Enemy maxHP: " << enemy->getMaxHP() << endl;
    cout << "Enemy description: " << enemy->getDescription() << endl;
    cout << "Enemy ATK: " << enemy->getATK() << endl;
    cout << "Enemy DEF: " << enemy->getDEF() << endl << endl;

    
}