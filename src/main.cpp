#include <iostream>

#include "../header/Player.h"
#include "../header/Item.h"
#include "../header/EnemyFactory.h"
#include "../header/ArmorFactory.h"
#include "../header/WeaponFactory.h"

using namespace std;

int main()
{

    // __ INVENTORY TEST HARNESS __

    Player* player = new Player("Rice");
    ItemFactory* af = new ArmorFactory();
    ItemFactory* wf = new WeaponFactory();

    cout << "Player's Inventory's Armor Size: " << player->getInventory().getArmor().size() << endl;
    cout << "Player's Inventory's Weapons Size: " << player->getInventory().getWeapons().size() << endl << endl;

    cout << "Adding Leather Armor to Player's Inventory..." << endl << endl;
    player->addArmorToInventory("Leather Armor", af);
    cout << "Adding Stone Sword to Player's Inventory..." << endl << endl;
    player->addWeaponToInventory("Stone Sword", wf);

    cout << "Player's Inventory's Armor Size: " << player->getInventory().getArmor().size() << endl;
    cout << "Player's Inventory's Weapons Size: " << player->getInventory().getWeapons().size() << endl << endl;   

    cout << "Player's Inventory's Leather Armor ATK: " << player->getInventory().findItem("Leather Armor")->combatStats->ATK << endl;
    cout << "Player's Inventory's Leather Armor DEF: " << player->getInventory().findItem("Leather Armor")->combatStats->DEF << endl;
    cout << "Player's Inventory's Leather Armor HP: " << player->getInventory().findItem("Leather Armor")->combatStats->HP << endl;
    cout << "Player's Inventory's Leather Armor maxHP: " << player->getInventory().findItem("Leather Armor")->combatStats->maxHP << endl << endl;

    cout << "Player's Inventory's Stone Sword ATK: " << player->getInventory().findItem("Stone Sword")->combatStats->ATK << endl;
    cout << "Player's Inventory's Stone Sword DEF: " << player->getInventory().findItem("Stone Sword")->combatStats->DEF << endl;
    cout << "Player's Inventory's Stone Sword HP: " << player->getInventory().findItem("Stone Sword")->combatStats->HP << endl;
    cout << "Player's Inventory's Stone Sword maxHP: " << player->getInventory().findItem("Stone Sword")->combatStats->maxHP << endl << endl;   

    cout << "Player's Equipped's Armor Size: " << player->getInventory().getArmor().size() << endl;
    cout << "Player's Equipped's Weapons Size: " << player->getInventory().getWeapons().size() << endl << endl;

    cout << "Equipping Leather Armor..." << endl << endl;
    player->equipArmor("Leather Armor");
    cout << "Equipping Stone Sword..." << endl << endl;
    player->equipWeapon("Stone Sword");

    cout << "Player's Equipped's Armor Size: " << player->getInventory().getArmor().size() << endl;
    cout << "Player's Equipped's Weapons Size: " << player->getInventory().getWeapons().size() << endl << endl;

    cout << "Player's Equipped's Leather Armor ATK: " << player->getEquipped().findItem("Leather Armor")->combatStats->ATK << endl;
    cout << "Player's Equipped's Leather Armor DEF: " << player->getEquipped().findItem("Leather Armor")->combatStats->DEF << endl;
    cout << "Player's Equipped's Leather Armor HP: " << player->getEquipped().findItem("Leather Armor")->combatStats->HP << endl;
    cout << "Player's Equipped's Leather Armor maxHP: " << player->getEquipped().findItem("Leather Armor")->combatStats->maxHP << endl << endl;

    cout << "Player's Equipped's Stone Sword ATK: " << player->getEquipped().findItem("Stone Sword")->combatStats->ATK << endl;
    cout << "Player's Equipped's Stone Sword DEF: " << player->getEquipped().findItem("Stone Sword")->combatStats->DEF << endl;
    cout << "Player's Equipped's Stone Sword HP: " << player->getEquipped().findItem("Stone Sword")->combatStats->HP << endl;
    cout << "Player's Equipped's Stone Sword maxHP: " << player->getEquipped().findItem("Stone Sword")->combatStats->maxHP << endl << endl;  
    
    cout << "Player's Inventory's Armor Size: " << player->getInventory().getArmor().size() << endl;
    cout << "Player's Inventory's Weapons Size: " << player->getInventory().getWeapons().size() << endl << endl;

    cout << "Adding Iron Armor to Player's Inventory..." << endl << endl;
    player->addArmorToInventory("Iron Armor", af);
    cout << "Adding Iron Sword to Player's Inventory..." << endl << endl;
    player->addWeaponToInventory("Iron Sword", wf);

    cout << "Player's Inventory's Armor Size: " << player->getInventory().getArmor().size() << endl;
    cout << "Player's Inventory's Weapons Size: " << player->getInventory().getWeapons().size() << endl << endl;

    cout << "Player's Inventory's Iron Armor ATK: " << player->getInventory().findItem("Iron Armor")->combatStats->ATK << endl;
    cout << "Player's Inventory's Iron Armor DEF: " << player->getInventory().findItem("Iron Armor")->combatStats->DEF << endl;
    cout << "Player's Inventory's Iron Armor HP: " << player->getInventory().findItem("Iron Armor")->combatStats->HP << endl;
    cout << "Player's Inventory's Iron Armor maxHP: " << player->getInventory().findItem("Iron Armor")->combatStats->maxHP << endl << endl;

    cout << "Player's Inventory's Iron Sword ATK: " << player->getInventory().findItem("Iron Sword")->combatStats->ATK << endl;
    cout << "Player's Inventory's Iron Sword DEF: " << player->getInventory().findItem("Iron Sword")->combatStats->DEF << endl;
    cout << "Player's Inventory's Iron Sword HP: " << player->getInventory().findItem("Iron Sword")->combatStats->HP << endl;
    cout << "Player's Inventory's Iron Sword maxHP: " << player->getInventory().findItem("Iron Sword")->combatStats->maxHP << endl << endl;  

    cout << "Player's Equipped's Armor Size: " << player->getInventory().getArmor().size() << endl;
    cout << "Player's Equipped's Weapons Size: " << player->getInventory().getWeapons().size() << endl << endl;

    cout << "Equipping Iron Armor..." << endl << endl;
    player->equipArmor("Iron Armor");
    cout << "Equipping Iron Sword..." << endl << endl;
    player->equipWeapon("Iron Sword");

    cout << "Player's Equipped's Armor Size: " << player->getInventory().getArmor().size() << endl;
    cout << "Player's Equipped's Weapons Size: " << player->getInventory().getWeapons().size() << endl << endl;

    cout << "Player's Equipped's Iron Armor ATK: " << player->getEquipped().findItem("Iron Armor")->combatStats->ATK << endl;
    cout << "Player's Equipped's Iron Armor DEF: " << player->getEquipped().findItem("Iron Armor")->combatStats->DEF << endl;
    cout << "Player's Equipped's Iron Armor HP: " << player->getEquipped().findItem("Iron Armor")->combatStats->HP << endl;
    cout << "Player's Equipped's Iron Armor maxHP: " << player->getEquipped().findItem("Iron Armor")->combatStats->maxHP << endl << endl;

    cout << "Player's Equipped's Iron Sword ATK: " << player->getEquipped().findItem("Iron Sword")->combatStats->ATK << endl;
    cout << "Player's Equipped's Iron Sword DEF: " << player->getEquipped().findItem("Iron Sword")->combatStats->DEF << endl;
    cout << "Player's Equipped's Iron Sword HP: " << player->getEquipped().findItem("Iron Sword")->combatStats->HP << endl;
    cout << "Player's Equipped's Iron Sword maxHP: " << player->getEquipped().findItem("Iron Sword")->combatStats->maxHP << endl << endl; 


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
