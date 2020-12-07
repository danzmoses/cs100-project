#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Entity.h"
#include <stdexcept>
#include <cmath>

class Player : public Entity{
	private:
		int gold;
		int EXP;
		int maxEXP;
	public:
    Player() : Entity(), gold(50), EXP(0), maxEXP(5) {}

    Player(std::string name) : Entity(name), gold(50), EXP(0), maxEXP(5){}

	//getters and setters
	int getGold(){
		return this->gold;
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

	void setEXP(int EXP) 
        { 
            if (EXP < 0) 
            { 
                std::invalid_argument ia("Invalid argument. EXP cannot be negative."); 
                throw ia;
            } 
            this->EXP = EXP;
        }

	void setMaxEXP(int maxEXP){
		this->maxEXP = maxEXP;
	} 

	//in battle or after battle, if(this->EXP >= maxEXP){ player->levelUp(); }
	void levelUp()
	{
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
		this->setLevel(this->getLevel() + numLevels);
		
		int random = 0;
		int pts = 1; // change pts based on the player's lvl.
		for (int i = 0; i < numLevels + pts; ++i)
		{
			random = rand() % 3;
			if (random == 0)
				baseStats->ATK += 1;
			else if (random == 1)
				baseStats->DEF += 1;
			else if (random == 2)
				baseStats->maxHP += 2;
		}
	}		
			
};

#endif //__PLAYER_H__
