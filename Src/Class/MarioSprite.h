#ifndef MARIO_SPRITE_H
#define MARIO_SPRITE_H

#include <SFML/Graphics.hpp>

class MarioSprite {
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

    float moveSpeed = 10.0f;
    bool movingLeft = false;
    bool movingRight = false;
    bool movingUp;
    bool movingDown;
    bool lookingLeft;
    bool lookingRight;
    int currentLeftFeetFrame;
    int currentRightFeetFrame;
    sf::Clock animationClock;
    float animationSpeed = 0.5f;
    bool jump;
    float jumpMaxHeight = 300.0f;
    float gravity = 20.0f;
    float originalXPosition;
    float originalYPosition;
    
public:
    MarioSprite();
    void loadTexture();
    void setPosition(float x, float y);
    void handleInput(sf::Event& event);
    void update();
    void draw(sf::RenderWindow& window);
    float xPosition;
    float yPosition;
};

#endif
