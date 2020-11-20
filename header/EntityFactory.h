#ifndef __ENTITY_FACTORY__
#define __ENTITY_FACTORY__

#include <string>
#include "Entity.h"

class EntityFactory
{
    public:
        EntityFactory() {};
        virtual Entity* createEntity(std::string name) = 0;

};

#endif // __ENTITY_FACTORY__