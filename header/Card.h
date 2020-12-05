#ifndef __CARD_H__
#define __CARD_H__

#include <iostream>
#include <string>

class Card{
	private:
		std::string name;
		int cost; //gold
		std::string description;
	public:
		Card(){
			name = "Card";
			cost = 50; 
			description = "Default description of card";
		}
		
		Card(std::string name){
			this->name = name;
			this->cost = 50;
			this->description = "This card can...";
		}

		std::string getName(){
			return this->name;
		}

		int getCost(){
			return this->cost;
		}

		std::string getDescription(){
			return this->description;
		}

		void setName(std::string name){
			this->name = name;
		}

		void setCost(int cost){
			this->cost = cost;
		}

		void setDescription(std::string description){
			this->description = description;
		}
};

#endif //__CARD_H__
