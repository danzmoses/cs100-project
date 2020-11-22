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

    connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(switch_to_main_menu()));
    connect(ui->battleButton, SIGNAL(clicked(bool)), this, SLOT(switch_to_battle_menu()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switch_to_main_menu()
{
    ui->menu_pages->setCurrentIndex(1);
}

void MainWindow::switch_to_battle_menu()
{
    ui->menu_pages->setCurrentIndex(2);
}
