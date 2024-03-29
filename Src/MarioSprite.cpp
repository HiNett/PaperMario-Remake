#include "./Class/MarioSprite.h"

MarioSprite::MarioSprite() {
    movingLeft = false;
    movingRight = false;
    moveSpeed = 1.0f;
    currentLeftFeetFrame = 0;
    currentRightFeetFrame = 0;
    animationSpeed = 0.1f;

    if (!marioTexture.loadFromFile("../Assets/Sprites/MarioSprites.png")) {
        return;
    }

    marioLeftFeetFrames[0] = sf::IntRect(1070, 1918, 42, 31);
    marioLeftFeetFrames[1] = sf::IntRect(1070, 2021, 44, 31);
    marioLeftFeetFrames[2] = sf::IntRect(1070, 2065, 43, 31);

    marioRightFeetFrames[0] = sf::IntRect(1070, 1918, 42, 31);
    marioRightFeetFrames[1] = sf::IntRect(1070, 2021, 44, 31);
    marioRightFeetFrames[2] = sf::IntRect(1070, 2065, 43, 31);

    marioBody = sf::IntRect(1079, 1834, 57, 59);
    marioLeftArm = sf::IntRect(1666, 1588, 29, 51);
    marioRightArm = sf::IntRect(0, 0, 0, 0); 
    marioLeftHand = sf::IntRect(1564, 1918, 39, 39);
    marioRightHand = sf::IntRect(1209, 2206, 40, 41);
    marioHead = sf::IntRect(1067, 1507, 101, 92);
    loadTexture();
}

void MarioSprite::setPosition(float x, float y) {

    sf::Vector2f basePosition(x, y);

    marioLeftFeetSprite.setPosition(basePosition.x + 35, basePosition.y + 135);
    marioRightFeetSprite.setPosition(basePosition.x + 10, basePosition.y + 135);
    marioBodySprite.setPosition(basePosition.x + 15, basePosition.y + 85);
    marioLeftArmSprite.setPosition(basePosition.x + 55, basePosition.y + 90);
    marioRightArmSprite.setPosition(basePosition.x + 20, basePosition.y + 227);
    marioLeftHandSprite.setPosition(basePosition.x + 53, basePosition.y + 105);
    marioRightHandSprite.setPosition(basePosition.x + 5, basePosition.y + 110);
    marioHeadSprite.setPosition(basePosition.x - 5, basePosition.y + 5);
}

void MarioSprite::loadTexture() {

    marioLeftFeetSprite.setTexture(marioTexture);
    marioLeftFeetSprite.setTextureRect(marioLeftFeetFrames[0]); 
    marioRightFeetSprite.setTexture(marioTexture);
    marioRightFeetSprite.setTextureRect(marioRightFeetFrames[0]); 
    marioBodySprite.setTexture(marioTexture);
    marioBodySprite.setTextureRect(marioBody);
    marioLeftArmSprite.setTexture(marioTexture);
    marioLeftArmSprite.setTextureRect(marioLeftArm);
    marioRightArmSprite.setTexture(marioTexture);
    marioRightArmSprite.setTextureRect(marioRightArm);
    marioLeftHandSprite.setTexture(marioTexture);
    marioLeftHandSprite.setTextureRect(marioLeftHand);
    marioRightHandSprite.setTexture(marioTexture);
    marioRightHandSprite.setTextureRect(marioRightHand);
    marioHeadSprite.setTexture(marioTexture);
    marioHeadSprite.setTextureRect(marioHead);
}

void MarioSprite::update() {
    if (animationClock.getElapsedTime().asSeconds() > animationSpeed) {
        currentLeftFeetFrame = (currentLeftFeetFrame + 1) % 3;
        currentRightFeetFrame = (currentRightFeetFrame + 1) % 3;
        marioLeftFeetSprite.setTextureRect(marioLeftFeetFrames[currentLeftFeetFrame]);
        marioRightFeetSprite.setTextureRect(marioRightFeetFrames[currentRightFeetFrame]);
        animationClock.restart();
    }

    // Handle movement
    if (movingLeft || movingRight) {
        float xMovement = 0.0f;
        if (movingLeft)
            xMovement -= moveSpeed;
        if (movingRight)
            xMovement += moveSpeed;

        // Update all parts' positions for left/right movement
        marioLeftFeetSprite.move(xMovement, 0);
        marioRightFeetSprite.move(xMovement, 0);
        marioBodySprite.move(xMovement, 0);
        marioLeftArmSprite.move(xMovement, 0);
        marioRightArmSprite.move(xMovement, 0);
        marioLeftHandSprite.move(xMovement, 0);
        marioRightHandSprite.move(xMovement, 0);
        marioHeadSprite.move(xMovement, 0);
    }
}

void MarioSprite::draw(sf::RenderWindow& window) {
    // Draw all the parts
    window.draw(marioRightArmSprite);
    window.draw(marioRightHandSprite);
    window.draw(marioRightFeetSprite);
    window.draw(marioBodySprite);
    window.draw(marioLeftFeetSprite);
    window.draw(marioLeftArmSprite);
    window.draw(marioLeftHandSprite);
    window.draw(marioHeadSprite);
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