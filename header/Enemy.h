#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Entity.h"

class Enemy : public Entity{
	private:
		std::string description;
	public:
		Enemy() : Entity(), description("this is an enemy"){}
		
		Enemy(std::string name) : Entity(name), description("this is an enemy"){}

		//getters and setters
		std::string getDescription(){
			return description;
		}

		void setDescription(std::string description){
			this->description = description;
		}
};

#endif //__ENEMY_H__
