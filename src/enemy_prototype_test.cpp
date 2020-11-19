#include <iostream>
#include "../header/Entity.h"
#include "../header/prototypes/enemies/EnemyPrototype.h"
#include "../header/prototypes/enemies/GoblinPrototype.h"

using namespace std;

int main()
{
    EnemyPrototype* goblin = new GoblinPrototype("Spear Goblin", 10);
    cout << "Name: " << goblin->getName() << endl;
    cout << "Health: " << goblin->getHealth() << endl;

    goblin->Clone();

    cout << "Name: " << goblin->getName() << endl;
    cout << "Health: " << goblin->getHealth() << endl;
    // only Use Clone() for prototype objects

}