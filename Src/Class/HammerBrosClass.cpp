#include "./Class.hpp"

HammerBros::HammerBros() {
    moveSpeed = 10.0f;
    animationSpeed = 0.5f;
    xPosition = 100;
    yPosition;

    if (!hammerBrosTexture.loadFromFile("../Assets/Sprites/HammerBros.png")) {
        return;
    }

    hammerBrosBody = sf::IntRect(649, 3, 149, 172);
    loadTexture();
}

void HammerBros::setPosition(float x, float y) {

    hammerBrosSprite.setPosition(x, y);
    

}

void HammerBros::loadTexture() {

    hammerBrosSprite.setTexture(hammerBrosTexture);
    hammerBrosSprite.setTextureRect(hammerBrosBody); 
}

void HammerBros::update() {
    
}

void HammerBros::draw(sf::RenderWindow& window) {
    // Draw all the parts
    window.draw(hammerBrosSprite);
}

void HammerBros::handleInput(sf::Event& event) {

}