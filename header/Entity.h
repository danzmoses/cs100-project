#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <string>

class Entity{
	private:
		int level;
		int health;
		int exp;
		int ATK;
		int DEF;
		std::string name;
	public:
		Entity(){
		}
		
		Entity(std::string name){
			this->name = name;
			this->level = 1;
			this->exp = 0; //max exp = 5
			this->health = 5; //max health = 5
			this->ATK = 1;
			this-> DEF = 1;		
		}

		//getters and setters
		int getLevel(){
			return this->level;
		}
		
		int getHealth(){
			return this->health;
		}

		int getExp(){
			return this->exp;
		}

		int getATK(){
			return this->ATK;
		}

		int getDEF(){
			return this->DEF;
		}

		std::string getName(){
			return this->name;
		}

		void setLevel(int level){
			this->level = level;
		}

		void setHealth(int health){
			this->health = health;
		}

		void setExp(int exp){
			this->exp = exp;
		}

		void setATK(int ATK){
			this->ATK = ATK;
		}

		void setDEF(int DEF){
			this->DEF = DEF;
		}

		void setName(std::string name){
			this->name = name;
		}

};

#endif //__ENTITY_H__
