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

    float moveSpeed = 1.0f;
    bool movingLeft = false;
    bool movingRight = false;
    bool movingUp = false;
    bool movingDown = false;
    int currentLeftFeetFrame = 0;
    int currentRightFeetFrame = 0;
    sf::Clock animationClock;
    float animationSpeed;
    

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
