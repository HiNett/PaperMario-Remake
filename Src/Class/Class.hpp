#ifndef CLASS_HPP
#define CLASS_HPP

#include <SFML/Graphics.hpp>

using namespace std;

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

// Main class for all characters
class Character {
    protected:
        // Type of Movements
        float moveSpeed;
        bool movingLeft;
        bool movingRight;
        bool movingUp;
        bool movingDown;
        bool lookingLeft;
        bool lookingRight;
        // Animation
        int currentFrame;
        sf::Clock animationClock;
        float animationSpeed = 0.5f;
        float gravity = 20.0f;

    public:
        // Methods
        void loadTexture();
        void setPosition(float x, float y);
        void update();
        void draw(sf::RenderWindow& window);
        // Variable / Constant
        string name;
        string text;
        int lifePoint;
        int power;
        int defense;
        float yPosition;
        float xPosition;
};

// To create all NPC (allies like ennemies)
class NPC : public Character {
    protected:
        bool aggressive;
        int attributionExperiencePoint;
        bool jumpDenied;
        bool hammerDenied;

    public:
        // int setDamage
        // 
};

// Mario Class
class Mario : public Character {
    private:
        sf::Texture marioTexture;
        sf::Sprite marioLeftFeetSprite;
        sf::Sprite marioRightFeetSprite;
        sf::Sprite marioBodySprite;
        sf::Sprite marioLeftArmSprite;
        sf::Sprite marioRightArmSprite;
        sf::Sprite marioLeftHandSprite;
        sf::Sprite marioRightHandSprite;
        sf::Sprite marioHeadSprite;

        sf::IntRect marioLeftFeetFrames[3];
        sf::IntRect marioRightFeetFrames[3];
        sf::IntRect marioBody;
        sf::IntRect marioLeftArm;
        sf::IntRect marioRightArm;
        sf::IntRect marioLeftHand;
        sf::IntRect marioRightHand;
        sf::IntRect marioHead;

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
        Item inventory;

    public:
        Mario();
        void handleInput(sf::Event& event);
        void loadTexture();
        void setPosition(float x, float y);
        void update();
        void draw(sf::RenderWindow& window);
};

// Class to create HammerBros character
class HammerBros : public NPC {
    
    private:
        sf::Texture hammerBrosTexture;
        sf::Sprite hammerBrosSprite;
        sf::IntRect hammerBrosBody;
    
    public:
        HammerBros();
        void loadTexture();
        void setPosition(float x, float y);
        void handleInput(sf::Event& event);
        void update();
        void draw(sf::RenderWindow& window);
        float xPosition;
        float yPosition;
};

#endif
