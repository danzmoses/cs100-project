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

	//getters and setters
	int getGold(){
		return this->gold;
	}

	int getLevel(){
		return this->level;
	}

	int getEXP(){
		return this->EXP;
	}

	void setGold(int gold){
		this->gold = gold;
	}

	void setLevel(int level){
		this->level = level;
	}

	void setEXP(int EXP){
		this->EXP = EXP;
	}
};

#endif //__PLAYER_H__
