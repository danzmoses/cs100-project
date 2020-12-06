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
    std::vector<Enemy*> area_enemies;

private slots:

    // functions
    void initializePlayer();
    void enterArea();
    void initializeBattleWithEnemy();
    void nextTurn();
    void endArea();

    void update_main_menu_player_stats();
    void update_battle_menu_player_stats();
    void update_battle_menu_enemy_stats();

    void selectInventoryItemType();

    // switch between menu pages
    void switchToMainMenu();
    void switchToBattleMenu();
    void switchToEquipmentMenu();
};

#endif // MAINWINDOW_H
