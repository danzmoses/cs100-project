#ifndef __ITEM_H__
#define __ITEM_H__
#include <string>
#include "Stats.h"
#include <iostream>

class Item{
	private:
		std::string name;
		int cost;

	public:
		Stats *baseStats = new Stats();
		Stats *combatStats = new Stats();
        	Item(){
			std::cout << "Item constructor" << std::endl;
			this->name = "Item";
			this->cost = 0; 
			baseStats->ATK = 0; 
			baseStats->DEF = 0;
			combatStats->ATK = 0;
			combatStats->DEF = 0;
			std::cout << "End of Item Constructor" << std::endl;
		}

        	Item(std::string name){
			this->name = name; 
			this->cost = 0;
			baseStats->ATK = 0;
			baseStats->DEF = 0;
			combatStats->ATK = 0;
			combatStats->DEF = 0;
		}

		std::string getName(){
			return name;
		}

		int getCost(){
			return cost;
		}

		void setName(std::string name){
			this->name = name;
		}

		void setCost(int cost){
			this->cost = cost;
		}
};

#endif //__ITEM_H__
