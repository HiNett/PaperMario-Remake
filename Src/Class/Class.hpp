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

        sf::Texture texture;
        sf::Sprite sprite;
        sf::IntRect intRect;

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
        sf::Sprite LeftFeetSprite;
        sf::Sprite RightFeetSprite;
        sf::Sprite BodySprite;
        sf::Sprite LeftArmSprite;
        sf::Sprite RightArmSprite;
        sf::Sprite LeftHandSprite;
        sf::Sprite RightHandSprite;
        sf::Sprite HeadSprite;

        sf::IntRect LeftFeetFrames[3];
        sf::IntRect RightFeetFrames[3];
        sf::IntRect Body;
        sf::IntRect LeftArm;
        sf::IntRect RightArm;
        sf::IntRect LeftHand;
        sf::IntRect RightHand;
        sf::IntRect Head;

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
