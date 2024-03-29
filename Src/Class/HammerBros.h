#ifndef HAMMER_BROS_SPRITE
#define HAMMER_BROS_SPRITE

#include <SFML/Graphics.hpp>

class HammerBrosSprite {
private:
    sf::Texture hammerBrosTexture;
    sf::Sprite hammerBrosSprite;

    sf::IntRect hammerBrosBody;

    float moveSpeed = 1.0f;
    bool movingLeft = false;
    bool movingRight = false;
    int currentLeftFeetFrame = 0;
    int currentRightFeetFrame = 0;
    sf::Clock animationClock;
    float animationSpeed;
    

public:
    HammerBrosSprite();
    void loadTexture();
    void setPosition(float x, float y);
    void handleInput(sf::Event& event);
    void update();
    void draw(sf::RenderWindow& window);
    float xPosition;
    float yPosition;
};

#endif
