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
 
 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
 ![alt text](https://github.com/cs100/final-project-dmose013-lly022-rmose005/blob/master/images/AbstractFactory.png?raw=true)
 
 ![alt text](https://github.com/cs100/final-project-dmose013-lly022-rmose005/blob/master/images/Strategy(Battle).png?raw=true) 
 
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
 
