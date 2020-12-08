#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const QSize BUTTON_SIZE = QSize(100, 10);
    ui->rollButton->setMinimumSize(BUTTON_SIZE);

    srand(time(0));
    // connections
    connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(initializePlayer()));
    connect(ui->battleButton, SIGNAL(clicked(bool)), this, SLOT(enterArea()));
    connect(ui->rollButton, SIGNAL(clicked(bool)), this, SLOT(nextTurn()));
    connect(ui->returnToMainMenuButton, SIGNAL(clicked(bool)), this, SLOT(endArea()));
    connect(ui->changeEquipmentButton, SIGNAL(clicked(bool)), this, SLOT(switchToEquipmentMenu()));
    connect(ui->equipmentReturnToMainMenuButton, SIGNAL(clicked(bool)), this, SLOT(switchToMainMenu()));
    connect(ui->goToShopButton, SIGNAL(clicked(bool)), this, SLOT(switchToShopMenu()));
    connect(ui->shopReturnToMainMenuButton, SIGNAL(clicked(bool)), this, SLOT(switchToMainMenu()));
    connect(ui->nextBattleButton, SIGNAL(clicked(bool)), this, SLOT(nextBattle()));

    // switch inventory item type
    connect(ui->viewInventoryWeaponsRadioButton, SIGNAL(clicked(bool)), this, SLOT(selectInventoryItemType()));
    connect(ui->viewInventoryArmorRadioButton, SIGNAL(clicked(bool)), this, SLOT(selectInventoryItemType()));
    connect(ui->viewInventoryBootsRadioButton, SIGNAL(clicked(bool)), this, SLOT(selectInventoryItemType()));
    connect(ui->viewInventoryCardsRadioButton, SIGNAL(clicked(bool)), this, SLOT(selectInventoryItemType()));

    connect(ui->equipmentEquipButton, SIGNAL(clicked(bool)), this, SLOT(equipItem()));
}

MainWindow::~MainWindow()
{
    if (player != nullptr)
        delete player;
    if (battle != nullptr)
        delete battle;
    delete weaponFactory;
    delete armorFactory;
    delete ui;
}

void MainWindow::update_main_menu_player_stats()
{
    ui->main_menu_name->setText("Name: " + QString::fromStdString(player->getName()));
    ui->main_menu_level->setText("Level: " + QString::number(player->getLevel()));
    ui->main_menu_exp->setText("EXP: " + QString::number(player->getEXP()) + '/' + QString::number(player->getMaxEXP()));
    ui->main_menu_health->setText("Health: " + QString::number(player->combatStats->HP) + '/' + QString::number(player->combatStats->maxHP));
    ui->main_menu_attack->setText("ATK: " + QString::number(player->combatStats->ATK));
    ui->main_menu_defense->setText("DEF: " + QString::number(player->combatStats->DEF));

    Inventory equipped = player->getEquipped();
    if (!equipped.getWeapons().empty())
        ui->mainMenuWeaponLabel->setText("Weapon: " + QString::fromStdString(equipped.getWeapons().at(0)->getName()));
    else
        ui->mainMenuWeaponLabel->setText("Weapon: <None>");

    if (!equipped.getArmor().empty())
        ui->mainMenuArmorLabel->setText("Armor: " + QString::fromStdString(equipped.getArmor().at(0)->getName()));
    else
        ui->mainMenuArmorLabel->setText("Armor: <None>");
}

void MainWindow::update_battle_menu_player_stats()
{
    QString name = QString::fromStdString(player->getName());
    QString hp = QString::number(player->combatStats->HP);
    QString maxHP = QString::number(player->combatStats->maxHP);
    QString level = QString::number(player->getLevel());
    QString exp = QString::number(player->getEXP());
    QString maxEXP = QString::number(player->getMaxEXP());
    QString atk = QString::number(player->combatStats->ATK);
    QString def = QString::number(player->combatStats->DEF);

    ui->battle_menu_player_name_and_level->setText(name + " (Level " + level + ")");
    ui->battle_menu_player_health->setText("Health: " + hp + '/' + maxHP);
    ui->battle_menu_player_exp->setText("EXP: " + exp + '/' + maxEXP);
    ui->battle_menu_player_atk->setText("ATK: " + atk);
    ui->battle_menu_player_def->setText("DEF: " + def);
}

void MainWindow::update_battle_menu_enemy_stats()
{
    QString name = QString::fromStdString(current_enemy->getName());
    QString hp = QString::number(current_enemy->combatStats->HP);
    QString maxHP = QString::number(current_enemy->combatStats->maxHP);
    QString level = QString::number(current_enemy->getLevel());
    QString atk = QString::number(current_enemy->combatStats->ATK);
    QString def = QString::number(current_enemy->combatStats->DEF);
    QString desc = QString::fromStdString(current_enemy->getDescription());

    ui->battle_menu_enemy_name_and_level->setText(name + " (Level " + level + ")");
    ui->battle_menu_enemy_health->setText("Health: " + hp + '/' + maxHP);
    ui->battle_menu_enemy_atk->setText("ATK: " + atk);
    ui->battle_menu_enemy_def->setText("DEF: " + def);
    ui->battle_menu_enemy_desc->setPlainText(desc);
}

void MainWindow::updateShopMenuPlayerStats()
{
    ui->shopMenuName->setText("Name: " + QString::fromStdString(player->getName()));
    ui->shopMenuLevel->setText("Level: " + QString::number(player->getLevel()));
    ui->shopMenuEXP->setText("EXP: " + QString::number(player->getEXP()) + '/' + QString::number(player->getMaxEXP()));
    ui->shopMenuHP->setText("Health: " + QString::number(player->combatStats->HP) + '/' + QString::number(player->combatStats->maxHP));
    ui->shopMenuATK->setText("ATK: " + QString::number(player->combatStats->ATK));
    ui->shopMenuDEF->setText("DEF: " + QString::number(player->combatStats->DEF));

    Inventory equipped = player->getEquipped();
    if (!equipped.getWeapons().empty())
        ui->shopMenuCurrentWeapon->setText("Weapon: " + QString::fromStdString(equipped.getWeapons().at(0)->getName()));
    else
        ui->shopMenuCurrentWeapon->setText("Weapon: <None>");

    if (!equipped.getArmor().empty())
        ui->shopMenuCurrentArmor->setText("Armor: " + QString::fromStdString(equipped.getArmor().at(0)->getName()));
    else
        ui->shopMenuCurrentArmor->setText("Armor: <None>");
}

void MainWindow::updateShopMenuInventory()
{
    ui->shopList->clear();
    std::vector<Item*> items;
    if (ui->shopInventoryWeaponsRadioButton->isChecked())
        items = shop.getShopInventory().getWeapons();
    else if (ui->shopInventoryArmorRadioButton->isChecked())
        items = shop.getShopInventory().getArmor();
    if (items.empty())
        ui->shopList->addItem("No items found");
    else
        for (unsigned i = 0; i < items.size(); ++i)
            ui->shopList->addItem(QString::fromStdString(items.at(i)->getName()));
}

void MainWindow::updateEquipmentMenuPlayerStats()
{
    ui->equipmentMenuName->setText("Name: " + QString::fromStdString(player->getName()));
    ui->equipmentMenuLevel->setText("Level: " + QString::number(player->getLevel()));
    ui->equipmentMenuEXP->setText("EXP: " + QString::number(player->getEXP()) + '/' + QString::number(player->getMaxEXP()));
    ui->equipmentMenuHP->setText("Health: " + QString::number(player->combatStats->HP) + '/' + QString::number(player->combatStats->maxHP));
    ui->equipmentMenuATK->setText("ATK: " + QString::number(player->combatStats->ATK));
    ui->equipmentMenuDEF->setText("DEF: " + QString::number(player->combatStats->DEF));

    Inventory equipped = player->getEquipped();
    if (!equipped.getWeapons().empty())
        ui->equipmentMenuCurrentWeapon->setText("Weapon: " + QString::fromStdString(equipped.getWeapons().at(0)->getName()));
    else
        ui->equipmentMenuCurrentWeapon->setText("Weapon: <None>");

    if (!equipped.getArmor().empty())
        ui->equipmentMenuCurrentArmor->setText("Armor: " + QString::fromStdString(equipped.getArmor().at(0)->getName()));
    else
        ui->equipmentMenuCurrentArmor->setText("Armor: <None>");

    Inventory inventory = player->getInventory();
    std::vector<Item*> items;
    if (ui->viewInventoryWeaponsRadioButton->isChecked())
        items = inventory.getWeapons();
    else if (ui->viewInventoryArmorRadioButton->isChecked())
        items = inventory.getArmor();

    ui->equipmentList->clear();

    if (items.empty())
        ui->equipmentList->addItem("No items found");
    else
        for (unsigned i = 0; i < items.size(); ++i)
            ui->equipmentList->addItem(QString::fromStdString(items.at(i)->getName()));

}

void MainWindow::initializePlayer()
{
    std::string name = ui->enter_name_lineedit->text().toStdString();
    if (name.empty())
        name = "Hero";

    player = new Player(name);
    player->addWeaponToInventory("Wooden Sword", weaponFactory);
    player->addWeaponToInventory("Stone Sword", weaponFactory);
    player->addArmorToInventory("Leather Armor", armorFactory);
    update_main_menu_player_stats();
    updateShopMenuPlayerStats();
    updateEquipmentMenuPlayerStats();
    updateShopMenuInventory();
    switchToMainMenu();
}

void MainWindow::enterArea()
{
    areaEnemiesCount = 0;
    for (int i = 1; i <= 10; ++i)
    {
        int temp = rand() % 3 + 1;
        if (temp == 1)
            area_enemies.push_back(ef.createEnemy("Green Slime"));
        if (temp == 2)
            area_enemies.push_back(ef.createEnemy("Red Slime"));
        if (temp == 3)
            area_enemies.push_back(ef.createEnemy("Goblin"));
    }
    initializeBattleWithEnemy();

    ui->enemiesDefeatedLabel->setText("Enemies Defeated: " + QString::number(areaEnemiesCount) + "/10");
    ui->battle_menu_battle_result->clear();
    ui->battle_menu_roll_difference->clear();
    ui->battle_menu_turn_result->clear();
    ui->battle_menu_enemy_roll->clear();
    ui->battle_menu_player_roll->clear();
    switchToBattleMenu();
}

void MainWindow::nextBattle()
{
    ++areaEnemiesCount;
    ui->enemiesDefeatedLabel->setText("Enemies Defeated: " + QString::number(areaEnemiesCount) + "/10");
    ui->battle_menu_battle_result->clear();
    ui->battle_menu_roll_difference->clear();
    ui->battle_menu_turn_result->clear();
    ui->battle_menu_enemy_roll->clear();
    ui->battle_menu_player_roll->clear();
    area_enemies.pop_back();

    if (area_enemies.size() > 0)
        initializeBattleWithEnemy();
    else
    {
        ui->battle_menu_battle_result->setText("You defeated all ten enemies!");
        ui->returnToMainMenuButton->setEnabled(true);
    }
    ui->nextBattleButton->setEnabled(false);
}

void MainWindow::initializeBattleWithEnemy()
{
    ui->rollButton->setEnabled(true);
    ui->returnToMainMenuButton->setEnabled(false);
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

    if (player->combatStats->HP <= 0 || current_enemy->combatStats->HP <= 0)
    {
        if (player->combatStats->HP <= 0)
        {
            ui->battle_menu_battle_result->setText(enemyName + " has won!");
            ui->returnToMainMenuButton->setEnabled(true);
        }
        else if (current_enemy->combatStats->HP <= 0)
        {
            ui->battle_menu_battle_result->setText(playerName + " has won!");
            ui->nextBattleButton->setEnabled(true);
        }
        ui->rollButton->setEnabled(false);
    }
    update_battle_menu_player_stats();
    update_battle_menu_enemy_stats();
}

void MainWindow::endArea()
{
    player->restoreHP();
    switchToMainMenu();
}

void MainWindow::selectInventoryItemType()
{
    if (ui->viewInventoryWeaponsRadioButton->isChecked())
        ui->viewInventoryItemType->setText("Weapons");
    else if (ui->viewInventoryArmorRadioButton->isChecked())
        ui->viewInventoryItemType->setText("Armor");
    else if (ui->viewInventoryBootsRadioButton->isChecked())
        ui->viewInventoryItemType->setText("Boots");
    else if (ui->viewInventoryCardsRadioButton->isChecked())
        ui->viewInventoryItemType->setText("Cards");
    updateEquipmentMenuPlayerStats();
}

void MainWindow::selectShopItemType()
{
    if (ui->shopInventoryWeaponsRadioButton->isChecked())
        ui->shopInventoryItemType->setText("Weapons");
    else if (ui->shopInventoryArmorRadioButton->isChecked())
        ui->shopInventoryItemType->setText("Armor");
    else if (ui->shopInventoryBootsRadioButton->isChecked())
        ui->shopInventoryItemType->setText("Boots");
    else if (ui->shopInventoryCardsRadioButton->isChecked())
        ui->shopInventoryItemType->setText("Cards");
    updateShopMenuInventory();
}

void MainWindow::equipItem()
{
    std::string selectedItem = ui->equipmentList->currentItem()->text().toStdString();
    if (ui->viewInventoryWeaponsRadioButton->isChecked())
        player->equipWeapon(selectedItem);
    else if (ui->viewInventoryArmorRadioButton->isChecked())
        player->equipArmor(selectedItem);
    update_main_menu_player_stats();
    updateEquipmentMenuPlayerStats();
}

void MainWindow::switchToMainMenu()
{
    ui->menu_pages->setCurrentIndex(1);
}

void MainWindow::switchToBattleMenu()
{
    ui->menu_pages->setCurrentIndex(2);
}

void MainWindow::switchToShopMenu()
{
    ui->menu_pages->setCurrentIndex(3);
}

void MainWindow::switchToEquipmentMenu()
{
    ui->menu_pages->setCurrentIndex(4);
}
