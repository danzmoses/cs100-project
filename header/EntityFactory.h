#ifndef __ENTITY_FACTORY_H__
#define __ENTITY_FACTORY_H__
#include "AbstractFactory.h"
#include "Entity.h"
#include <string>

class EntityFactory : public AbstractFactory{
	public:
		EntityFactory() : AbstractFactory() {};
		virtual Entity* createEntity(std::string name) = 0;
};

#endif //__ENTITY_FACTORY_H__
