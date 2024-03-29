#include "./Class/HammerBros.h"

HammerBrosSprite::HammerBrosSprite() {
    moveSpeed = 10.0f;
    currentLeftFeetFrame = 0;
    currentRightFeetFrame = 0;
    animationSpeed = 0.5f;
    xPosition = 100;
    yPosition;

    if (!hammerBrosTexture.loadFromFile("../Assets/Sprites/HammerBros.png")) {
        return;
    }

    hammerBrosBody = sf::IntRect(649, 3, 149, 172);
    loadTexture();
}

void HammerBrosSprite::setPosition(float x, float y) {

    hammerBrosSprite.setPosition(x, y);
    

}

void HammerBrosSprite::loadTexture() {

    hammerBrosSprite.setTexture(hammerBrosTexture);
    hammerBrosSprite.setTextureRect(hammerBrosBody); 
}

void HammerBrosSprite::update() {
    
}

void HammerBrosSprite::draw(sf::RenderWindow& window) {
    // Draw all the parts
    window.draw(hammerBrosSprite);
}

void HammerBrosSprite::handleInput(sf::Event& event) {

}