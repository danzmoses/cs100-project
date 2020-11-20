#ifndef __ITEM_FACTORY_H__
#define __ITEM_FACTORY_H__

class ItemFactory : public AbstractFactory{
	public:
		ItemFactory();
		virtual void CreateItem(std::string name) = 0;
};

#endif //__ITEM_FACTORY_H__
