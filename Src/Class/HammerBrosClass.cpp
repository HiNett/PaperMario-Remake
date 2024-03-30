#include "./Class.hpp"

HammerBros::HammerBros() {
    moveSpeed = 10.0f;
    animationSpeed = 0.5f;
    xPosition = 100;
    yPosition;

    if (!texture.loadFromFile("../Assets/Sprites/HammerBros.png")) {
        return;
    }
    intRect = sf::IntRect(649, 3, 149, 172);
    loadTexture();
}

void HammerBros::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void HammerBros::loadTexture() {
    sprite.setTexture(texture);
    sprite.setTextureRect(intRect); 
}

void HammerBros::update() {
}

void HammerBros::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void HammerBros::handleInput(sf::Event& event) {
}