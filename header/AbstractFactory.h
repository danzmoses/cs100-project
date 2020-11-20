#ifndef __ABSTRACT_FACTORY_H__
#define __ABSTRACT_FACTORY_H__

class AbstractFactory{
	public:
		AbstractFactory();
		virtual void CreateEntity();
		virtual void CreateItem();
};

#endif //__ABSTRACT_FACTORY_H__
