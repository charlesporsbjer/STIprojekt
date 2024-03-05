#include <iostream> 
#include <vector>

class Weapon {
public:
    std::string name;
    int baseDamage;
    float strengthScaling;
    float dexterityScaling;

    Weapon(std::string name, int baseDamage, float strengthScaling, float dexterityScaling) 
        : name(name), baseDamage(baseDamage), strengthScaling(strengthScaling), dexterityScaling(dexterityScaling) {}
};

int calculateDamage(Weapon weapon, int strength, int dexterity) {
    return weapon.baseDamage + (strength * weapon.strengthScaling) + (dexterity * weapon.dexterityScaling);
}

int main() {
    std::vector weapons = {
        Weapon("Sword", 10, 0.5, 0.2),
        Weapon("Bow", 15, 0.3, 0.4),
        Weapon("Axe", 8, 0.6, 0.1),
        Weapon("Donkey", 7, 0.6, 0.1)
    };

    for (int i = 0; i < weapons.size(); i++) {
        std::cout << i << ": " << weapons[i].name << std::endl;
    }

    int weaponIndex;
    std::cout << "Enter the weapon index (0-" << weapons.size() - 1 << "): ";
    std::cin >> weaponIndex;

    int strength;
    std::cout << "Enter your strength: ";
    std::cin >> strength;

    int dexterity;
    std::cout << "Enter your dexterity: ";
    std::cin >> dexterity;

    if (weaponIndex >= 0 && weaponIndex < weapons.size()) {
        Weapon weapon = weapons[weaponIndex];
        int damage = calculateDamage(weapon, strength, dexterity);
        std::cout << "The damage with " << weapon.name << " will be: " << damage << std::endl;
    } else {
        std::cout << "Invalid weapon index." << std::endl;
    }

    return 0;
}