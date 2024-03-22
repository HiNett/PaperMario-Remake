#include <iostream>
#include <string>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

class Character {
private:
    sf::Sprite sprite;

public:
    string name;
    string text;
    int lifePoint;
    int power;
    int defense;
    float yPosition;
    float xPosition;

    // Constructor with a texture parameter
    Character(sf::Texture& texture) {
        sprite.setTexture(texture);
    }
};

class Item {
public:
    int id;
    string name[32];
    int kamas;
    string description[128];
    bool useInCombatOnly;
    int lifePoint;
    int flowerPoint;
    // Use the item
    // Throw the item
};

class Mario : public Character {
private:
    int experiencePoint;
    int level;
    int flowerPoint;
    int badgePoint;
    int kamas;
    Item inventory;
    bool jump;

public:
    // Constructor with a texture parameter
    Mario(sf::Texture& texture) : Character(texture) {}

    // Get exp
    // Lose lifePoint
    // Lose flowerPoint
    int readcontrols(Mario Mario) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            Mario.xPosition = Mario.xPosition - 5;
            return Mario.xPosition;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            Mario.xPosition = Mario.xPosition + 5;
            return Mario.xPosition;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            Mario.yPosition = Mario.yPosition + 20;
            return Mario.yPosition;
        }
    }
};

class NPC : public Character {
private:
    bool aggressive;
    int attributionExperiencePoint;
    bool jumpDenied;
    bool hammerDenied;

public:
    // int setDamage
    // 
};