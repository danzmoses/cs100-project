#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Entity.h"
#include <stdexcept>
#include <cmath>

class Player : public Entity{
	private:
		int EXP;
		int maxEXP;
	public:
    Player() : Entity(), EXP(0), maxEXP(5) {}

    Player(std::string name) : Entity(name), EXP(0), maxEXP(5){}

	//getters and setters
	int getEXP(){
		return this->EXP;
	}

	int getMaxEXP(){
		return this->maxEXP;
	}

	void setEXP(int EXP) 
        { 
            if (EXP < 0) 
            { 
                std::invalid_argument ia("Invalid argument. EXP cannot be negative."); 
                throw ia;
            }

			if (EXP < this->maxEXP)
			{
				this->EXP = EXP;
				return;
			}

			while (EXP >= this->maxEXP)
			{
				this->EXP = EXP - this->maxEXP;
				EXP = EXP - this->maxEXP;
				levelUp();
			}
        }

	void setMaxEXP(int maxEXP){
		this->maxEXP = maxEXP;
	} 

	void levelUp()
	{
		this->setLevel(this->getLevel() + 1); // level up by 1
		this->maxEXP += 10;
			
		int pts = 0; // change pts based on the player's lvl.
		if (this->getLevel() > 0 && this->getLevel() <= 5) // lvl.0-5 gives one point
			pts = 1;
		else if (this->getLevel() > 5 && this->getLevel() <= 8) // lvl.6-8 gives two points
			pts = 2;
		if (this->getLevel() > 9) //>lvl.9 gives three points
			pts = 3;
		
		int rr = 0; // roll result
		
		for (int i = 0; i < pts; ++i)
		{
            rr = rand() % 3;
			if (rr == 0)
			{
				baseStats->ATK += 1;
				combatStats->ATK += 1;
			}
			else if (rr == 1)
			{
				baseStats->DEF += 1;
				combatStats->DEF += 1;
			}
			else if (rr == 2)
			{
                baseStats->HP += 2;
				baseStats->maxHP += 2;
                combatStats->HP += 2;
				combatStats->maxHP += 2;
			}
		}
        updateCombatStats();
	}		
			
};

#endif //__PLAYER_H__
