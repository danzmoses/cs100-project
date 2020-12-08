#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Entity.h"
#include <stdexcept>

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
            		this->setLevel(this->getLevel() + numLevels);
			baseStats->ATK += 1;
			baseStats->DEF += 1;
			baseStats->maxHP += 5;
			combatStats->ATK += 1;
			combatStats->DEF += 1;
			combatStats->maxHP += 5; 
			//every time player levels up (no matter how many levels) maxHP increases only once
			//we can always remove the part where maxHP increases if it becomes a problem/too advantageous in battle
	}		
			
};

#endif //__PLAYER_H__
