#ifndef __ITEM_H__
#define __ITEM_H__
#include <string>

class Item{
	private:
		std::string name;
		int cost;
	public:
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
