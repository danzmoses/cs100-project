//#include "Battle.h"
//#include "../Player.h"
//#include "../Enemy.h"

//#include <iostream>
//#include <random>
//#include <time.h>
//using namespace std;

//int main()
//{
//    srand(time(0));
//    Player* player = new Player();
//    Enemy* enemy = new Enemy();

//    player->setATK(1);
//    player->setDEF(0);
//    player->setHP(5);

//    enemy->setATK(1);
//    enemy->setDEF(0);
//    enemy->setHP(5);

//    Battle* battle = new Battle(player, enemy);

//    cout << "Player HP: " << player->getHP() << endl;
//    cout << "Enemy HP: " << enemy->getHP() << endl << endl;

//    while (player->getHP() > 0 && enemy->getHP() > 0)
//    {
//        battle->nextTurn();
//        cout << "Player roll: " << battle->getPlayerRoll() << endl;
//        cout << "Enemy roll: " << battle->getEnemyRoll() << endl;

//        if (battle->getPlayerWonRoll())
//            cout << "Player won the roll." << endl;
//        else
//            cout << "Enemy won the roll." << endl;
      

//        cout << "Player HP: " << player->getHP() << endl;
//        cout << "Enemy HP: " << enemy->getHP() << endl << endl;

//        cout << "-------------------------------------------------" << endl;
//    }

//    if (player->getHP() <= 0)
//        cout << "Player has been defeated!" << endl;
//    else
//        cout << "Enemy has been defeated!" << endl;
//}
