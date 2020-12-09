#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <cmath>
#include <random>
#include <time.h>
#include <vector>
#include <queue>

#include "header/Player.h"
#include "header/Enemy.h"
#include "header/EnemyFactory.h"
#include "header/battle/Battle.h"
#include "header/WeaponFactory.h"
#include "header/ArmorFactory.h"
#include "header/Shop.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Player* player = nullptr;
    Enemy* current_enemy = nullptr;
    Battle* battle = nullptr;
    EnemyFactory ef;
    ItemFactory* weaponFactory = new WeaponFactory;
    ItemFactory* armorFactory = new ArmorFactory;
    CardFactory* cardFactory = new CardFactory;
    std::vector<Enemy*> area_enemies;
    int areaEnemiesCount;
    Shop shop;

private slots:

    // functions
    void initializePlayer();
    void enterArea();
    void initializeBattleWithEnemy();
    void nextTurn();
    void nextBattle();
    void endArea();

    void updateMainMenuPlayerStats();
    void update_battle_menu_player_stats();
    void update_battle_menu_enemy_stats();
    void updateEquipmentMenuPlayerStats();
    void updateEquipmentMenuCurrentlySelectedCard();
    void updateShopMenuPlayerStats();
    void updateShopMenuInventory();
    void updateShopMenuCurrentlySelectedItem();

    void selectInventoryItemType();
    void selectShopItemType();
    void equipItem();
    void purchaseItem();

    // switch between menu pages
    void switchToMainMenu();
    void switchToBattleMenu();
    void switchToShopMenu();
    void switchToEquipmentMenu();
};

#endif // MAINWINDOW_H
