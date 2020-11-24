#ifndef __ENEMY_PROTOTYPE_H__
#define __ENEMY_PROTOTYPE_H__

#include "../../Enemy.h"

class EnemyPrototype : public Enemy{
	public:
		EnemyPrototype() : Enemy(){}
		EnemyPrototype(std::string name) : Enemy(name){}
		virtual EnemyPrototype* Clone() = 0;
};

#endif //__ENEMY_PROTOTYPE_H__
