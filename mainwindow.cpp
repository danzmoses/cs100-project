#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const QSize BUTTON_SIZE = QSize(100, 10);
    ui->pushButton_5->setMinimumSize(BUTTON_SIZE);


    // connections

    connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(switchToMainMenu()));
    connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(initializePlayer()));
    connect(ui->battleButton, SIGNAL(clicked(bool)), this, SLOT(switchToBattleMenu()));
    connect(ui->battleButton, SIGNAL(clicked(bool)), this, SLOT(enterArea()));
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
        player = new Player();
    else
        player = new Player(name);
    update_main_menu_player_stats();
}

void MainWindow::enterArea()
{
    area_enemies.push_back(ef.createEnemy("Goblin"));
    initializeBattleWithEnemy();
}

void MainWindow::initializeBattleWithEnemy()
{
    if (battle != nullptr)
        delete battle;
    current_enemy = area_enemies[area_enemies.size() - 1];
    battle = new Battle(player, current_enemy);

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
