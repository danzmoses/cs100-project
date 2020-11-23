#ifndef __ARMOR_FACTORY_H__
#define __ARMOR_FACTORY_H__
#include "ItemFactory.h"

class ArmorFactory : public ItemFactory{
        public:
                ArmorFactory() : ItemFactory(){
                }

                virtual Item* createItem(std::string name){
                } 
};

#endif //__ARMOR_FACTORY_H__
