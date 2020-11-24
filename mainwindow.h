#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>
#include <cmath>

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

    int count = 0;

    void update_main_menu_player_stats();
    void update_battle_menu_player_stats();
    void update_battle_menu_enemy_stats();

private slots:

    // functions
    void initializePlayer();
    void enterArea();
    void initializeBattleWithEnemy();
    void nextTurn();

    // switch between menu pages
    void switchToMainMenu();
    void switchToBattleMenu();
};

#endif // MAINWINDOW_H
