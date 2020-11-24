#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const QSize BUTTON_SIZE = QSize(100, 10);
    ui->rollButton->setMinimumSize(BUTTON_SIZE);


    // connections

    connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(switchToMainMenu()));
    connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(initializePlayer()));
    connect(ui->battleButton, SIGNAL(clicked(bool)), this, SLOT(switchToBattleMenu()));
    connect(ui->battleButton, SIGNAL(clicked(bool)), this, SLOT(enterArea()));
    connect(ui->rollButton, SIGNAL(clicked(bool)), this, SLOT(nextTurn()));
    connect(ui->returnToMainMenuButton, SIGNAL(clicked(bool)), this, SLOT(switchToMainMenu()));
}

MainWindow::~MainWindow()
{
    if (player != nullptr)
        delete player;
    if (battle != nullptr)
        delete battle;
    delete ui;
}

void MainWindow::update_main_menu_player_stats()
{
    ui->main_menu_name->setText("Name: " + QString::fromStdString(player->getName()));
    ui->main_menu_level->setText("Level: " + QString::number(player->getLevel()));
    ui->main_menu_exp->setText("EXP: " + QString::number(player->getEXP()) + '/' + QString::number(player->getMaxEXP()));
    ui->main_menu_health->setText("Health: " + QString::number(player->getHP()) + '/' + QString::number(player->getMaxHP()));
    ui->main_menu_attack->setText("ATK: " + QString::number(player->getATK()));
    ui->main_menu_defense->setText("DEF: " + QString::number(player->getDEF()));
}

void MainWindow::update_battle_menu_player_stats()
{
    QString name = QString::fromStdString(player->getName());
    QString hp = QString::number(player->getHP());
    QString maxHP = QString::number(player->getMaxHP());
    QString level = QString::number(player->getLevel());
    QString exp = QString::number(player->getEXP());
    QString maxEXP = QString::number(player->getMaxEXP());
    QString atk = QString::number(player->getATK());
    QString def = QString::number(player->getDEF());

    ui->battle_menu_player_name_and_level->setText(name + " (Level " + level + ")");
    ui->battle_menu_player_health->setText("Health: " + hp + '/' + maxHP);
    ui->battle_menu_player_exp->setText("EXP: " + exp + '/' + maxEXP);
    ui->battle_menu_player_atk->setText("ATK: " + atk);
    ui->battle_menu_player_def->setText("DEF: " + def);
}

void MainWindow::update_battle_menu_enemy_stats()
{
    QString name = QString::fromStdString(current_enemy->getName());
    QString hp = QString::number(current_enemy->getHP());
    QString maxHP = QString::number(current_enemy->getMaxHP());
    QString level = QString::number(current_enemy->getLevel());
    QString atk = QString::number(current_enemy->getATK());
    QString def = QString::number(current_enemy->getDEF());

    ui->battle_menu_enemy_name_and_level->setText(name + " (Level " + level + ")");
    ui->battle_menu_enemy_health->setText("Health: " + hp + '/' + maxHP);
    ui->battle_menu_enemy_atk->setText("ATK: " + atk);
    ui->battle_menu_enemy_def->setText("DEF: " + def);
}

void MainWindow::initializePlayer()
{
    std::string name = ui->enter_name_lineedit->text().toStdString();
    if (name.empty())
        name = "Hero";

    player = new Player(name);
    update_main_menu_player_stats();
}

void MainWindow::enterArea()
{
    if (count == 0)
        area_enemies.push_back(ef.createEnemy("Green Slime"));
    else
        area_enemies.push_back(ef.createEnemy("Goblin"));
    initializeBattleWithEnemy();
}

void MainWindow::initializeBattleWithEnemy()
{
    ui->rollButton->setEnabled(true);
    ui->returnToMainMenuButton->setEnabled(false);
    ui->battle_menu_battle_result->clear();
    if (battle != nullptr)
        delete battle;
    current_enemy = area_enemies[area_enemies.size() - 1];
    battle = new Battle(player, current_enemy);

    update_battle_menu_player_stats();
    update_battle_menu_enemy_stats();
}

void MainWindow::nextTurn()
{
    battle->nextTurn();
    QString playerRoll = QString::number(battle->getPlayerRoll());
    QString enemyRoll = QString::number(battle->getEnemyRoll());
    QString rollDifference = QString::number(abs(playerRoll.toInt() - enemyRoll.toInt()));

    QString damageDone = QString::number(battle->getDamageDone());
    QString playerName = QString::fromStdString(player->getName());
    QString enemyName = QString::fromStdString(current_enemy->getName());

    ui->battle_menu_player_roll->setText(playerName + " Roll: " + playerRoll);
    ui->battle_menu_enemy_roll->setText(enemyName + " Roll: " + enemyRoll);

    if (battle->getPlayerWonRoll())
    {
        ui->battle_menu_turn_result->setText(playerName + " deals " + damageDone + " damage to " + enemyName + "!");
    }
    else
        ui->battle_menu_turn_result->setText(enemyName + " deals " + damageDone + " damage to " + playerName + "!");

    ui->battle_menu_roll_difference->setText("Roll difference: " + rollDifference);

    if (player->getHP() <= 0 || current_enemy->getHP() <= 0)
    {
        if (player->getHP() <= 0)
            ui->battle_menu_battle_result->setText(enemyName + " has won!");
        else if (current_enemy->getHP() <= 0)
            ui->battle_menu_battle_result->setText(playerName + " has won!");
        ++count;
        ui->rollButton->setEnabled(false);
        ui->returnToMainMenuButton->setEnabled(true);
    }
    update_battle_menu_player_stats();
    update_battle_menu_enemy_stats();
}

void MainWindow::switchToMainMenu()
{
    ui->menu_pages->setCurrentIndex(1);
}

void MainWindow::switchToBattleMenu()
{
    ui->menu_pages->setCurrentIndex(2);
}
