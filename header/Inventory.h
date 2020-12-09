#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include "Item.h"
#include "Card.h"
#include <vector>

class Inventory
{
    private:
        std::vector<Item*> weapons;
        std::vector<Item*> armor;
        std::vector<Card*> cards;

    public:
        Inventory() {}
        void addWeapon(Item* w) { this->weapons.push_back(w); }
        void addArmor(Item* a) { this->armor.push_back(a); }
        void addCard(Card* c) { this->cards.push_back(c); }

        void modifyWeaponItem(int index, Item* item) { weapons.at(index) = item; } // used to reroute pointers in weapons
        void modifyArmorItem(int index, Item* item) { armor.at(index) = item; } // used to reroute pointers in armor
        
        std::vector<Item*> getWeapons() { return weapons; }
        std::vector<Item*> getArmor() { return armor; }
        std::vector<Card*> getCards() { return cards; }

        Item* getItem(std::string name)
        {
            for (int i = 0; i < this->weapons.size(); ++i)
                if (this->weapons.at(i)->getName() == name)
                    return this->weapons.at(i);

            for (int i = 0; i < this->armor.size(); ++i)
                if (this->armor.at(i)->getName() == name)
                    return this->armor.at(i);
            
            std::invalid_argument ia("Invalid argument. Unable to find item named \"" + name + "\" inside of this inventory.");
            throw ia;
        }

        Card* getCard(std::string name)
        {
            for (int i = 0; i < this->cards.size(); ++i)
                if (this->cards.at(i)->getName() == name)
                    return this->cards.at(i);
            
            std::invalid_argument ia("Invalid argument. Unable to find item named \"" + name + "\" inside of this inventory.");
            throw ia;
        }

        void removeItem(std::string name)
        {
            for (int i = 0; i < this->weapons.size(); ++i)
                if (this->weapons.at(i)->getName() == name)
                {
                    this->weapons.at(i) = nullptr;
                    this->weapons.erase(this->weapons.begin() + i);       
                    return;
                }

            for (int i = 0; i < this->armor.size(); ++i)
                if (this->armor.at(i)->getName() == name)
                {
                    this->armor.at(i) = nullptr;
                    this->armor.erase(this->armor.begin() + i);
                    return;
                }
            
            std::invalid_argument ia("Invalid argument. Unable to find item named \"" + name + "\" inside of this inventory.");
            throw ia;
        }

        void removeCard(std::string name)
        {
            for (int i = 0; i < this->cards.size(); ++i)
                if (this->cards.at(i)->getName() == name)
                {
                    this->cards.at(i) = nullptr;
                    this->cards.erase(this->cards.begin() + i);
                    return;
                }

            std::invalid_argument ia("Invalid argument. Unable to find item named \"" + name + "\" inside of this inventory.");
            throw ia;
        }
        
};


#endif // __INVENTORY_H__
