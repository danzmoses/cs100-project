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
    delete player;
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

void MainWindow::initializePlayer()
{
    std::string name = ui->enter_name_lineedit->text().toStdString();
    if (name.empty())
        name = "Hero";

    player = new Player(name);
    update_main_menu_player_stats();
    //ui->battle_menu_player_name_and_level->setText(name + " (Level " + level + ")");
}

void MainWindow::enterArea()
{
    area_enemies.push_back(ef.createEnemy("Green Slime"));
}

void MainWindow::battleEnemy()
{
    ;
}

void MainWindow::switchToMainMenu()
{
    ui->menu_pages->setCurrentIndex(1);
}

void MainWindow::switchToBattleMenu()
{
    ui->menu_pages->setCurrentIndex(2);
}
