#include <iostream>
#include <vector>
#include <map>

class Gear {
public:
    Gear(std::string name, int health, int mana, int strength, int intelligence) 
        : name(name), health(health), mana(mana), strength(strength), intelligence(intelligence) {}

    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getMana() const { return mana; }
    int getStrength() const { return strength; }
    int getIntelligence() const { return intelligence; }

private:
    std::string name;
    int health;
    int mana;
    int strength;
    int intelligence;
};

class Character {
public:
    // Constructor
    Character(std::string name, int level, int health, int mana, int strength, int intelligence) 
        : name(name), level(level), health(health), mana(mana), strength(strength), intelligence(intelligence) {}

    // Level up
    void levelUp() {
        level++;
        health += 10;
        mana += 5;
        strength += 2;
        intelligence += 2;
    }

    // Equip gear
    void equipGear(const Gear& gear) {
        if (gearSlot[gear.getName()] == nullptr) {
            gearSlot[gear.getName()] = &gear;
            health += gear.getHealth();
            mana += gear.getMana();
            strength += gear.getStrength();
            intelligence += gear.getIntelligence();
        } else {
            std::cout << "You already have a " << gear.getName() << " equipped." << std::endl;
        }
    }

    // Unequip gear
    void unequipGear(const Gear& gear) {
        if (gearSlot[gear.getName()] == &gear) {
            gearSlot[gear.getName()] = nullptr;
            health -= gear.getHealth();
            mana -= gear.getMana();
            strength -= gear.getStrength();
            intelligence -= gear.getIntelligence();
        } else {
            std::cout << "You don't have a " << gear.getName() << " equipped." << std::endl;
        }
    }

    // Print stats
    void printStats() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Level: " << level << std::endl;
        std::cout << "Health: " << health << std::endl;
        std::cout << "Mana: " << mana << std::endl;
        std::cout << "Strength: " << strength << std::endl;
        std::cout << "Intelligence: " << intelligence << std::endl;
    }

private:
    std::string name;
    int level;
    int health;
    int mana;
    int strength;
    int intelligence;
    std::map<std::string, const Gear*> gearSlot;
};

int main() {
    // Create a character
    Character character("Hero", 1, 100, 20, 10, 5);

    // Create a list of gear pieces
    std::vector gearList = {
        Gear("Helmet", 5, 0, 0, 2),
        Gear("Chestplate", 10, 0, 5, 0),
        Gear("Gauntlets", 5, 0, 2, 0),
        Gear("Leggings", 10, 0, 5, 0),
        Gear("Boots", 5, 0, 2, 0),
        Gear("Weapon", 0, 0, 10, 0),
        Gear("Shield", 0, 0, 5, 0),
    };

    // Print initial stats
    std::cout << "Initial Stats:" << std::endl;
    character.printStats();

    // Level up
    character.levelUp();

    // Print updated stats
    std::cout << "\nStats after level up:" << std::endl;
    character.printStats();

    // Equip some gear
    character.equipGear(gearList[0]); // Helmet
    character.equipGear(gearList[1]); // Chestplate
    character.equipGear(gearList[5]); // Weapon

    // Print updated stats
    std::cout << "\nStats after equipping gear:" << std::endl;
    character.printStats();

    // Try to equip the same gear again
    character.equipGear(gearList[0]); // Helmet

    // Print updated stats
    std::cout << "\nStats after trying to equip the same gear again:" << std::endl;
    character.printStats();

    // Unequip some gear
    character.unequipGear(gearList[0]); // Helmet
    character.unequipGear(gearList[2]); // Gauntlets

    // Print updated stats
    std::cout << "\nStats after unequipping gear:" << std::endl;
    character.printStats();

    return 0;
}