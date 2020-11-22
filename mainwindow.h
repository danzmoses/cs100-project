#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "header/Player.h"
#include "header/Enemy.h"
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
    Player* player;

private slots:
    //
    void switchToMainMenu();
    void switchToBattleMenu();
    void initializePlayer();
};

#endif // MAINWINDOW_H
