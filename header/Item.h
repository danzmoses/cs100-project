#ifndef __ITEM_H__
#define __ITEM_H__
#include <string>
#include "Stats.h"

class Item : public Stats {
	private:
		std::string name;
		int cost;

	public:
        	Item() : Stats(){
			this->name = "Item";
			this->cost = 0; 
			this->ATK = 0; 
			this->DEF = 0;
		}

        	Item(std::string name) : Stats(){
			this->name = name; 
			this->cost = 0;
			this->ATK = 0;
			this->DEF = 0;
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
