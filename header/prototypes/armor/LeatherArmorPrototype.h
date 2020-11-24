#ifndef __LEATHERARMOR_PROTOTYPE__
#define __LEATHERARMOR_PROTOTYPE__

#include "ArmorPrototype.h"

class LeatherArmorPrototype : public ArmorPrototype 
{
    public:
        LeatherArmorPrototype() : ArmorPrototype() { this->setName("Leather Armor"); this->setCost(50); }
        LeatherArmorPrototype(std::string name) : ArmorPrototype(name) {}
        virtual ArmorPrototype* Clone() { return this; }
};

#endif // __LEATHERARMOR_PROTOTYPE__
