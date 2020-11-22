#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <string>

class Entity{
	private:
		int HP;
		int maxHP;
		int ATK;
		int DEF;
		std::string name;
	public:
		Entity() : HP(10), maxHP(10), ATK(1), DEF(1){}
		
		Entity(std::string name) : name(name), HP(10), maxHP(10), ATK(1), DEF(1) {}

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
