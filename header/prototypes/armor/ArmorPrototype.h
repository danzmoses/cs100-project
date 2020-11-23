#ifndef __ARMOR_PROTOTYPE__
#define __ARMOR_PROTOTYPE__

#include "../../Armor.h"

class ArmorPrototype : public Armor
{
    public:
        ArmorPrototype() : Armor() {}
        ArmorPrototype(std::string name) : Armor(name) {}
        virtual ArmorPrototype* Clone() { return this; }
};

#endif // __ARMOR_PROTOTYPE__

