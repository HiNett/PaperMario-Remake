#include "./Class/MarioSprite.h"

MarioSprite::MarioSprite() {
    moveSpeed = 10.0f;
    currentLeftFeetFrame = 0;
    currentRightFeetFrame = 0;
    animationSpeed = 0.5f;
    xPosition = 100;
    yPosition;

    if (!marioTexture.loadFromFile("../Assets/Sprites/HammerBros.png")) {
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

    if (movingLeft || (movingLeft && movingUp)) {
        marioLeftFeetSprite.setPosition(basePosition.x + 35, basePosition.y + 135);
        marioRightFeetSprite.setPosition(basePosition.x + 10, basePosition.y + 135);
        marioBodySprite.setPosition(basePosition.x + 15, basePosition.y + 85);
        marioLeftArmSprite.setPosition(basePosition.x + 55, basePosition.y + 90);
        marioRightArmSprite.setPosition(basePosition.x + 20, basePosition.y + 227);
        marioLeftHandSprite.setPosition(basePosition.x + 53, basePosition.y + 105);
        marioRightHandSprite.setPosition(basePosition.x + 5, basePosition.y + 110);
        marioHeadSprite.setPosition(basePosition.x - 5, basePosition.y + 5);
    } 
    else if (movingRight || (movingRight && movingUp)){
        marioLeftFeetSprite.setPosition((basePosition.x - 35) + 100, basePosition.y + 135);
        marioRightFeetSprite.setPosition((basePosition.x - 10) + 100, basePosition.y + 135);
        marioBodySprite.setPosition((basePosition.x - 15) + 100, basePosition.y + 85);
        marioLeftArmSprite.setPosition((basePosition.x - 55) + 100, basePosition.y + 90);
        marioRightArmSprite.setPosition((basePosition.x - 20) + 100, basePosition.y + 227);
        marioLeftHandSprite.setPosition((basePosition.x - 53) + 100, basePosition.y + 105);
        marioRightHandSprite.setPosition((basePosition.x - 5) + 100, basePosition.y + 110);
        marioHeadSprite.setPosition((basePosition.x + 5) + 100, basePosition.y + 5);
    }
    else {
        marioLeftFeetSprite.setPosition(basePosition.x + 35, basePosition.y + 135);
        marioRightFeetSprite.setPosition(basePosition.x + 10, basePosition.y + 135);
        marioBodySprite.setPosition(basePosition.x + 15, basePosition.y + 85);
        marioLeftArmSprite.setPosition(basePosition.x + 55, basePosition.y + 90);
        marioRightArmSprite.setPosition(basePosition.x + 20, basePosition.y + 227);
        marioLeftHandSprite.setPosition(basePosition.x + 53, basePosition.y + 105);
        marioRightHandSprite.setPosition(basePosition.x + 5, basePosition.y + 110);
        marioHeadSprite.setPosition(basePosition.x - 5, basePosition.y + 5);
    }
    

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

    // Handle movement
    if (movingLeft || movingRight || movingUp) {
        float xMovement = 0.0f;
        float yMovement = 0.0f;
        if (movingLeft){
            xMovement -= moveSpeed;
        }
        if (movingRight){
            xMovement += moveSpeed;
        }
        if (movingUp){
            yMovement += moveSpeed + 20;
        }

        xPosition += xMovement;
        std::cout << yPosition << std::endl;
        yPosition -= yMovement;
        std::cout << yPosition << std::endl;
        setPosition(xPosition, yPosition);
        marioLeftFeetSprite.move(xMovement, yMovement);
        marioRightFeetSprite.move(xMovement, yMovement);
        marioBodySprite.move(xMovement, yMovement);
        marioLeftArmSprite.move(xMovement, yMovement);
        marioRightArmSprite.move(xMovement, yMovement);
        marioLeftHandSprite.move(xMovement, yMovement);
        marioRightHandSprite.move(xMovement, yMovement);
        marioHeadSprite.move(xMovement, yMovement);
        }

    if (!jump && yPosition < 425) {
        yPosition += 25.0f;
        setPosition(xPosition, yPosition);
        std::cout << yPosition << std::endl;
        if (yPosition == 425){
            std::cout <<"jump :" << jump << std::endl;
            jump = true;
            std::cout <<"jump :" << jump << std::endl;
        }
    }
    // else if (yPosition < 425)
        
    if (movingRight) {
        marioLeftFeetSprite.setScale(-1.0f, 1.0f);
        marioRightFeetSprite.setScale(-1.0f, 1.0f);
        marioBodySprite.setScale(-1.0f, 1.0f);
        marioLeftArmSprite.setScale(-1.0f, 1.0f);
        marioRightArmSprite.setScale(-1.0f, 1.0f);
        marioLeftHandSprite.setScale(-1.0f, 1.0f);
        marioRightHandSprite.setScale(-1.0f, 1.0f);
        marioHeadSprite.setScale(-1.0f, 1.0f);
    }
    if (movingLeft) {
        marioLeftFeetSprite.setScale(1.0f, 1.0f);
        marioRightFeetSprite.setScale(1.0f, 1.0f);
        marioBodySprite.setScale(1.0f, 1.0f);
        marioLeftArmSprite.setScale(1.0f, 1.0f);
        marioRightArmSprite.setScale(1.0f, 1.0f);
        marioLeftHandSprite.setScale(1.0f, 1.0f);
        marioRightHandSprite.setScale(1.0f, 1.0f);
        marioHeadSprite.setScale(1.0f, 1.0f);
    }


    if ((movingLeft || movingRight) && animationClock.getElapsedTime().asSeconds() > animationSpeed) {
        currentLeftFeetFrame = (currentLeftFeetFrame + 1) % 3;
        currentRightFeetFrame = (currentRightFeetFrame + 1) % 3;
        marioLeftFeetSprite.setTextureRect(marioLeftFeetFrames[currentLeftFeetFrame]);
        marioRightFeetSprite.setTextureRect(marioRightFeetFrames[currentRightFeetFrame]);
        animationClock.restart();
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
        if (event.key.code == sf::Keyboard::Left) {
            movingLeft = true;            
            movingRight = false;
        }
        if (event.key.code == sf::Keyboard::Right) {
            movingRight = true;
            movingLeft = false;
        }
        if (event.key.code == sf::Keyboard::Space) {
            movingUp = true;
            jump = false;
        }
        // Handle other movement input here
    } else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Left){
            movingLeft = false;
            movingRight = false;
        }
        else if (event.key.code == sf::Keyboard::Right){
            movingRight = false;
            movingLeft = false;
        }
        else if (event.key.code == sf::Keyboard::Space){
            movingUp = false;
        }
        

        // Handle other movement release here
    }
}