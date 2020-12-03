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
    cout << "Armor ATK: " << armor->combatStats->ATK << endl;
    cout << "Armor DEF: " << armor->combatStats->DEF << endl << endl;

    armor->setName("Super cool Iron Armor");
    armor->setCost(9999);
    armor->combatStats->ATK = 1;
    armor->combatStats->DEF = 999;

    cout << "Armor Name: " << armor->getName() << endl;
    cout << "Armor Cost: " << armor->getCost() << endl;
    cout << "Armor ATK: " << armor->combatStats->ATK << endl;
    cout << "Armor DEF: " << armor->combatStats->DEF << endl << endl;
    
    ItemFactory* wf = new WeaponFactory();
    Item* weapon = wf->createItem("Stone Sword");

    cout << "Weapon Name: " << weapon->getName() << endl;
    cout << "Weapon Cost: " << weapon->getCost() << endl;
    cout << "Weapon ATK: " << weapon->combatStats->ATK << endl;
    cout << "Weapon DEF: " << weapon->combatStats->DEF << endl << endl;
    
    weapon->setName("Super cool Stone Sword");
    weapon->setCost(9999);
    weapon->combatStats->ATK = 999;
    weapon->combatStats->DEF = 1;

    cout << "Weapon Name: " << weapon->getName() << endl;
    cout << "Weapon Cost: " << weapon->getCost() << endl;
    cout << "Weapon ATK: " << weapon->combatStats->ATK << endl;
    cout << "Weapon DEF: " << weapon->combatStats->DEF << endl << endl;

    

    Player* player = new Player("Rice");

    cout << "Player Name: " << player->getName() << endl;
    cout << "Player HP: " << player->combatStats->HP << endl;
    cout << "Player Gold: " << player->getGold() << endl;
    cout << "Player Level: " << player->getLevel() << endl;
    cout << "Player maxHP: " << player->combatStats->maxHP << endl;
    cout << "Player EXP: " << player->getEXP() << endl;
    cout << "Player ATK: " << player->combatStats->ATK << endl;
    cout << "Player DEF: " << player->combatStats->DEF << endl << endl;

    player->setName("Fang");
    player->combatStats->HP = 99;
    player->setGold(500);
    player->setLevel(2);
    player->combatStats->maxHP = 100;
    player->setEXP(1);
    player->combatStats->ATK = 2;
    player->combatStats->DEF = 2;

    cout << "Player Name: " << player->getName() << endl;
    cout << "Player HP: " << player->combatStats->HP << endl;
    cout << "Player maxHP: " << player->combatStats->maxHP << endl;
    cout << "Player Gold: " << player->getGold() << endl;
    cout << "Player Level: " << player->getLevel() << endl;
    cout << "Player EXP: " << player->getEXP() << endl;
    cout << "Player ATK: " << player->combatStats->ATK << endl;
    cout << "Player DEF: " << player->combatStats->DEF << endl << endl;

    cout << "Restoring HP..." << endl;
    player->restoreHP();
    cout << "Player HP: " << player->combatStats->HP << endl << endl;

    EnemyFactory* ef = new EnemyFactory(); // instantiate all enemy prototypes at once
    Enemy* enemy = ef->createEnemy("Green Slime");

    cout << "Enemy Name: " << enemy->getName() << endl;
    cout << "Enemy HP: " << enemy->combatStats->HP << endl;
    cout << "Enemy maxHP: " << enemy->combatStats->maxHP << endl;
    cout << "Enemy description: " << enemy->getDescription() << endl;
    cout << "Enemy ATK: " << enemy->combatStats->ATK << endl;
    cout << "Enemy DEF: " << enemy->combatStats->DEF << endl << endl;

    enemy->setName("Mega Goblin");
    enemy->combatStats->HP = 1000;
    enemy->combatStats->maxHP = 1001;
    enemy->combatStats->ATK = 50;
    enemy->combatStats->DEF = 60;
    enemy->setDescription("It's a mega goblin... good luck, adventurer.");

    cout << "Enemy Name: " << enemy->getName() << endl;
    cout << "Enemy HP: " << enemy->combatStats->HP << endl;
    cout << "Enemy maxHP: " << enemy->combatStats->maxHP << endl;
    cout << "Enemy description: " << enemy->getDescription() << endl;
    cout << "Enemy ATK: " << enemy->combatStats->ATK << endl;
    cout << "Enemy DEF: " << enemy->combatStats->DEF << endl << endl;

    Enemy* enemy2 = ef->createEnemy("Green Slime");

    cout << "Enemy2 Name: " << enemy2->getName() << endl;
    cout << "Enemy2 HP: " << enemy2->getHP() << endl;
    cout << "Enemy2 maxHP: " << enemy2->getMaxHP() << endl;
    cout << "Enemy2 description: " << enemy2->getDescription() << endl;
    cout << "Enemy2 ATK: " << enemy2->getATK() << endl;
    cout << "Enemy2 DEF: " << enemy2->getDEF() << endl << endl;

    enemy = ef->createEnemy("Zombie"); // we lost the pointer to Mega Goblin
    
    cout << "Enemy Name: " << enemy->getName() << endl;
    cout << "Enemy HP: " << enemy->getHP() << endl;
    cout << "Enemy maxHP: " << enemy->getMaxHP() << endl;
    cout << "Enemy description: " << enemy->getDescription() << endl;
    cout << "Enemy ATK: " << enemy->getATK() << endl;
    cout << "Enemy DEF: " << enemy->getDEF() << endl << endl;
    
}
