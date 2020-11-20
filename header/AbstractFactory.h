#ifndef __ABSTRACT_FACTORY_H__
#define __ABSTRACT_FACTORY_H__

class AbstractFactory{
	public:
		AbstractFactory();
		virtual void createEntity();
		virtual void createItem();
};

#endif //__ABSTRACT_FACTORY_H__
