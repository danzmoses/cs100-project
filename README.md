# RPG
 Authors: \<[Danz Moses](https://github.com/danzmoses)\> \<[Royce Moses](https://github.com/roycemoses)\> \<[Linda Ly](https://github.com/lly022)\>

## Project Description

 The project is interesting for us because we wanted something fun, yet challenging. This project could help us understand how to work as a team in developing a game/software.

 * We plan to use C++. For the UI, we are going to use Qt Creator. We will also be using Hammer in order to use Valgrind and for unit testing. 
      * [Qt Creator](https://www.qt.io/product/development-tools) - This is our UI that we will be using which we will also be using C++ for. 
 
 * The input is the user's name that they can choose at the starting screen, at their own will. The output will be the context of the user's objective in order to win the game. Throughout the game, there will be information displayed through GUIs which explain what actions have been done to and by the player. 

 * We will be using Abstract Factory for an item class, which will be used to create different items with a common interface. Each Abstract Product (Weapons, Armor, etc.) has a corresponding Concrete Factory (WeaponFactory, ArmorFactory, etc.) that produces the Concrete Product. For example, a WeaponFactory can produce Concrete Products such as Wooden Sword, Stone Sword, Iron Sword, etc. The client uses the AbstractFactory (ItemFactory) to create the Concrete Products.
 * As a complement to the abstract factory, we will be using the Prototype design pattern for the items. This allows us to use a single base prototype class such as WeaponPrototype that all weapon prototypes inherit from. The Concrete Factory (WeaponFactory) can hold a list of all the weapons that can be instantiated using a clone() method whenever the user wants to create a weapon. Additionally, we can use Prototype to create enemies using an EnemyFactory class. This allows us to create different subtypes of enemies based on what they are. For example, we could have a Slime prototype that potentially creates "Green Slime", "Red Slime", "Blue Slime", etc. These unique enemies could then have different stats. Cards will also have Prototypes that hold the name and description of each card.
 * Finally, we are also using strategy. We need this design pattern primarily for the battle system. The strategy pattern can be used to determine the type of attack used in a turn of a battle. We will have the LightAttackStrategy, NormalAttackStrategy, and HeavyAttackStrategy as Concrete Strategies that inherit from an abstract AttackStrategy class. The Battle class acts as the Context for the Strategy pattern that decides which attack strategy to use. Each attack strategy returns the amount of damage done to defender of the engagement. Additionally, we will use Strategy to define the functionality of the Card class. Each Card will have corresponding Concrete Strategy that inherits from an abstract CardStrategy class. For example, if the player uses a "LightHeal" card, the LightHealStrategy class will be used to increase a player's HP for a small amount. If the player uses an "EnhanceATK" card, the EnhanceATKStrategy class should increase the player's ATK for a turn.
 
## Class Diagrams

### Abstract Factory Class Diagram
 > ![alt text](https://github.com/cs100/final-project-dmose013-lly022-rmose005/blob/master/images/AbstractFactory.png?raw=true)
 
 - The AbstractFactory design pattern allows us to create families of related objects (in this case we have Items). This reveals the interface of the objects to the client, but not their implementation. The Concrete Factories (WeaponFactory and ArmorFactory) have a similar interface, but the client only uses the ItemFactory to create the Concrete Products. This design pattern works together with the Prototype design pattern to create a variety of different items.
 - In this design pattern, ItemFactory is the AbstractFactory. The Concrete Factories are WeaponFactory and ArmorFactory. The Abstract Products are Weapon and Armor. The ConcreteProducts are WeaponPrototype and ArmorPrototype.

### Strategy Class Diagram
 > ![alt text](https://github.com/cs100/final-project-dmose013-lly022-rmose005/blob/master/images/Strategy.png?raw=true) 
 
 - The Strategy design pattern helps us define a family of algorithms (the AttackStrategy). The algorithm changes depending on the type of attack being used by the attacker. This allows us to change the behavior of the algorithm without using many conditional statements and avoid duplicating similar code.
 - In this design pattern, AttackStrategy is the Strategy. LightAttackStrategy, NormalAttackStrategy, and HeavyAttackStrategy are the ConcreteStrategy classes. The Context in this case is the Battle class, which chooses the type of AttackStrategy to use. When the Battle object does the nextTurn() function, it will call the attack() function and the Strategy pattern will decide which attack strategy to use.

### Prototype Class Diagram
> ![alt text](https://github.com/cs100/final-project-dmose013-lly022-rmose005/blob/master/images/Prototype.png?raw=true)

- The Prototype design pattern allows us to create different types of enemies such as Goblins or Slimes, etc. There will be preset classes in the "Prototypes" folder that we will use to instantiate these different types of enemies. The BossPrototype will also go under EnemyPrototype.
- In this design pattern, EnemyPrototype is the Prototype. GreenSlimePrototype, RedSlimePrototype, and GoblinPrototype are the Concrete Prototypes. The Client in this case is the EnemyFactory, which calls clone on a prototype to return a copy of that prototype.

### Card Strategy Class Diagram
> ![alt text](https://github.com/cs100/final-project-dmose013-lly022-rmose005/blob/master/images/CardStrategyDesign.png?raw=true)

- The Card Strategy design pattern helps us group the Card functionality algorithms together. The algorithm changes based on the type of card that is equipped and selected by the attacker. This allows us to use cards such as EnhanceDEF, EnhanceATK, etc. to temporarily increase a Player's stats in combat. There are also Cards that restore health, and deal damage, all of which can easily be expanded with this design pattern.

### Card Prototype Class Diagram
> ![alt text](https://github.com/cs100/final-project-dmose013-lly022-rmose005/blob/master/images/CardFactoryAndPrototype.png?raw=true)
- The Card Prototype design patterns allows us create different types of cards. There will be preset classes in the "prototypes/cards" directory that we will use to instantiate each of the Cards.
- This design pattern relies on CardPrototype, which is inherited by all other CardPrototypes such as EnhanceATK, EnhanceDEF, SmallHeal, etc. The derived classes can serve base classes of even more subclasses, which will eventually turn into a Conrcrete Prototype. In each Prototype, the client will be able to use the function Clone() to return an instance of a CardPrototype of their choice. 

 ## Screenshots
 ### Start Menu
 > ![alt text](https://github.com/cs100/final-project-dmose013-lly022-rmose005/blob/master/images/screenshots/startMenu.png?raw=true)
 ### Main Menu
 > ![alt text](https://github.com/cs100/final-project-dmose013-lly022-rmose005/blob/master/images/screenshots/mainMenu.png?raw=true)
 ### Equipment Menu
 > ![alt text](https://github.com/cs100/final-project-dmose013-lly022-rmose005/blob/master/images/screenshots/equipmentMenu.png?raw=true)
 ### Shop Menu
 > ![alt text](https://github.com/cs100/final-project-dmose013-lly022-rmose005/blob/master/images/screenshots/shopMenu.png?raw=true)
 ### Battle Menu
 > ![alt text](https://github.com/cs100/final-project-dmose013-lly022-rmose005/blob/master/images/screenshots/battleMenu.png?raw=true)
 ## Installation/Usage
 We are unable to deploy an installation package for this application at this time. For now, use the steps below to run this program.
 - Step 1: If you do not have a version of Qt or QtCreator, use one of the installers at https://www.qt.io/offline-installers.
 - Step 2: Open QtCreator and go to File->New File or Project->Import Project->Git Clone
 - Step 3: Enter this git repository next to "Repository" and click "Next" and follow the rest of the instructions.
 - Step 4: If all steps are done correctly, press the green arrow on the bottom left of the screen to run the application.
 ## Testing
 ![CI](https://github.com/cs100/final-project-dmose013-lly022-rmose005/workflows/CI/badge.svg)
