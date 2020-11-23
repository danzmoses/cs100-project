#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Entity.h"

class Enemy : public Entity{
	private:
		std::string description;
	public:
		Enemy() : Entity(), description("this is an enemy"){}
		
		Enemy(std::string name) : Entity(name), description("this is an enemy"){}

};

#endif //__ENEMY_H__
