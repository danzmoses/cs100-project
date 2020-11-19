#include <iostream>
#include "../header/Entity.h"
#include "../header/prototypes/enemies/EnemyPrototype.h"
#include "../header/prototypes/enemies/GoblinPrototype.h"

using namespace std;

int main()
{
    Entity* goblin = new GoblinPrototype("Goblin", 25);
    cout << "Name: " << goblin->getName() << endl;
    cout << "Health: " << goblin->getHealth() << endl;

    goblin->setName("Spear Goblin");
    goblin->setHealth(100);

    cout << "Name: " << goblin->getName() << endl;
    cout << "Health: " << goblin->getHealth() << endl;

}