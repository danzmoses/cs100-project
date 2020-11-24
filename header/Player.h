#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Entity.h"

class Player : public Entity{
	private:
		int gold;
		int level;
		int EXP;
		int maxEXP;
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

	int getMaxEXP(){
		return this->maxEXP;
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

	void setMaxEXP(int maxEXP){
		this->maxEXP = maxEXP;
	} 

	//in battle or after battle, if(this->EXP >= maxEXP){ player->levelUp(); }
	void levelUp(){
		int additionalEXP = 0;
		int numLevels = 0;
			//bc player's curr EXP could be more than double MaxEXP
			//each time a multiple of maxEXP is met = level up by 1
			while(this->EXP >= maxEXP){
				additionalEXP = this->EXP - maxEXP;
				this->EXP = additionalEXP;
				numLevels++;
			}
			this->setEXP(additionalEXP); 
			this->level += numLevels;
			this->ATK += 1;
			this->DEF += 1;
			this->setMaxHP(this->maxHP+5); 
	}		
			
};

#endif //__PLAYER_H__
