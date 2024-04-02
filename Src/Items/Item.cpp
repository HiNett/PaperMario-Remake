#include "Item.hpp"

Item::Item() {
    // Load texture from file
    if (!texture.loadFromFile("./Sprites/NormalItems.png")) {
        // Handle error
    }
    sprite.setTexture(texture);

    mushroomRect = sf::IntRect(200, 200, 40, 40);
    superMushroomRect = sf::IntRect(8, 344, 40, 40);
    sirupRect = sf::IntRect(152, 104, 40, 40);
    superSirupRect = sf::IntRect(56, 200, 40, 40);
}

void Item::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void Item::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

// Create multiple instances of Item


// Initialize the items
void initializeItems() {

    Item Mushroom;
    Mushroom.id = 0;
    Mushroom.kamas = 5;
    Mushroom.description = "good but moist";
    Mushroom.lifePoint = 5;
    Mushroom.flowerPoint = 0;
    Mushroom.useInCombatOnly = false;

    Item SuperMushroom;
    SuperMushroom.id = 1;
    SuperMushroom.kamas = 10;
    SuperMushroom.description = "super good but moist";
    SuperMushroom.lifePoint = 10;
    SuperMushroom.flowerPoint = 0;
    SuperMushroom.useInCombatOnly = false;

    Item Sirup;
    Sirup.id = 2;
    Sirup.kamas = 5;
    Sirup.description = "tasty";
    Sirup.lifePoint = 0;
    Sirup.flowerPoint = 5;
    Sirup.useInCombatOnly = false;

    Item SuperSirup;
    SuperSirup.id = 3;
    SuperSirup.kamas = 10;
    SuperSirup.description = "super tasty";
    SuperSirup.lifePoint = 0;
    SuperSirup.flowerPoint = 10;
    SuperSirup.useInCombatOnly = false;

}
