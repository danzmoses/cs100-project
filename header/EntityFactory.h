#ifndef __ENTITY_FACTORY_H__
#define __ENTITY_FACTORY_H__
#include "AbstractFactory.h"

class EntityFactory : public AbstractFactory{
	public:
		EntityFactory();
		virtual void CreateEntity(std::string name) = 0;
};

#endif //__ENTITY_FACTORY_H__
