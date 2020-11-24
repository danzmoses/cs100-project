#ifndef __IRONARMOR_PROTOTYPE__
#define __IRONARMOR_PROTOTYPE__

#include "ArmorPrototype.h"

class IronArmorPrototype : public ArmorPrototype 
{
    public:
        IronArmorPrototype() : ArmorPrototype() { this->setName("Iron Armor"); this->setCost(450); }
        IronArmorPrototype(std::string name) : ArmorPrototype(name) {}
        virtual ArmorPrototype* Clone() { return this; }
};

#endif // __IRONARMOR_PROTOTYPE__
