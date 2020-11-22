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
}

MainWindow::~MainWindow()
{
    delete player;
    delete ui;
}

void MainWindow::initializePlayer()
{
    QString name = ui->enter_name_lineedit->text();
    player = new Player(name.toStdString());
    ui->main_menu_name_label->setText(QString("Name: ") + name);
}

void MainWindow::switchToMainMenu()
{
    ui->menu_pages->setCurrentIndex(1);
}

void MainWindow::switchToBattleMenu()
{
    ui->menu_pages->setCurrentIndex(2);
}
