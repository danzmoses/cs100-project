#include <iostream>

#include "../header/Player.h"
#include "../header/EnemyFactory.h"
#include "../header/ArmorFactory.h"
#include "../header/WeaponFactory.h"

using namespace std;

int main()
{
    ItemFactory* af = new ArmorFactory();
    Item* armor = af->createItem("Iron Armor");

    cout << "Armor Name: " << armor->getName() << endl;
    cout << "Armor Cost: " << armor->getCost() << endl;
    cout << "Armor ATK: " << armor->getATK() << endl;
    cout << "Armor DEF: " << armor->getDEF() << endl << endl;
    
    armor->setName("Super cool Iron Armor");
    armor->setCost(9999);
    armor->setATK(1);
    armor->setDEF(999);

    cout << "Armor Name: " << armor->getName() << endl;
    cout << "Armor Cost: " << armor->getCost() << endl;
    cout << "Armor ATK: " << armor->getATK() << endl;
    cout << "Armor DEF: " << armor->getDEF() << endl << endl;
    
    ItemFactory* wf = new WeaponFactory();
    Item* weapon = wf->createItem("Stone Sword");

    cout << "Weapon Name: " << weapon->getName() << endl;
    cout << "Weapon Cost: " << weapon->getCost() << endl;
    cout << "Weapon ATK: " << weapon->getATK() << endl;
    cout << "Weapon DEF: " << weapon->getDEF() << endl << endl;
    
    weapon->setName("Super cool Stone Sword");
    weapon->setCost(9999);
    weapon->setATK(999);
    weapon->setDEF(1);

    cout << "Weapon Name: " << weapon->getName() << endl;
    cout << "Weapon Cost: " << weapon->getCost() << endl;
    cout << "Weapon ATK: " << weapon->getATK() << endl;
    cout << "Weapon DEF: " << weapon->getDEF() << endl << endl;

    

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
    Enemy* enemy = ef->createEnemy("Zombie");

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