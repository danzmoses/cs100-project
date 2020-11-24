# RPG
 Authors: \<[Danz Moses](https://github.com/danzmoses)\> \<[Royce Moses](https://github.com/roycemoses)\> \<[Linda Ly](https://github.com/lly022)\>

## Project Description

 The project is interesting for us because we wanted something fun, yet challenging. This project could help us understand how to work as a team in developing a game/software.

 * We plan to use C++. For the UI, we are going to use Qt Creator. We will also be using Hammer in order to use Valgrind and for unit testing. 
      * [Qt Creator](https://www.qt.io/product/development-tools) - This is our UI that we will be using which we will also be using C++ for. 
 
 * The input is the user's name that they can choose at the starting screen, at their own will. The output will be the context of the user's objective in order to win the game. Throughout the game, there will be information displayed through GUIs which explain what actions have been done to and by the player. 

 * We will be using abstract factory for an entity class, which will be an abstract class used for our player and enemy classes. Inside of player and enemy, we will have the stats, name, and inventory of the player/enemy. We will also have an abstract class for items such as weapons, armor, and boots. 
 * As a complement to the abstract factory, we will be using the prototype design pattern. This allows us to create different subtypes of enemies based on what they are. For example, we could have a Slime prototype that potentially creates "Green Slime", "Red Slime", "Blue Slime", etc. These unique enemies could then have different stats. 
 * Finally, we are also using strategy. We need this design pattern primarily for the battle system. Strategy should determine how damage is calculated, how gold is earned from battles, and whether the player or enemy attacks in a turn. We may also use algorithms to determine which stats the player gains when they level up.
 
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
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 ![CI](https://github.com/cs100/final-project-dmose013-lly022-rmose005/workflows/CI/badge.svg)
