#ifndef __ENEMY_PROTOTYPE__
#define __ENEMY_PROTOTYPE__

class EnemyPrototype
{
    public:
        EnemyPrototype() {};
        EnemyPrototype(std::string name) {};
        virtual EnemyPrototype* Clone() = 0;
};

#endif // __ENEMY_PROTOTYPE__