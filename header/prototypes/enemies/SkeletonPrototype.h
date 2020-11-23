#ifndef __SKELETON_PROTOTYPE__
#define __SKELETON_PROTOTYPE__

#include "EnemyPrototype.h"

class SkeletonPrototype : public EnemyPrototype 
{
    public:
        SkeletonPrototype() : EnemyPrototype() { setName("Skeleton"); setHP(5); }
        SkeletonPrototype(std::string name) : EnemyPrototype(name) {}
        virtual EnemyPrototype* Clone() { return this; }
};

#endif // __SKELETON_PROTOTYPE__
