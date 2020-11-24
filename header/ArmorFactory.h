#ifndef __ARMOR_FACTORY_H__
#define __ARMOR_FACTORY_H__
#include "ItemFactory.h"
#include "prototypes/armor/LeatherArmorPrototype.h"
#include "prototypes/armor/IronArmorPrototype.h"
#include <vector>
#include <stdexcept>

class ArmorFactory : public ItemFactory {
    private:
        std::vector<ArmorPrototype*> armorPrototypes;

    public:
        ArmorFactory() : ItemFactory()
        {
            this->armorPrototypes.push_back(new LeatherArmorPrototype());
            this->armorPrototypes.push_back(new IronArmorPrototype());
        }

        virtual Item* createItem(std::string name)
        { 
            for (int i = 0; i < armorPrototypes.size(); ++i)
            {
                if (armorPrototypes.at(i)->getName() == name)
                {
                    return armorPrototypes.at(i)->Clone();
                }
            }
            std::invalid_argument ia("Invalid argument. Unable to find \"" + name + '\"' );
            throw ia;
        } 
};

#endif //__ARMOR_FACTORY_H__
