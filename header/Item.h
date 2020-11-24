#ifndef __ITEM_H__
#define __ITEM_H__
#include <string>

class Item{
	private:
		std::string name;
		int cost;
		int ATK;
		int DEF;
	public:
		Item(){
			this->name = "Item";
			this->cost = 0;
			this->ATK = 0;
			this->DEF = 0;
		}

		Item(std::string name){
			this->name = name;
			this->cost = 0;
			this->ATK = 0;
			this->DEF = 0;
		}

		std::string getName(){
			return this->name;
		}

		int getCost(){
			return this->cost;
		}

		int getATK(){
			return this->ATK;
		}
		
		int getDEF(){
			return this->DEF;
		} 

		void setName(std::string name){
			this->name = name;
		}

		void setCost(int cost){
			this->cost = cost;
		}

		void setATK(int ATK){
			this->ATK = ATK;
		}

		void setDEF(int DEF){
			this->DEF = DEF;
		}
};

#endif //__ITEM_H__
