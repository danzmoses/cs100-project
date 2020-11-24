#ifndef __ITEM_H__
#define __ITEM_H__
#include <string>

class Item
{
	private:
		std::string name;
		int cost;
        int ATK;
        int DEF;

	public:
        Item() : name("Item"), cost(0), ATK(0), DEF(0) {}

        Item(std::string name) : name(name), cost(0), ATK(0), DEF(0) {}

		std::string getName(){
			return name;
		}

		int getCost(){
			return cost;
		}

        int getATK(){
			return ATK;
		}

        int getDEF(){
			return DEF;
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
