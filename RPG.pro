#-------------------------------------------------
#
# Project created by QtCreator 2020-11-07T13:12:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RPG
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    header/battle/AttackStrategy.h \
    header/battle/Battle.h \
    header/battle/HeavyAttackStrategy.h \
    header/battle/LightAttackStrategy.h \
    header/battle/NormalAttackStrategy.h \
    header/battle/Turn.h \
    header/prototypes/armor/ArmorPrototype.h \
    header/prototypes/enemies/EnemyPrototype.h \
    header/prototypes/enemies/GoblinPrototype.h \
    header/prototypes/enemies/GreenSlimePrototype.h \
    header/prototypes/enemies/RedSlimePrototype.h \
    header/prototypes/enemies/SkeletonPrototype.h \
    header/prototypes/enemies/SlimePrototype.h \
    header/prototypes/enemies/ZombiePrototype.h \
    header/prototypes/weapons/WeaponPrototype.h \
    header/Armor.h \
    header/Enemy.h \
    header/EnemyFactory.h \
    header/Entity.h \
    header/Item.h \
    header/ItemFactory.h \
    header/Player.h \
    header/Weapon.h

FORMS    += mainwindow.ui

DISTFILES += \
    images/AbstractFactory.png \
    images/Prototype.png \
    images/Strategy.png \
    .gitmodules \
    README.md
