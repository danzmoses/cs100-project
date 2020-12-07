#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Entity.h"

class Enemy : public Entity{
	private:
		std::string description;
		int EXPMult;
	public:
		Enemy() : Entity(), description("this is an enemy"){}
		
		Enemy(std::string name) : Entity(name), description("this is an enemy"){}

		//getters and setters
		std::string getDescription(){
			return description;
		}

		int getEXPMult() { return EXPMult; }

		void setDescription(std::string description){
			this->description = description;
		}

		void setEXPMult(int EXPMult) { this->EXPMult = EXPMult; }

};

#endif //__ENEMY_H__
