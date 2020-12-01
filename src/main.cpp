#include <iostream>

#include "../header/Player.h"
#include "../header/Item.h"
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
    cout << "Armor ATK: " << armor->ATK << endl;
    cout << "Armor DEF: " << armor->DEF << endl << endl;
    
    armor->setName("Super cool Iron Armor");
    armor->setCost(9999);
    armor->ATK = 1;
    armor->DEF = 999;

    cout << "Armor Name: " << armor->getName() << endl;
    cout << "Armor Cost: " << armor->getCost() << endl;
    cout << "Armor ATK: " << armor->ATK << endl;
    cout << "Armor DEF: " << armor->DEF << endl << endl;
    
    ItemFactory* wf = new WeaponFactory();
    Item* weapon = wf->createItem("Stone Sword");

    cout << "Weapon Name: " << weapon->getName() << endl;
    cout << "Weapon Cost: " << weapon->getCost() << endl;
    cout << "Weapon ATK: " << weapon->ATK << endl;
    cout << "Weapon DEF: " << weapon->DEF << endl << endl;
    
    weapon->setName("Super cool Stone Sword");
    weapon->setCost(9999);
    weapon->ATK = 999;
    weapon->DEF = 1;

    cout << "Weapon Name: " << weapon->getName() << endl;
    cout << "Weapon Cost: " << weapon->getCost() << endl;
    cout << "Weapon ATK: " << weapon->ATK << endl;
    cout << "Weapon DEF: " << weapon->DEF << endl << endl;

    

    Player* player = new Player("Rice");

    cout << "Player Name: " << player->getName() << endl;
    cout << "Player HP: " << player->HP << endl;
    cout << "Player Gold: " << player->getGold() << endl;
    cout << "Player Level: " << player->getLevel() << endl;
    cout << "Player maxHP: " << player->maxHP << endl;
    cout << "Player EXP: " << player->getEXP() << endl;
    cout << "Player ATK: " << player->ATK << endl;
    cout << "Player DEF: " << player->DEF << endl << endl;

    player->setName("Fang");
    player->HP = 99;
    player->setGold(500);
    player->setLevel(2);
    player->maxHP = 100;
    player->setEXP(1);
    player->ATK = 2;
    player->DEF = 2;

    cout << "Player Name: " << player->getName() << endl;
    cout << "Player HP: " << player->HP << endl;
    cout << "Player maxHP: " << player->maxHP << endl;
    cout << "Player Gold: " << player->getGold() << endl;
    cout << "Player Level: " << player->getLevel() << endl;
    cout << "Player EXP: " << player->getEXP() << endl;
    cout << "Player ATK: " << player->ATK << endl;
    cout << "Player DEF: " << player->DEF << endl << endl;

    cout << "Restoring HP..." << endl;
    player->restoreHP();
    cout << "Player HP: " << player->HP << endl << endl;

    EnemyFactory* ef = new EnemyFactory(); // instantiate all enemy prototypes at once
    Enemy* enemy = ef->createEnemy("Zombie");

    cout << "Enemy Name: " << enemy->getName() << endl;
    cout << "Enemy HP: " << enemy->HP << endl;
    cout << "Enemy maxHP: " << enemy->maxHP << endl;
    cout << "Enemy description: " << enemy->getDescription() << endl;
    cout << "Enemy ATK: " << enemy->ATK << endl;
    cout << "Enemy DEF: " << enemy->DEF << endl << endl;

    enemy->setName("Mega Goblin");
    enemy->HP = 1000;
    enemy->maxHP = 1001;
    enemy->ATK = 50;
    enemy->DEF = 60;
    enemy->setDescription("It's a mega goblin... good luck, adventurer.");

    cout << "Enemy Name: " << enemy->getName() << endl;
    cout << "Enemy HP: " << enemy->HP << endl;
    cout << "Enemy maxHP: " << enemy->maxHP << endl;
    cout << "Enemy description: " << enemy->getDescription() << endl;
    cout << "Enemy ATK: " << enemy->ATK << endl;
    cout << "Enemy DEF: " << enemy->DEF << endl << endl;

    
}
