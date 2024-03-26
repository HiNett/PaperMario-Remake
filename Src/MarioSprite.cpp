#include "./Class/MarioSprite.h"

MarioSprite::MarioSprite() {
    movingLeft = false;
    movingRight = false;
    moveSpeed = 1.0f;
    currentLeftFeetFrame = 0;
    currentRightFeetFrame = 0;
    animationSpeed = 0.1f;

    // Define rectangles for each part of Mario
    sf::IntRect marioLeftFeetFrames[3] = {
        sf::IntRect(1070, 1918, 42, 31),  // First frame of left feet animation
        sf::IntRect(1070, 2021, 44, 31),  // Second frame of left feet animation
        sf::IntRect(1070, 2065, 43, 31)   // Third frame of left feet animation
    };
    sf::IntRect marioRightFeetFrames[3] = {
        sf::IntRect(1070, 1918, 42, 31),  // First frame of right feet animation
        sf::IntRect(1070, 2021, 44, 31),  // Second frame of right feet animation
        sf::IntRect(1070, 2065, 43, 31)   // Third frame of right feet animation
    };
    sf::IntRect marioBody(1079, 1834, 57, 59);
    sf::IntRect marioLeftArm(1666, 1588, 29, 51);
    sf::IntRect marioRightArm(0, 0, 0, 0);
    sf::IntRect marioLeftHand(1564, 1918, 39, 39);
    sf::IntRect marioRightHand(1209, 2206, 40, 41);
    sf::IntRect marioHead(1067, 1507, 101, 92);
    // Assign values to the rectangles here
}

void MarioSprite::setPosition(float x, float y) {
        // Define the base position of the character
    sf::Vector2f basePosition(x, y);

    // Adjust positions of the character's parts relative to the base position
    leftFeetSprite.setPosition(basePosition.x + 35, basePosition.y + 135);
    rightFeetSprite.setPosition(basePosition.x + 10, basePosition.y + 135);
    bodySprite.setPosition(basePosition.x + 15, basePosition.y + 85);
    leftArmSprite.setPosition(basePosition.x + 55, basePosition.y + 90);
    rightArmSprite.setPosition(basePosition.x + 20, basePosition.y + 227);
    leftHandSprite.setPosition(basePosition.x + 53, basePosition.y + 105);
    rightHandSprite.setPosition(basePosition.x + 5, basePosition.y + 110);
    headSprite.setPosition(basePosition.x - 5, basePosition.y + 5);
}

void MarioSprite::loadTexture(const sf::Texture& texture) {

    // Assigner la texture à chaque sprite
    leftFeetSprite.setTexture(texture);
    rightFeetSprite.setTexture(texture);
    bodySprite.setTexture(texture);
    leftArmSprite.setTexture(texture);
    rightArmSprite.setTexture(texture);
    leftHandSprite.setTexture(texture);
    rightHandSprite.setTexture(texture);
    headSprite.setTexture(texture);
}

void MarioSprite::handleInput(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left)
            movingLeft = true;
        else if (event.key.code == sf::Keyboard::Right)
            movingRight = true;
        // Handle other movement input here
    } else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Left)
            movingLeft = false;
        else if (event.key.code == sf::Keyboard::Right)
            movingRight = false;
        // Handle other movement release here
    }
}

void MarioSprite::update() {
    if (movingLeft || movingRight) {
        float xMovement = 0.0f;
        if (movingLeft)
            xMovement -= moveSpeed;
        if (movingRight)
            xMovement += moveSpeed;

        // Update all parts' positions for left/right movement
        leftFeetSprite.move(xMovement, 0);
        rightFeetSprite.move(xMovement, 0);
        bodySprite.move(xMovement, 0);
        leftArmSprite.move(xMovement, 0);
        rightArmSprite.move(xMovement, 0);
        leftHandSprite.move(xMovement, 0);
        rightHandSprite.move(xMovement, 0);
        headSprite.move(xMovement, 0);
    }

    // Update animation frames
    if (animationClock.getElapsedTime().asSeconds() > animationSpeed) {
        currentLeftFeetFrame = (currentLeftFeetFrame + 1) % 3;
        currentRightFeetFrame = (currentRightFeetFrame + 1) % 3;
        leftFeetSprite.setTextureRect(marioLeftFeetFrames[currentLeftFeetFrame]);
        rightFeetSprite.setTextureRect(marioRightFeetFrames[currentRightFeetFrame]);
        animationClock.restart();
    }
}

void MarioSprite::draw(sf::RenderWindow& window) {
    // Draw all the parts
    window.draw(rightArmSprite);
    window.draw(rightHandSprite);
    window.draw(rightFeetSprite);
    window.draw(bodySprite);
    window.draw(leftFeetSprite);
    window.draw(leftArmSprite);
    window.draw(leftHandSprite);
    window.draw(headSprite);
}
