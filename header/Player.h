#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Entity.h"

class Player : public Entity{
	private:
		int gold;
		int level;
		int EXP;
	public:
	Player() : Entity(), gold(50), level(1), EXP(0){}

	Player(std::string name) : Entity(name), gold(50), level(1), EXP(0){}

};

#endif //__PLAYER_H__
