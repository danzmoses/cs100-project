#ifndef __ENTITY_FACTORY__
#define __ENTITY_FACTORY__

#include <string>

class EntityFactory
{
    public:
        EntityFactory() {};
        virtual void createEntity(std::string name) = 0;

};

#endif // __ENTITY_FACTORY__