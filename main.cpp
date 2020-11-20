#include <iostream>
#include "header/PlayerFactory.h"
#include "header/EnemyFactory.h"

using namespace std;

int main()
{
    EntityFactory* pf = new PlayerFactory();
    Entity* player = pf->createEntity("Linda");

    cout << "Player Name: " << player->getName() << endl;
    cout << "Player Health: " << player->getHealth() << endl << endl;

    player->setName("Royce");
    player->setHealth(99);

    cout << "Player Name: " << player->getName() << endl;
    cout << "Player Health: " << player->getHealth() << endl << endl;

    cout << "Player Gold: " << player->getGold() << endl;
    player->setGold(5000);
    cout << "Player Gold: " << player->getGold() << endl;
}
