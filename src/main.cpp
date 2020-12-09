#include <iostream>

#include "../header/Player.h"
#include "../header/Item.h"
#include "../header/EnemyFactory.h"
#include "../header/ArmorFactory.h"
#include "../header/WeaponFactory.h"
#include "../header/battle/Battle.h"
#include <ctime>
#include <fstream>



using namespace std;

int main()
{
    
    // __ LEVELING TEST HARNESS __

    // Player* player = new Player("Rice");

    // srand(time(0));

    // cout << "Player Level: " << player->getLevel() << endl;
    // cout << "Player Base ATK: " << player->baseStats->ATK << endl;
    // cout << "Player Combat ATK: " << player->combatStats->ATK << endl;
    // cout << "Player Base DEF: " << player->baseStats->DEF << endl;
    // cout << "Player Combat DEF: " << player->combatStats->DEF << endl;
    // cout << "Player Base maxHP: " << player->baseStats->maxHP << endl;
    // cout << "Player Combat maxHP: " << player->combatStats->maxHP << endl;
    // cout << "Player EXP: " << player->getEXP() << endl;
    // cout << "Player maxEXP: " << player->getMaxEXP() << endl << endl;
    
    // cout << "player->setEXP(1)" << endl << endl;
    // player->setEXP(1);
 
    // cout << "Player Level: " << player->getLevel() << endl;
    // cout << "Player Base ATK: " << player->baseStats->ATK << endl;
    // cout << "Player Combat ATK: " << player->combatStats->ATK << endl;
    // cout << "Player Base DEF: " << player->baseStats->DEF << endl;
    // cout << "Player Combat DEF: " << player->combatStats->DEF << endl;
    // cout << "Player Base maxHP: " << player->baseStats->maxHP << endl;
    // cout << "Player Combat maxHP: " << player->combatStats->maxHP << endl;
    // cout << "Player EXP: " << player->getEXP() << endl;
    // cout << "Player maxEXP: " << player->getMaxEXP() << endl<< endl;

    // cout << "player->setEXP(5)" << endl << endl;
    // player->setEXP(5);
    // cout << "Level Up!" << endl << endl;

    // cout << "Player Level: " << player->getLevel() << endl;
    // cout << "Player Base ATK: " << player->baseStats->ATK << endl;
    // cout << "Player Combat ATK: " << player->combatStats->ATK << endl;
    // cout << "Player Base DEF: " << player->baseStats->DEF << endl;
    // cout << "Player Combat DEF: " << player->combatStats->DEF << endl;
    // cout << "Player Base maxHP: " << player->baseStats->maxHP << endl;
    // cout << "Player Combat maxHP: " << player->combatStats->maxHP << endl;
    // cout << "Player EXP: " << player->getEXP() << endl;
    // cout << "Player maxEXP: " << player->getMaxEXP() << endl<< endl;

    // cout << "player->setEXP(20)" << endl << endl;
    // player->setEXP(20);
    // cout << "Level Up!" << endl << endl;

    // cout << "Player Level: " << player->getLevel() << endl;
    // cout << "Player Base ATK: " << player->baseStats->ATK << endl;
    // cout << "Player Combat ATK: " << player->combatStats->ATK << endl;
    // cout << "Player Base DEF: " << player->baseStats->DEF << endl;
    // cout << "Player Combat DEF: " << player->combatStats->DEF << endl;
    // cout << "Player Base maxHP: " << player->baseStats->maxHP << endl;
    // cout << "Player Combat maxHP: " << player->combatStats->maxHP << endl;
    // cout << "Player EXP: " << player->getEXP() << endl;
    // cout << "Player maxEXP: " << player->getMaxEXP() << endl<< endl;

    // cout << "player->setEXP(65)" << endl << endl;
    // player->setEXP(65);
    // cout << "Level Up!" << endl << endl;
    // cout << "Level Up!" << endl << endl;

    // cout << "Player Level: " << player->getLevel() << endl;
    // cout << "Player Base ATK: " << player->baseStats->ATK << endl;
    // cout << "Player Combat ATK: " << player->combatStats->ATK << endl;
    // cout << "Player Base DEF: " << player->baseStats->DEF << endl;
    // cout << "Player Combat DEF: " << player->combatStats->DEF << endl;
    // cout << "Player Base maxHP: " << player->baseStats->maxHP << endl;
    // cout << "Player Combat maxHP: " << player->combatStats->maxHP << endl;
    // cout << "Player EXP: " << player->getEXP() << endl;
    // cout << "Player maxEXP: " << player->getMaxEXP() << endl<< endl;


    // cout << "player->setEXP(46)" << endl << endl;
    // player->setEXP(46);
    // cout << "Level Up!" << endl << endl;

    // cout << "Player Level: " << player->getLevel() << endl;
    // cout << "Player Base ATK: " << player->baseStats->ATK << endl;
    // cout << "Player Combat ATK: " << player->combatStats->ATK << endl;
    // cout << "Player Base DEF: " << player->baseStats->DEF << endl;
    // cout << "Player Combat DEF: " << player->combatStats->DEF << endl;
    // cout << "Player Base maxHP: " << player->baseStats->maxHP << endl;
    // cout << "Player Combat maxHP: " << player->combatStats->maxHP << endl;
    // cout << "Player EXP: " << player->getEXP() << endl;
    // cout << "Player maxEXP: " << player->getMaxEXP() << endl<< endl;

    
    // // __ BATTLE TEST HARNESS __

    // srand(time(0));
    // int playerWins = 0;
    // int enemyWins = 0;
    
    // while (true)
    // {
    
    // bool playerWon = true;

    // Player* player = new Player("Rice");
    // player->combatStats->ATK = 2;
    // EnemyFactory* ef = new EnemyFactory();
    
    // Enemy* e1 = ef->createEnemy("Green Slime");
    // Battle* b1 = new Battle(player, e1);

    // while (player->combatStats->HP > 0 && e1->combatStats->HP > 0)
    // {
    //     b1->nextTurn();
    //     cout << "Player HP: " << player->combatStats->HP << endl;
    //     cout << "Enemy HP: " << e1->combatStats->HP << endl;
    //     cout << "Player rolled a " << b1->getPlayerRoll() << "!\n";
    //     cout << "Enemy rolled a " << b1->getEnemyRoll() << "!\n";
    //     if (b1->getPlayerWonRoll())
    //         cout << "Player won the roll and dealt ";
    //     else
    //         cout << "Enemy won the roll and dealt ";
    //     cout << b1->getDamageDone() << "!\n\n";
    // }

    // if (player->combatStats->HP > 0)
    //     cout << "Player won!\n";
    // else
    // {
    //     cout << "Enemy won!\n";
    //     playerWon = false;
    // }
    
    // Enemy* e2 = ef->createEnemy("Green Slime");
    // Battle* b2 = new Battle(player, e2);

    // while (player->combatStats->HP > 0 && e2->combatStats->HP > 0)
    // {
    //     b2->nextTurn();
    //     cout << "Player HP: " << player->combatStats->HP << endl;
    //     cout << "Enemy HP: " << e2->combatStats->HP << endl;
    //     cout << "Player rolled a " << b2->getPlayerRoll() << "!\n";
    //     cout << "Enemy rolled a " << b2->getEnemyRoll() << "!\n";
    //     if (b2->getPlayerWonRoll())
    //         cout << "Player won the roll and dealt ";
    //     else
    //         cout << "Enemy won the roll and dealt ";
    //     cout << b2->getDamageDone() << "!\n\n";
    // }

    // if (player->combatStats->HP > 0)
    //     cout << "Player won!\n";
    // else
    // {
    //     cout << "Enemy won!\n";
    //     playerWon = false;
    // }

    // Enemy* e3 = ef->createEnemy("Green Slime");
    // Battle* b3 = new Battle(player, e3);

    // while (player->combatStats->HP > 0 && e3->combatStats->HP > 0)
    // {
    //     b3->nextTurn();
    //     cout << "Player HP: " << player->combatStats->HP << endl;
    //     cout << "Enemy HP: " << e3->combatStats->HP << endl;
    //     cout << "Player rolled a " << b3->getPlayerRoll() << "!\n";
    //     cout << "Enemy rolled a " << b3->getEnemyRoll() << "!\n";
    //     if (b3->getPlayerWonRoll())
    //         cout << "Player won the roll and dealt ";
    //     else
    //         cout << "Enemy won the roll and dealt ";
    //     cout << b3->getDamageDone() << "!\n\n";
    // }

    // if (player->combatStats->HP > 0)
    //     cout << "Player won!\n";
    // else
    // {
    //     cout << "Enemy won!\n";
    //     playerWon = false;
    // }


    // if (playerWon)
    //     ++playerWins;
    // else
    //     ++enemyWins;
    
    // cout << "playerWins: " << playerWins << endl;
    // cout << "enemyWins: " << enemyWins << endl << endl;

    // }

    // __ INVENTORY TEST HARNESS __

    // Player* player = new Player("Rice");
    // ItemFactory* af = new ArmorFactory();
    // ItemFactory* wf = new WeaponFactory();

    // cout << "Player's Inventory's Armor Size: " << player->getInventory().getArmor().size() << endl;
    // cout << "Player's Inventory's Weapons Size: " << player->getInventory().getWeapons().size() << endl << endl;

    // cout << "Adding Leather Armor to Player's Inventory..." << endl << endl;
    // player->addArmorToInventory("Leather Armor", af);
    // cout << "Adding Stone Sword to Player's Inventory..." << endl << endl;
    // player->addWeaponToInventory("Stone Sword", wf);

    // cout << "Player's Inventory's Armor Size: " << player->getInventory().getArmor().size() << endl;
    // cout << "Player's Inventory's Weapons Size: " << player->getInventory().getWeapons().size() << endl << endl;   

    // cout << "Player's Inventory's Leather Armor ATK: " << player->getInventory().getItem("Leather Armor")->combatStats->ATK << endl;
    // cout << "Player's Inventory's Leather Armor DEF: " << player->getInventory().getItem("Leather Armor")->combatStats->DEF << endl;
    // cout << "Player's Inventory's Leather Armor HP: " << player->getInventory().getItem("Leather Armor")->combatStats->HP << endl;
    // cout << "Player's Inventory's Leather Armor maxHP: " << player->getInventory().getItem("Leather Armor")->combatStats->maxHP << endl << endl;

    // cout << "Player's Inventory's Stone Sword ATK: " << player->getInventory().getItem("Stone Sword")->combatStats->ATK << endl;
    // cout << "Player's Inventory's Stone Sword DEF: " << player->getInventory().getItem("Stone Sword")->combatStats->DEF << endl;
    // cout << "Player's Inventory's Stone Sword HP: " << player->getInventory().getItem("Stone Sword")->combatStats->HP << endl;
    // cout << "Player's Inventory's Stone Sword maxHP: " << player->getInventory().getItem("Stone Sword")->combatStats->maxHP << endl << endl;   

    // cout << "Player's Equipped's Armor Size: " << player->getEquipped().getArmor().size() << endl;
    // cout << "Player's Equipped's Weapons Size: " << player->getEquipped().getWeapons().size() << endl << endl;

    // cout << "Equipping Leather Armor..." << endl << endl;
    // player->equipArmor("Leather Armor");
    // cout << "Equipping Stone Sword..." << endl << endl;
    // player->equipWeapon("Stone Sword");

    // cout << "Player's Equipped's Armor Size: " << player->getEquipped().getArmor().size() << endl;
    // cout << "Player's Equipped's Weapons Size: " << player->getEquipped().getWeapons().size() << endl << endl;

    // cout << "Player's Equipped's Leather Armor ATK: " << player->getEquipped().getItem("Leather Armor")->combatStats->ATK << endl;
    // cout << "Player's Equipped's Leather Armor DEF: " << player->getEquipped().getItem("Leather Armor")->combatStats->DEF << endl;
    // cout << "Player's Equipped's Leather Armor HP: " << player->getEquipped().getItem("Leather Armor")->combatStats->HP << endl;
    // cout << "Player's Equipped's Leather Armor maxHP: " << player->getEquipped().getItem("Leather Armor")->combatStats->maxHP << endl << endl;

    // cout << "Player's Equipped's Stone Sword ATK: " << player->getEquipped().getItem("Stone Sword")->combatStats->ATK << endl;
    // cout << "Player's Equipped's Stone Sword DEF: " << player->getEquipped().getItem("Stone Sword")->combatStats->DEF << endl;
    // cout << "Player's Equipped's Stone Sword HP: " << player->getEquipped().getItem("Stone Sword")->combatStats->HP << endl;
    // cout << "Player's Equipped's Stone Sword maxHP: " << player->getEquipped().getItem("Stone Sword")->combatStats->maxHP << endl << endl;  
    
    // cout << "Player's Inventory's Armor Size: " << player->getInventory().getArmor().size() << endl;
    // cout << "Player's Inventory's Weapons Size: " << player->getInventory().getWeapons().size() << endl << endl;

    // cout << "Adding Iron Armor to Player's Inventory..." << endl << endl;
    // player->addArmorToInventory("Iron Armor", af);
    // cout << "Adding Iron Sword to Player's Inventory..." << endl << endl;
    // player->addWeaponToInventory("Iron Sword", wf);

    // cout << "Player's Inventory's Armor Size: " << player->getInventory().getArmor().size() << endl;
    // cout << "Player's Inventory's Weapons Size: " << player->getInventory().getWeapons().size() << endl << endl;

    // cout << "Player's Inventory's Iron Armor ATK: " << player->getInventory().getItem("Iron Armor")->combatStats->ATK << endl;
    // cout << "Player's Inventory's Iron Armor DEF: " << player->getInventory().getItem("Iron Armor")->combatStats->DEF << endl;
    // cout << "Player's Inventory's Iron Armor HP: " << player->getInventory().getItem("Iron Armor")->combatStats->HP << endl;
    // cout << "Player's Inventory's Iron Armor maxHP: " << player->getInventory().getItem("Iron Armor")->combatStats->maxHP << endl << endl;

    // cout << "Player's Inventory's Iron Sword ATK: " << player->getInventory().getItem("Iron Sword")->combatStats->ATK << endl;
    // cout << "Player's Inventory's Iron Sword DEF: " << player->getInventory().getItem("Iron Sword")->combatStats->DEF << endl;
    // cout << "Player's Inventory's Iron Sword HP: " << player->getInventory().getItem("Iron Sword")->combatStats->HP << endl;
    // cout << "Player's Inventory's Iron Sword maxHP: " << player->getInventory().getItem("Iron Sword")->combatStats->maxHP << endl << endl;  

    // cout << "Player's Equipped's Armor Size: " << player->getEquipped().getArmor().size() << endl;
    // cout << "Player's Equipped's Weapons Size: " << player->getEquipped().getWeapons().size() << endl << endl;

    // cout << "Equipping Iron Armor..." << endl << endl;
    // player->equipArmor("Iron Armor");
    // cout << "Equipping Iron Sword..." << endl << endl;
    // player->equipWeapon("Iron Sword");

    // cout << "Player's Equipped's Armor Size: " << player->getEquipped().getArmor().size() << endl;
    // cout << "Player's Equipped's Weapons Size: " << player->getEquipped().getWeapons().size() << endl << endl;

    // cout << "Player's Equipped's Iron Armor ATK: " << player->getEquipped().getItem("Iron Armor")->combatStats->ATK << endl;
    // cout << "Player's Equipped's Iron Armor DEF: " << player->getEquipped().getItem("Iron Armor")->combatStats->DEF << endl;
    // cout << "Player's Equipped's Iron Armor HP: " << player->getEquipped().getItem("Iron Armor")->combatStats->HP << endl;
    // cout << "Player's Equipped's Iron Armor maxHP: " << player->getEquipped().getItem("Iron Armor")->combatStats->maxHP << endl << endl;

    // cout << "Player's Equipped's Iron Sword ATK: " << player->getEquipped().getItem("Iron Sword")->combatStats->ATK << endl;
    // cout << "Player's Equipped's Iron Sword DEF: " << player->getEquipped().getItem("Iron Sword")->combatStats->DEF << endl;
    // cout << "Player's Equipped's Iron Sword HP: " << player->getEquipped().getItem("Iron Sword")->combatStats->HP << endl;
    // cout << "Player's Equipped's Iron Sword maxHP: " << player->getEquipped().getItem("Iron Sword")->combatStats->maxHP << endl << endl; 

    
    // cout << "Removing Leather Armor from Player's Inventory..." << endl;
    // player->removeItemFromInventory("Leather Armor");
    // cout << "Removing Iron Sword from Player's Inventory..." << endl << endl;
    // player->removeItemFromInventory("Iron Sword");


    // __ ITEM FACTORY, ENEMY FACTORY, AND PLAYER INSTANTIATION TEST HARNESS __

    // ItemFactory* af = new ArmorFactory();
    // Item* armor = af->createItem("Iron Armor");

    // cout << "Armor Name: " << armor->getName() << endl;
    // cout << "Armor Cost: " << armor->getCost() << endl;
    // cout << "Armor ATK: " << armor->combatStats->ATK << endl;
    // cout << "Armor DEF: " << armor->combatStats->DEF << endl << endl;

    // armor->setName("Super cool Iron Armor");
    // armor->setCost(9999);
    // armor->combatStats->ATK = 1;
    // armor->combatStats->DEF = 999;

    // cout << "Armor Name: " << armor->getName() << endl;
    // cout << "Armor Cost: " << armor->getCost() << endl;
    // cout << "Armor ATK: " << armor->combatStats->ATK << endl;
    // cout << "Armor DEF: " << armor->combatStats->DEF << endl << endl;
    
    // ItemFactory* wf = new WeaponFactory();
    // Item* weapon = wf->createItem("Stone Sword");

    // cout << "Weapon Name: " << weapon->getName() << endl;
    // cout << "Weapon Cost: " << weapon->getCost() << endl;
    // cout << "Weapon ATK: " << weapon->combatStats->ATK << endl;
    // cout << "Weapon DEF: " << weapon->combatStats->DEF << endl << endl;
    
    // weapon->setName("Super cool Stone Sword");
    // weapon->setCost(9999);
    // weapon->combatStats->ATK = 999;
    // weapon->combatStats->DEF = 1;

    // cout << "Weapon Name: " << weapon->getName() << endl;
    // cout << "Weapon Cost: " << weapon->getCost() << endl;
    // cout << "Weapon ATK: " << weapon->combatStats->ATK << endl;
    // cout << "Weapon DEF: " << weapon->combatStats->DEF << endl << endl;

    

    // Player* player = new Player("Rice");

    // cout << "Player Name: " << player->getName() << endl;
    // cout << "Player HP: " << player->combatStats->HP << endl;
    // cout << "Player Gold: " << player->getGold() << endl;
    // cout << "Player Level: " << player->getLevel() << endl;
    // cout << "Player maxHP: " << player->combatStats->maxHP << endl;
    // cout << "Player EXP: " << player->getEXP() << endl;
    // cout << "Player ATK: " << player->combatStats->ATK << endl;
    // cout << "Player DEF: " << player->combatStats->DEF << endl << endl;

    // player->setName("Fang");
    // player->combatStats->HP = 99;
    // player->setGold(500);
    // player->setLevel(2);
    // player->combatStats->maxHP = 100;
    // player->setEXP(1);
    // player->combatStats->ATK = 2;
    // player->combatStats->DEF = 2;

    // cout << "Player Name: " << player->getName() << endl;
    // cout << "Player HP: " << player->combatStats->HP << endl;
    // cout << "Player maxHP: " << player->combatStats->maxHP << endl;
    // cout << "Player Gold: " << player->getGold() << endl;
    // cout << "Player Level: " << player->getLevel() << endl;
    // cout << "Player EXP: " << player->getEXP() << endl;
    // cout << "Player ATK: " << player->combatStats->ATK << endl;
    // cout << "Player DEF: " << player->combatStats->DEF << endl << endl;

    // cout << "Restoring HP..." << endl;
    // player->restoreHP();
    // cout << "Player HP: " << player->combatStats->HP << endl << endl;

    // EnemyFactory* ef = new EnemyFactory(); // instantiate all enemy prototypes at once
    // Enemy* enemy = ef->createEnemy("Green Slime");

    // cout << "Enemy Name: " << enemy->getName() << endl;
    // cout << "Enemy HP: " << enemy->combatStats->HP << endl;
    // cout << "Enemy maxHP: " << enemy->combatStats->maxHP << endl;
    // cout << "Enemy description: " << enemy->getDescription() << endl;
    // cout << "Enemy ATK: " << enemy->combatStats->ATK << endl;
    // cout << "Enemy DEF: " << enemy->combatStats->DEF << endl << endl;

    // enemy->setName("Mega Goblin");
    // enemy->combatStats->HP = 1000;
    // enemy->combatStats->maxHP = 1001;
    // enemy->combatStats->ATK = 50;
    // enemy->combatStats->DEF = 60;
    // enemy->setDescription("It's a mega goblin... good luck, adventurer.");

    // cout << "Enemy Name: " << enemy->getName() << endl;
    // cout << "Enemy HP: " << enemy->combatStats->HP << endl;
    // cout << "Enemy maxHP: " << enemy->combatStats->maxHP << endl;
    // cout << "Enemy description: " << enemy->getDescription() << endl;
    // cout << "Enemy ATK: " << enemy->combatStats->ATK << endl;
    // cout << "Enemy DEF: " << enemy->combatStats->DEF << endl << endl;

    // Enemy* enemy2 = ef->createEnemy("Green Slime");

    // cout << "Enemy2 Name: " << enemy2->getName() << endl;
    // cout << "Enemy2 HP: " << enemy2->combatStats->HP << endl;
    // cout << "Enemy2 maxHP: " << enemy2->combatStats->maxHP << endl;
    // cout << "Enemy2 description: " << enemy2->getDescription() << endl;
    // cout << "Enemy2 ATK: " << enemy2->combatStats->ATK << endl;
    // cout << "Enemy2 DEF: " << enemy2->combatStats->DEF << endl << endl;

    // enemy = ef->createEnemy("Zombie"); // we lost the pointer to Mega Goblin
    
    // cout << "Enemy Name: " << enemy->getName() << endl;
    // cout << "Enemy HP: " << enemy->combatStats->HP << endl;
    // cout << "Enemy maxHP: " << enemy->combatStats->maxHP << endl;
    // cout << "Enemy description: " << enemy->getDescription() << endl;
    // cout << "Enemy ATK: " << enemy->combatStats->ATK << endl;
    // cout << "Enemy DEF: " << enemy->combatStats->DEF << endl << endl;
    
}
