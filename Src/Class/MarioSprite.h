#ifndef MARIO_SPRITE_H
#define MARIO_SPRITE_H

#include <SFML/Graphics.hpp>

class MarioSprite {
private:
    sf::Sprite leftFeetSprite;
    sf::Sprite rightFeetSprite;
    sf::Sprite bodySprite;
    sf::Sprite leftArmSprite;
    sf::Sprite rightArmSprite;
    sf::Sprite leftHandSprite;
    sf::Sprite rightHandSprite;
    sf::Sprite headSprite;

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
    MarioSprite(); // Ajout d'un constructeur sans argument
    void loadTexture(const sf::Texture& texture);
    void setPosition(float x, float y);
    void handleInput(sf::Event& event);
    void update();
    void draw(sf::RenderWindow& window);
};

#endif
