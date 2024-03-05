#include 
#include 

struct Weapon {
    std::string name;
    int baseDamage;
    float strengthScaling;
    float dexterityScaling;
};

float calculateDamage(const Weapon& weapon, int strength, int dexterity) {
    return weapon.baseDamage + (weapon.strengthScaling * strength) + (weapon.dexterityScaling * dexterity);
}

int main() {
    std::vector weapons = {
        {"Sword", 10, 0.5, 0.2},
        {"Bow", 8, 0.2, 0.6},
        {"Staff", 12, 0.3, 0.4}
    };

    while (true) {
        std::cout << "Enter a weapon index (0-" << weapons.size() - 1 << "), or -1 to quit: ";
        int index;
        std::cin >> index;

        if (index == -1) {
            break;
        }

        if (index < 0 || index >= weapons.size()) {
            std::cout << "Invalid index. Please try again.\n";
            continue;
        }

        std::cout << "Enter your strength: ";
        int strength;
        std::cin >> strength;

        std::cout << "Enter your dexterity: ";
        int dexterity;
        std::cin >> dexterity;

        std::cout << "Damage with " << weapons[index].name << ": " << calculateDamage(weapons[index], strength, dexterity) << "\n";
    }

    return 0;
}