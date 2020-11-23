#ifndef __WEAPON_FACTORY_H__
#define __WEAPON_FACTORY_H__
#include "ItemFactory.h"
#include "prototypes/weapons/WoodenSwordPrototype.h"
#include "prototypes/weapons/StoneSwordPrototype.h"
#include <vector>
#include <stdexcept>

class WeaponFactory : public ItemFactory {
    private:
        std::vector<WeaponPrototype*> weaponPrototypes;

    public:
        WeaponFactory() : ItemFactory()
        {
            this->weaponPrototypes.push_back(new WoodenSwordPrototype());
            this->weaponPrototypes.push_back(new StoneSwordPrototype());
        }

        virtual Item* createItem(std::string name)
        { 
            for (int i = 0; i < weaponPrototypes.size(); ++i)
            {
                if (weaponPrototypes.at(i)->getName() == name)
                {
                    return weaponPrototypes.at(i)->Clone();
                }
            }
            std::invalid_argument ia("Invalid argument. Unable to find \"" + name + '\"' );
            throw ia;
        } 
};

#endif //__WEAPON_FACTORY_H__