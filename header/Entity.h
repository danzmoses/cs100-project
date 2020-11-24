#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <string>

class Entity{
	private:
		int HP; 
		std::string name;
	protected:
		int ATK; //ATK, DEF, maxHP used in Player's levelUp()
		int DEF;
		int maxHP; 
	public:
		Entity() : HP(10), maxHP(10), ATK(1), DEF(1){}
		
		Entity(std::string name) : name(name), HP(10), maxHP(10), ATK(1), DEF(1) {}

		//getters and setters
		int getHP(){
                        return this->HP;
                }

		int getMaxHP(){
			return this->maxHP;
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

		void setHP(int HP){
			this->HP = HP;
		}

		void setMaxHP(int maxHP){
			this->maxHP = maxHP;
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

		void restoreHP(){
			this->HP = maxHP;
		}


};

#endif //__ENTITY_H__
