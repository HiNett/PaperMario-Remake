#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include "../json/json.h"

class Character {
protected:
    // Attributes
    sf::Texture texture;
    sf::Sprite sprite;
    float moveSpeed;
    bool movingLeft;
    bool movingRight;
    bool movingUp;
    bool movingDown;
    bool lookingLeft;
    bool lookingRight;
    int currentFrame;
    sf::Clock animationClock;
    float animationSpeed;
    float gravity;

public:
    // Constructor
    Character(){};

    // Methods
    void loadTexture(const std::string& texturePath);
    virtual void setPosition(float x, float y) = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow& window) const = 0;
};

// NPC class
class NPC : public Character {
protected:
    bool aggressive;
    int lifePoint;
    int power;
    int defense;
    bool jumpDenied;
    bool hammerDenied;
    int attributionExperiencePoint;

public:
    // Constructor
    NPC(const std::string& name, const std::string& jsonFilename);

    // Methods
    void setPosition(float x, float y) override;
    void update() override;
    void draw(sf::RenderWindow& window) const override;
};

class Mario : public Character {
private:
    
    sf::Sprite leftFeetSprite;
    sf::Sprite rightFeetSprite;
    sf::Sprite bodySprite;
    sf::Sprite leftArmSprite;
    sf::Sprite rightArmSprite;
    sf::Sprite leftHandSprite;
    sf::Sprite rightHandSprite;
    sf::Sprite headSprite;

    sf::IntRect leftFeetRect[3];
    sf::IntRect rightFeetRect[3];

    // Setup Values
    bool jump;
    float jumpMaxHeight = 300.0f;
    float originalXPosition;
    float originalYPosition;

    // Personal Values
    int experiencePoint;
    int level;
    int flowerPoint;
    int badgePoint;
    int kamas;
    // vector<Item> inventory;
    float xPosition;
    float yPosition;
public:
    // Constructor
    Mario(const std::string& name, const std::string& jsonFilename);

    // Visual
    void setPosition(float x, float y) override;
    void update() override;
    void draw(sf::RenderWindow& window) const override;
    
    // Controls
    void handleInput(sf::Event& event);
    
    // Mario's inventory methods
    void addItemToInventory() {};
    void deleteItemToInventory() {};
    void useItem() {};
};
#endif
